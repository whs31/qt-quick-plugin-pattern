cmake_minimum_required(VERSION 3.15)

project(QtQuickPatternPlugin
  VERSION 0.0.1
  DESCRIPTION "Template for Qt5 Quick Plugin"
  HOMEPAGE_URL "io.github.whs31"
  LANGUAGES C CXX
)

find_package(Qt5 REQUIRED COMPONENTS Quick Core Qml)
qt5_add_resources(QQP_RESOURCES resources/qqp-plugin-rc.qrc)

set(QQP_SOURCES
  src/c++/qqpplugin.h
  src/c++/qqpplugin.c++

  ${QQP_RESOURCES}
)

set(CMAKE_AUTOMOC ON)

add_library(${PROJECT_NAME} SHARED
#  ${CMAKE_CURRENT_LIST_DIR}/qmldir
#  ${CMAKE_CURRENT_LIST_DIR}/plugin.qmltypes

  ${QQP_SOURCES}
)


target_link_libraries(${PROJECT_NAME}
  PRIVATE
    Qt5::Core
    Qt5::Quick
    Qt5::Qml
)

add_custom_command(TARGET ${PROJECT_NAME}
  POST_BUILD
  COMMAND
    ${CMAKE_COMMAND} -E copy
    ${CMAKE_CURRENT_LIST_DIR}/qmldir
    $<TARGET_FILE_DIR:${PROJECT_NAME}>/qmldir
)