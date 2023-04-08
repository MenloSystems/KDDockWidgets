/*
  This file is part of KDDockWidgets.

  SPDX-FileCopyrightText: 2019-2023 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
  Author: Sérgio Martins <sergio.martins@kdab.com>

  SPDX-License-Identifier: GPL-2.0-only OR GPL-3.0-only

  Contact KDAB at <info@kdab.com> for commercial licensing options.
*/

#ifndef KD_DRAGCONTROLLER_P_H
#define KD_DRAGCONTROLLER_P_H

#include "kddockwidgets/docks_export.h"

#include "WindowBeingDragged_p.h"
#include "EventFilterInterface.h"

#include <QPoint>
#include <QMimeData>
#include <QTimer>

#include <memory>

namespace KDDockWidgets {

class StateBase;
class StateNone;
class StateInternalMDIDragging;
class Draggable;
class FallbackMouseGrabber;
class MinimalStateMachine;

namespace Core {
class DropArea;
}

class State : public QObject
{
    Q_OBJECT
public:
    explicit State(MinimalStateMachine *parent);
    ~State() override;

    template<typename Obj, typename Signal>
    void addTransition(Obj *, Signal, State *dest);
    bool isCurrentState() const;

    virtual void onEntry() = 0;
    virtual void onExit()
    {
    }

private:
    MinimalStateMachine *const m_machine;
};

class MinimalStateMachine : public QObject
{
    Q_OBJECT
public:
    explicit MinimalStateMachine(QObject *parent = nullptr);

    State *currentState() const;
    void setCurrentState(State *);

Q_SIGNALS:
    void currentStateChanged();

private:
    State *m_currentState = nullptr;
};

class DOCKS_EXPORT DragController : public MinimalStateMachine, public EventFilterInterface
{
    Q_OBJECT
    Q_PROPERTY(bool isDragging READ isDragging NOTIFY isDraggingChanged)
public:
    enum State {
        State_None = 0,
        State_PreDrag,
        State_Dragging
    };
    Q_ENUM(State)

    static DragController *instance();

    // Registers something that wants to be able to be dragged
    void registerDraggable(Draggable *);
    void unregisterDraggable(Draggable *);

    bool isDragging() const;
    bool isInNonClientDrag() const;
    bool isInClientDrag() const;
    bool isIdle() const;

    void grabMouseFor(View *);
    void releaseMouse(View *);

    Core::FloatingWindow *floatingWindowBeingDragged() const;

    /// @brief Returns the current drop area under the mouse
    Core::DropArea *dropAreaUnderCursor() const;

    ///@brief Returns the window being dragged
    WindowBeingDragged *windowBeingDragged() const;

    /// Experimental, internal, not for general use.
    void enableFallbackMouseGrabber();

    // Returns the active state
    StateBase *activeState() const;

    /// Returns the current drop location
    /// The user needs to be dragging a window and be over a drop indicator, otherwise DropLocation_None is returned
    DropLocation currentDropLocation() const;

Q_SIGNALS:
    void mousePressed();
    void manhattanLengthMove();
    void manhattanLengthMoveMDI();
    void mdiPopOut();
    void dragCanceled();
    void dropped();
    void isDraggingChanged();

private:
    friend class StateBase;
    friend class StateNone;
    friend class StatePreDrag;
    friend class StateDragging;
    friend class StateInternalMDIDragging;
    friend class StateDropped;
    friend class StateDraggingWayland;

    DragController(QObject * = nullptr);
    std::shared_ptr<View> qtTopLevelUnderCursor() const;
    Draggable *draggableForView(View *) const;
    bool onDnDEvent(View *, Event *) override;
    bool onMoveEvent(View *) override;
    bool onMouseEvent(View *, MouseEvent *) override;

    QPoint m_pressPos;
    QPoint m_offset;

    QVector<Draggable *> m_draggables;
    Draggable *m_draggable = nullptr;
    ViewGuard m_draggableGuard =
        nullptr; // Just so we know if the draggable was destroyed for some reason
    std::unique_ptr<WindowBeingDragged> m_windowBeingDragged;
    Core::DropArea *m_currentDropArea = nullptr;
    bool m_nonClientDrag = false;
    FallbackMouseGrabber *m_fallbackMouseGrabber = nullptr;
    StateNone *m_stateNone = nullptr;
    StateInternalMDIDragging *m_stateDraggingMDI = nullptr;
};

class StateBase : public State
{
    Q_OBJECT
public:
    explicit StateBase(DragController *parent);
    ~StateBase();

    // Not using QEvent here, to abstract platform differences regarding production of such events
    virtual bool handleMouseButtonPress(Draggable * /*receiver*/, QPoint /*globalPos*/,
                                        QPoint /*pos*/)
    {
        return false;
    }
    virtual bool handleMouseMove(QPoint /*globalPos*/)
    {
        return false;
    }
    virtual bool handleMouseButtonRelease(QPoint /*globalPos*/)
    {
        return false;
    }
    virtual bool handleMouseDoubleClick()
    {
        return false;
    }

    // Only interesting for Wayland
    virtual bool handleDragEnter(DragEnterEvent *, Core::DropArea *)
    {
        return false;
    }
    virtual bool handleDragLeave(Core::DropArea *)
    {
        return false;
    }
    virtual bool handleDragMove(DragMoveEvent *, Core::DropArea *)
    {
        return false;
    }
    virtual bool handleDrop(DropEvent *, Core::DropArea *)
    {
        return false;
    }

    // Returns whether this is the current state
    bool isActiveState() const;

    DragController *const q;
};

class StateNone : public StateBase
{
    Q_OBJECT
public:
    explicit StateNone(DragController *parent);
    ~StateNone() override;
    void onEntry() override;
    bool handleMouseButtonPress(Draggable *draggable, QPoint globalPos, QPoint pos) override;
};

class StatePreDrag : public StateBase
{
    Q_OBJECT
public:
    explicit StatePreDrag(DragController *parent);
    ~StatePreDrag() override;
    void onEntry() override;
    bool handleMouseMove(QPoint globalPos) override;
    bool handleMouseButtonRelease(QPoint) override;
    bool handleMouseDoubleClick() override;
};

// Used on all platforms except Wayland. @see StateDraggingWayland
class StateDragging : public StateBase
{
    Q_OBJECT
public:
    explicit StateDragging(DragController *parent);
    ~StateDragging() override;
    void onEntry() override;
    void onExit() override;
    bool handleMouseButtonRelease(QPoint globalPos) override;
    bool handleMouseMove(QPoint globalPos) override;
    bool handleMouseDoubleClick() override;

private:
    QTimer m_maybeCancelDrag;
};


/// @brief State when we're moving an MDI dock widget around the main window
/// without it becoming floating
class StateInternalMDIDragging : public StateBase
{
    Q_OBJECT
public:
    explicit StateInternalMDIDragging(DragController *parent);
    ~StateInternalMDIDragging() override;
    void onEntry() override;
    bool handleMouseButtonRelease(QPoint globalPos) override;
    bool handleMouseMove(QPoint globalPos) override;
    bool handleMouseDoubleClick() override;
};

// Used on wayland only to use QDrag instead of setting geometry on mouse-move.
class StateDraggingWayland : public StateDragging
{
    Q_OBJECT
public:
    explicit StateDraggingWayland(DragController *parent);
    ~StateDraggingWayland() override;
    void onEntry() override;

    bool handleMouseButtonRelease(QPoint globalPos) override;
    bool handleDragEnter(DragEnterEvent *, Core::DropArea *) override;
    bool handleDragMove(DragMoveEvent *, Core::DropArea *) override;
    bool handleDragLeave(Core::DropArea *) override;
    bool handleDrop(DropEvent *, Core::DropArea *) override;
    bool handleMouseMove(QPoint globalPos) override;
    bool m_inQDrag = false;
};

// A sub-class just so we don't use QMimeData directly. We'll only accept drops if its mime data
// Can be qobject_casted to this class. For safety.
class WaylandMimeData : public QMimeData
{
    Q_OBJECT
public:
};

}

#endif
