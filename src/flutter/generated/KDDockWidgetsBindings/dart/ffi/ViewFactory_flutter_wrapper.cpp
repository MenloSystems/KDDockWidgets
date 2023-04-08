/*
  This file is part of KDDockWidgets.

  SPDX-FileCopyrightText: 2019-2023 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
  Author: Sérgio Martins <sergio.martins@kdab.com>

  SPDX-License-Identifier: GPL-2.0-only OR GPL-3.0-only

  Contact KDAB at <info@kdab.com> for commercial licensing options.
*/
#include "ViewFactory_flutter_wrapper.h"


#include <QDebug>


namespace Dartagnan {

typedef int (*CleanupCallback)(void *thisPtr);
static CleanupCallback s_cleanupCallback = nullptr;

template<typename T>
struct ValueWrapper
{
    T value;
};

}
namespace KDDockWidgetsBindings_wrappersNS {
ViewFactory_flutter_wrapper::ViewFactory_flutter_wrapper()
    : ::KDDockWidgets::ViewFactory_flutter()
{
}
KDDockWidgets::Views::ClassicIndicatorWindowViewInterface *ViewFactory_flutter_wrapper::createClassicIndicatorWindow(KDDockWidgets::Core::ClassicIndicators *arg__1) const
{
    if (m_createClassicIndicatorWindowCallback) {
        const void *thisPtr = this;
        return m_createClassicIndicatorWindowCallback(const_cast<void *>(thisPtr), arg__1);
    } else {
        return ::KDDockWidgets::ViewFactory_flutter::createClassicIndicatorWindow(arg__1);
    }
}
KDDockWidgets::Views::ClassicIndicatorWindowViewInterface *ViewFactory_flutter_wrapper::createClassicIndicatorWindow_nocallback(KDDockWidgets::Core::ClassicIndicators *arg__1) const
{
    return ::KDDockWidgets::ViewFactory_flutter::createClassicIndicatorWindow(arg__1);
}
KDDockWidgets::View *ViewFactory_flutter_wrapper::createDockWidget(const QString &uniqueName, QFlags<KDDockWidgets::DockWidgetOption> arg__2, QFlags<KDDockWidgets::LayoutSaverOption> arg__3, Qt::WindowFlags arg__4) const
{
    if (m_createDockWidgetCallback) {
        const void *thisPtr = this;
        return m_createDockWidgetCallback(const_cast<void *>(thisPtr), uniqueName, arg__2, arg__3, arg__4);
    } else {
        return ::KDDockWidgets::ViewFactory_flutter::createDockWidget(uniqueName, arg__2, arg__3, arg__4);
    }
}
KDDockWidgets::View *ViewFactory_flutter_wrapper::createDockWidget_nocallback(const QString &uniqueName, QFlags<KDDockWidgets::DockWidgetOption> arg__2, QFlags<KDDockWidgets::LayoutSaverOption> arg__3, Qt::WindowFlags arg__4) const
{
    return ::KDDockWidgets::ViewFactory_flutter::createDockWidget(uniqueName, arg__2, arg__3, arg__4);
}
KDDockWidgets::View *ViewFactory_flutter_wrapper::createDropArea(KDDockWidgets::Core::DropArea *arg__1, KDDockWidgets::View *parent) const
{
    if (m_createDropAreaCallback) {
        const void *thisPtr = this;
        return m_createDropAreaCallback(const_cast<void *>(thisPtr), arg__1, parent);
    } else {
        return ::KDDockWidgets::ViewFactory_flutter::createDropArea(arg__1, parent);
    }
}
KDDockWidgets::View *ViewFactory_flutter_wrapper::createDropArea_nocallback(KDDockWidgets::Core::DropArea *arg__1, KDDockWidgets::View *parent) const
{
    return ::KDDockWidgets::ViewFactory_flutter::createDropArea(arg__1, parent);
}
KDDockWidgets::View *ViewFactory_flutter_wrapper::createFloatingWindow(KDDockWidgets::Core::FloatingWindow *arg__1, KDDockWidgets::Core::MainWindow *parent, Qt::WindowFlags windowFlags) const
{
    if (m_createFloatingWindowCallback) {
        const void *thisPtr = this;
        return m_createFloatingWindowCallback(const_cast<void *>(thisPtr), arg__1, parent, windowFlags);
    } else {
        return ::KDDockWidgets::ViewFactory_flutter::createFloatingWindow(arg__1, parent, windowFlags);
    }
}
KDDockWidgets::View *ViewFactory_flutter_wrapper::createFloatingWindow_nocallback(KDDockWidgets::Core::FloatingWindow *arg__1, KDDockWidgets::Core::MainWindow *parent, Qt::WindowFlags windowFlags) const
{
    return ::KDDockWidgets::ViewFactory_flutter::createFloatingWindow(arg__1, parent, windowFlags);
}
KDDockWidgets::View *ViewFactory_flutter_wrapper::createGroup(KDDockWidgets::Core::Group *arg__1, KDDockWidgets::View *parent) const
{
    if (m_createGroupCallback) {
        const void *thisPtr = this;
        return m_createGroupCallback(const_cast<void *>(thisPtr), arg__1, parent);
    } else {
        return ::KDDockWidgets::ViewFactory_flutter::createGroup(arg__1, parent);
    }
}
KDDockWidgets::View *ViewFactory_flutter_wrapper::createGroup_nocallback(KDDockWidgets::Core::Group *arg__1, KDDockWidgets::View *parent) const
{
    return ::KDDockWidgets::ViewFactory_flutter::createGroup(arg__1, parent);
}
KDDockWidgets::View *ViewFactory_flutter_wrapper::createRubberBand(KDDockWidgets::View *parent) const
{
    if (m_createRubberBandCallback) {
        const void *thisPtr = this;
        return m_createRubberBandCallback(const_cast<void *>(thisPtr), parent);
    } else {
        return ::KDDockWidgets::ViewFactory_flutter::createRubberBand(parent);
    }
}
KDDockWidgets::View *ViewFactory_flutter_wrapper::createRubberBand_nocallback(KDDockWidgets::View *parent) const
{
    return ::KDDockWidgets::ViewFactory_flutter::createRubberBand(parent);
}
KDDockWidgets::View *ViewFactory_flutter_wrapper::createSeparator(KDDockWidgets::Core::Separator *arg__1, KDDockWidgets::View *parent) const
{
    if (m_createSeparatorCallback) {
        const void *thisPtr = this;
        return m_createSeparatorCallback(const_cast<void *>(thisPtr), arg__1, parent);
    } else {
        return ::KDDockWidgets::ViewFactory_flutter::createSeparator(arg__1, parent);
    }
}
KDDockWidgets::View *ViewFactory_flutter_wrapper::createSeparator_nocallback(KDDockWidgets::Core::Separator *arg__1, KDDockWidgets::View *parent) const
{
    return ::KDDockWidgets::ViewFactory_flutter::createSeparator(arg__1, parent);
}
KDDockWidgets::View *ViewFactory_flutter_wrapper::createSideBar(KDDockWidgets::Core::SideBar *arg__1, KDDockWidgets::View *parent) const
{
    if (m_createSideBarCallback) {
        const void *thisPtr = this;
        return m_createSideBarCallback(const_cast<void *>(thisPtr), arg__1, parent);
    } else {
        return ::KDDockWidgets::ViewFactory_flutter::createSideBar(arg__1, parent);
    }
}
KDDockWidgets::View *ViewFactory_flutter_wrapper::createSideBar_nocallback(KDDockWidgets::Core::SideBar *arg__1, KDDockWidgets::View *parent) const
{
    return ::KDDockWidgets::ViewFactory_flutter::createSideBar(arg__1, parent);
}
KDDockWidgets::View *ViewFactory_flutter_wrapper::createStack(KDDockWidgets::Core::Stack *arg__1, KDDockWidgets::View *parent) const
{
    if (m_createStackCallback) {
        const void *thisPtr = this;
        return m_createStackCallback(const_cast<void *>(thisPtr), arg__1, parent);
    } else {
        return ::KDDockWidgets::ViewFactory_flutter::createStack(arg__1, parent);
    }
}
KDDockWidgets::View *ViewFactory_flutter_wrapper::createStack_nocallback(KDDockWidgets::Core::Stack *arg__1, KDDockWidgets::View *parent) const
{
    return ::KDDockWidgets::ViewFactory_flutter::createStack(arg__1, parent);
}
KDDockWidgets::View *ViewFactory_flutter_wrapper::createTabBar(KDDockWidgets::Core::TabBar *tabBar, KDDockWidgets::View *parent) const
{
    if (m_createTabBarCallback) {
        const void *thisPtr = this;
        return m_createTabBarCallback(const_cast<void *>(thisPtr), tabBar, parent);
    } else {
        return ::KDDockWidgets::ViewFactory_flutter::createTabBar(tabBar, parent);
    }
}
KDDockWidgets::View *ViewFactory_flutter_wrapper::createTabBar_nocallback(KDDockWidgets::Core::TabBar *tabBar, KDDockWidgets::View *parent) const
{
    return ::KDDockWidgets::ViewFactory_flutter::createTabBar(tabBar, parent);
}
KDDockWidgets::View *ViewFactory_flutter_wrapper::createTitleBar(KDDockWidgets::Core::TitleBar *arg__1, KDDockWidgets::View *parent) const
{
    if (m_createTitleBarCallback) {
        const void *thisPtr = this;
        return m_createTitleBarCallback(const_cast<void *>(thisPtr), arg__1, parent);
    } else {
        return ::KDDockWidgets::ViewFactory_flutter::createTitleBar(arg__1, parent);
    }
}
KDDockWidgets::View *ViewFactory_flutter_wrapper::createTitleBar_nocallback(KDDockWidgets::Core::TitleBar *arg__1, KDDockWidgets::View *parent) const
{
    return ::KDDockWidgets::ViewFactory_flutter::createTitleBar(arg__1, parent);
}
QString ViewFactory_flutter_wrapper::tr(const char *s, const char *c, int n)
{
    return ::KDDockWidgets::ViewFactory_flutter::tr(s, c, n);
}
ViewFactory_flutter_wrapper::~ViewFactory_flutter_wrapper()
{
}

}
static KDDockWidgets::ViewFactory_flutter *fromPtr(void *ptr)
{
    return reinterpret_cast<KDDockWidgets::ViewFactory_flutter *>(ptr);
}
static KDDockWidgetsBindings_wrappersNS::ViewFactory_flutter_wrapper *fromWrapperPtr(void *ptr)
{
    return reinterpret_cast<KDDockWidgetsBindings_wrappersNS::ViewFactory_flutter_wrapper *>(ptr);
}
extern "C" {
void c_KDDockWidgets__ViewFactory_flutter_Finalizer(void *, void *cppObj, void *)
{
    delete reinterpret_cast<KDDockWidgetsBindings_wrappersNS::ViewFactory_flutter_wrapper *>(cppObj);
}
void *c_KDDockWidgets__ViewFactory_flutter__constructor()
{
    auto ptr = new KDDockWidgetsBindings_wrappersNS::ViewFactory_flutter_wrapper();
    return reinterpret_cast<void *>(ptr);
}
// createClassicIndicatorWindow(KDDockWidgets::Core::ClassicIndicators * arg__1) const
void *c_KDDockWidgets__ViewFactory_flutter__createClassicIndicatorWindow_ClassicIndicators(void *thisObj, void *arg__1_)
{
    auto arg__1 = reinterpret_cast<KDDockWidgets::Core::ClassicIndicators *>(arg__1_);
    return [&] {auto targetPtr = fromPtr(thisObj);auto wrapperPtr = dynamic_cast<KDDockWidgetsBindings_wrappersNS::ViewFactory_flutter_wrapper*>(targetPtr);if (wrapperPtr) {    return wrapperPtr->createClassicIndicatorWindow_nocallback(arg__1);} else {    return targetPtr->createClassicIndicatorWindow(arg__1);} }();
}
// createDockWidget(const QString & uniqueName, QFlags<KDDockWidgets::DockWidgetOption> arg__2, QFlags<KDDockWidgets::LayoutSaverOption> arg__3, Qt::WindowFlags arg__4) const
void *c_KDDockWidgets__ViewFactory_flutter__createDockWidget_QString_DockWidgetOptions_LayoutSaverOptions_WindowFlags(void *thisObj, const char *uniqueName_, int arg__2_, int arg__3_, int arg__4)
{
    const auto uniqueName = QString::fromUtf8(uniqueName_);
    auto arg__2 = static_cast<QFlags<KDDockWidgets::DockWidgetOption>>(arg__2_);
    auto arg__3 = static_cast<QFlags<KDDockWidgets::LayoutSaverOption>>(arg__3_);
    return [&] {auto targetPtr = fromPtr(thisObj);auto wrapperPtr = dynamic_cast<KDDockWidgetsBindings_wrappersNS::ViewFactory_flutter_wrapper*>(targetPtr);if (wrapperPtr) {    return wrapperPtr->createDockWidget_nocallback(uniqueName,arg__2,arg__3,static_cast<Qt::WindowFlags>(arg__4));} else {    return targetPtr->createDockWidget(uniqueName,arg__2,arg__3,static_cast<Qt::WindowFlags>(arg__4));} }();
}
// createDropArea(KDDockWidgets::Core::DropArea * arg__1, KDDockWidgets::View * parent) const
void *c_KDDockWidgets__ViewFactory_flutter__createDropArea_DropArea_View(void *thisObj, void *arg__1_, void *parent_)
{
    auto arg__1 = reinterpret_cast<KDDockWidgets::Core::DropArea *>(arg__1_);
    auto parent = reinterpret_cast<KDDockWidgets::View *>(parent_);
    return [&] {auto targetPtr = fromPtr(thisObj);auto wrapperPtr = dynamic_cast<KDDockWidgetsBindings_wrappersNS::ViewFactory_flutter_wrapper*>(targetPtr);if (wrapperPtr) {    return wrapperPtr->createDropArea_nocallback(arg__1,parent);} else {    return targetPtr->createDropArea(arg__1,parent);} }();
}
// createFloatingWindow(KDDockWidgets::Core::FloatingWindow * arg__1, KDDockWidgets::Core::MainWindow * parent, Qt::WindowFlags windowFlags) const
void *c_KDDockWidgets__ViewFactory_flutter__createFloatingWindow_FloatingWindow_MainWindow_WindowFlags(void *thisObj, void *arg__1_, void *parent_, int windowFlags)
{
    auto arg__1 = reinterpret_cast<KDDockWidgets::Core::FloatingWindow *>(arg__1_);
    auto parent = reinterpret_cast<KDDockWidgets::Core::MainWindow *>(parent_);
    return [&] {auto targetPtr = fromPtr(thisObj);auto wrapperPtr = dynamic_cast<KDDockWidgetsBindings_wrappersNS::ViewFactory_flutter_wrapper*>(targetPtr);if (wrapperPtr) {    return wrapperPtr->createFloatingWindow_nocallback(arg__1,parent,static_cast<Qt::WindowFlags>(windowFlags));} else {    return targetPtr->createFloatingWindow(arg__1,parent,static_cast<Qt::WindowFlags>(windowFlags));} }();
}
// createGroup(KDDockWidgets::Core::Group * arg__1, KDDockWidgets::View * parent) const
void *c_KDDockWidgets__ViewFactory_flutter__createGroup_Group_View(void *thisObj, void *arg__1_, void *parent_)
{
    auto arg__1 = reinterpret_cast<KDDockWidgets::Core::Group *>(arg__1_);
    auto parent = reinterpret_cast<KDDockWidgets::View *>(parent_);
    return [&] {auto targetPtr = fromPtr(thisObj);auto wrapperPtr = dynamic_cast<KDDockWidgetsBindings_wrappersNS::ViewFactory_flutter_wrapper*>(targetPtr);if (wrapperPtr) {    return wrapperPtr->createGroup_nocallback(arg__1,parent);} else {    return targetPtr->createGroup(arg__1,parent);} }();
}
// createRubberBand(KDDockWidgets::View * parent) const
void *c_KDDockWidgets__ViewFactory_flutter__createRubberBand_View(void *thisObj, void *parent_)
{
    auto parent = reinterpret_cast<KDDockWidgets::View *>(parent_);
    return [&] {auto targetPtr = fromPtr(thisObj);auto wrapperPtr = dynamic_cast<KDDockWidgetsBindings_wrappersNS::ViewFactory_flutter_wrapper*>(targetPtr);if (wrapperPtr) {    return wrapperPtr->createRubberBand_nocallback(parent);} else {    return targetPtr->createRubberBand(parent);} }();
}
// createSeparator(KDDockWidgets::Core::Separator * arg__1, KDDockWidgets::View * parent) const
void *c_KDDockWidgets__ViewFactory_flutter__createSeparator_Separator_View(void *thisObj, void *arg__1_, void *parent_)
{
    auto arg__1 = reinterpret_cast<KDDockWidgets::Core::Separator *>(arg__1_);
    auto parent = reinterpret_cast<KDDockWidgets::View *>(parent_);
    return [&] {auto targetPtr = fromPtr(thisObj);auto wrapperPtr = dynamic_cast<KDDockWidgetsBindings_wrappersNS::ViewFactory_flutter_wrapper*>(targetPtr);if (wrapperPtr) {    return wrapperPtr->createSeparator_nocallback(arg__1,parent);} else {    return targetPtr->createSeparator(arg__1,parent);} }();
}
// createSideBar(KDDockWidgets::Core::SideBar * arg__1, KDDockWidgets::View * parent) const
void *c_KDDockWidgets__ViewFactory_flutter__createSideBar_SideBar_View(void *thisObj, void *arg__1_, void *parent_)
{
    auto arg__1 = reinterpret_cast<KDDockWidgets::Core::SideBar *>(arg__1_);
    auto parent = reinterpret_cast<KDDockWidgets::View *>(parent_);
    return [&] {auto targetPtr = fromPtr(thisObj);auto wrapperPtr = dynamic_cast<KDDockWidgetsBindings_wrappersNS::ViewFactory_flutter_wrapper*>(targetPtr);if (wrapperPtr) {    return wrapperPtr->createSideBar_nocallback(arg__1,parent);} else {    return targetPtr->createSideBar(arg__1,parent);} }();
}
// createStack(KDDockWidgets::Core::Stack * arg__1, KDDockWidgets::View * parent) const
void *c_KDDockWidgets__ViewFactory_flutter__createStack_Stack_View(void *thisObj, void *arg__1_, void *parent_)
{
    auto arg__1 = reinterpret_cast<KDDockWidgets::Core::Stack *>(arg__1_);
    auto parent = reinterpret_cast<KDDockWidgets::View *>(parent_);
    return [&] {auto targetPtr = fromPtr(thisObj);auto wrapperPtr = dynamic_cast<KDDockWidgetsBindings_wrappersNS::ViewFactory_flutter_wrapper*>(targetPtr);if (wrapperPtr) {    return wrapperPtr->createStack_nocallback(arg__1,parent);} else {    return targetPtr->createStack(arg__1,parent);} }();
}
// createTabBar(KDDockWidgets::Core::TabBar * tabBar, KDDockWidgets::View * parent) const
void *c_KDDockWidgets__ViewFactory_flutter__createTabBar_TabBar_View(void *thisObj, void *tabBar_, void *parent_)
{
    auto tabBar = reinterpret_cast<KDDockWidgets::Core::TabBar *>(tabBar_);
    auto parent = reinterpret_cast<KDDockWidgets::View *>(parent_);
    return [&] {auto targetPtr = fromPtr(thisObj);auto wrapperPtr = dynamic_cast<KDDockWidgetsBindings_wrappersNS::ViewFactory_flutter_wrapper*>(targetPtr);if (wrapperPtr) {    return wrapperPtr->createTabBar_nocallback(tabBar,parent);} else {    return targetPtr->createTabBar(tabBar,parent);} }();
}
// createTitleBar(KDDockWidgets::Core::TitleBar * arg__1, KDDockWidgets::View * parent) const
void *c_KDDockWidgets__ViewFactory_flutter__createTitleBar_TitleBar_View(void *thisObj, void *arg__1_, void *parent_)
{
    auto arg__1 = reinterpret_cast<KDDockWidgets::Core::TitleBar *>(arg__1_);
    auto parent = reinterpret_cast<KDDockWidgets::View *>(parent_);
    return [&] {auto targetPtr = fromPtr(thisObj);auto wrapperPtr = dynamic_cast<KDDockWidgetsBindings_wrappersNS::ViewFactory_flutter_wrapper*>(targetPtr);if (wrapperPtr) {    return wrapperPtr->createTitleBar_nocallback(arg__1,parent);} else {    return targetPtr->createTitleBar(arg__1,parent);} }();
}
// tr(const char * s, const char * c, int n)
void *c_static_KDDockWidgets__ViewFactory_flutter__tr_char_char_int(const char *s, const char *c, int n)
{
    return new Dartagnan::ValueWrapper<QString> { KDDockWidgetsBindings_wrappersNS::ViewFactory_flutter_wrapper::tr(s, c, n) };
}
void c_KDDockWidgets__ViewFactory_flutter__destructor(void *thisObj)
{
    delete fromPtr(thisObj);
}
void c_KDDockWidgets__ViewFactory_flutter__registerVirtualMethodCallback(void *ptr, void *callback, int methodId)
{
    auto wrapper = fromWrapperPtr(ptr);
    switch (methodId) {
    case 675:
        wrapper->m_createClassicIndicatorWindowCallback = reinterpret_cast<KDDockWidgetsBindings_wrappersNS::ViewFactory_flutter_wrapper::Callback_createClassicIndicatorWindow>(callback);
        break;
    case 676:
        wrapper->m_createDockWidgetCallback = reinterpret_cast<KDDockWidgetsBindings_wrappersNS::ViewFactory_flutter_wrapper::Callback_createDockWidget>(callback);
        break;
    case 677:
        wrapper->m_createDropAreaCallback = reinterpret_cast<KDDockWidgetsBindings_wrappersNS::ViewFactory_flutter_wrapper::Callback_createDropArea>(callback);
        break;
    case 678:
        wrapper->m_createFloatingWindowCallback = reinterpret_cast<KDDockWidgetsBindings_wrappersNS::ViewFactory_flutter_wrapper::Callback_createFloatingWindow>(callback);
        break;
    case 679:
        wrapper->m_createGroupCallback = reinterpret_cast<KDDockWidgetsBindings_wrappersNS::ViewFactory_flutter_wrapper::Callback_createGroup>(callback);
        break;
    case 680:
        wrapper->m_createRubberBandCallback = reinterpret_cast<KDDockWidgetsBindings_wrappersNS::ViewFactory_flutter_wrapper::Callback_createRubberBand>(callback);
        break;
    case 681:
        wrapper->m_createSeparatorCallback = reinterpret_cast<KDDockWidgetsBindings_wrappersNS::ViewFactory_flutter_wrapper::Callback_createSeparator>(callback);
        break;
    case 682:
        wrapper->m_createSideBarCallback = reinterpret_cast<KDDockWidgetsBindings_wrappersNS::ViewFactory_flutter_wrapper::Callback_createSideBar>(callback);
        break;
    case 683:
        wrapper->m_createStackCallback = reinterpret_cast<KDDockWidgetsBindings_wrappersNS::ViewFactory_flutter_wrapper::Callback_createStack>(callback);
        break;
    case 684:
        wrapper->m_createTabBarCallback = reinterpret_cast<KDDockWidgetsBindings_wrappersNS::ViewFactory_flutter_wrapper::Callback_createTabBar>(callback);
        break;
    case 685:
        wrapper->m_createTitleBarCallback = reinterpret_cast<KDDockWidgetsBindings_wrappersNS::ViewFactory_flutter_wrapper::Callback_createTitleBar>(callback);
        break;
    }
}
}
