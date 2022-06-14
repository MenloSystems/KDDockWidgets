/*
  This file is part of KDDockWidgets.

  SPDX-FileCopyrightText: 2019-2022 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
  Author: Sérgio Martins <sergio.martins@kdab.com>

  SPDX-License-Identifier: GPL-2.0-only OR GPL-3.0-only

  Contact KDAB at <info@kdab.com> for commercial licensing options.
*/

#include "QmlTypes.h"
#include "DockWidgetInstantiator.h"
#include "MainWindowInstantiator.h"
#include "LayoutSaverInstantiator.h"

#include "private/multisplitter/Item_p.h"

#include <QQmlEngine>
#include <QDebug>

void KDDockWidgets::registerQmlTypes()
{
    qmlRegisterType<MainWindowInstantiator>("com.kdab.dockwidgets", 2, 0, "MainWindowLayout");
    qmlRegisterType<DockWidgetInstantiator>("com.kdab.dockwidgets", 2, 0, "DockWidget");
    qmlRegisterType<LayoutSaverInstantiator>("com.kdab.dockwidgets", 2, 0, "LayoutSaver");
    qmlRegisterUncreatableType<Layouting::Item>("com.kdab.kddockwidgets.multisplitter", 2, 0,
                                                "KDMultiSplitter", QStringLiteral("enum access"));

    qmlRegisterUncreatableMetaObject(KDDockWidgets::staticMetaObject, "com.kdab.dockwidgets", 2, 0, "KDDockWidgets", QStringLiteral("Enum access only"));
}
