cmake_minimum_required(VERSION 3.16)

project(Calc3D VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -O2")

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Sql)

qt_add_resources(RESOURCES 
  "view/resources.qrc"
) 

set(MAIN_SOURCES
        main.cpp

        view/main_window.cpp
        view/main_window.h

        view/about_dialog.cpp
        view/formula_dialog.cpp
        view/update_dialog.cpp
        view/printer_settings.cpp
        view/add_printer.cpp
        view/delete_printer.cpp
        view/add_plastic.cpp
        view/delete_plastic.cpp

        view/ui/about.ui
        view/ui/main_window.ui
        view/ui/formula.ui
        view/ui/settings_preset.ui
        view/ui/printer_settings.ui
        view/ui/updates.ui
        view/ui/add_printer.ui
        view/ui/del_printer.ui
        view/ui/add_plastic.ui
        view/ui/del_plastic.ui

        storage/printer_db.cpp
        storage/printer_db.h
        storage/plastic_db.cpp
        storage/plastic_db.h
        storage/setting_preset.cpp
        storage/setting_preset.h

        logic/calculator.cpp
        logic/calculator.h
        logic/facade.cpp
        logic/facade.h
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Calc3D
    MANUAL_FINALIZATION
    ${MAIN_SOURCES}
    ${RESOURCES}
    ../app_icon.rc
)
else()
    add_executable(Calc3D
    ${MAIN_SOURCES}
    ${RESOURCES}
    ../app_icon.rc
)
endif()

target_link_libraries(Calc3D PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Sql)

set_target_properties(Calc3D PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS Calc3D
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Calc3D)
endif()