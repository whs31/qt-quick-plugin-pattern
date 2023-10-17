//
// Created by whs31 on 17.10.2023.
//

#pragma once

#include <QtQml/QQmlExtensionPlugin>

class QQPPlugin : public QQmlExtensionPlugin
{
  Q_OBJECT
  Q_PLUGIN_METADATA(IID "whs31.qt.quickpatternplugin/1.0")

  public:
    void registerTypes(const char* uri) override;
};

