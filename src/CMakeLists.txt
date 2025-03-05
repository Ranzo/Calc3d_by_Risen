cmake_minimum_required(VERSION 3.5)

project(Calc3D VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -O2")

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Sql)

set(MAIN_SOURCES
        main.cpp

        view/main_window.cpp
        view/main_window.h

        view/about_dialog.cpp
        view/formula_dialog.cpp
        view/update_dialog.cpp
        view/printer_settings.cpp
        view/add_preset.cpp
        view/delete_preset.cpp
        view/edit_preset.cpp

        view/ui/about.ui
        view/ui/main_window.ui
        view/ui/del_preset.ui
        view/ui/edit_preset.ui
        view/ui/formula.ui
        view/ui/settings_preset.ui
        view/ui/printer_settings.ui
        view/ui/updates.ui
        view/ui/add_preset.ui

        logic/printer_db.cpp
        logic/printer_db.h
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Calc3D
    MANUAL_FINALIZATION
    ${MAIN_SOURCES}
)
else()
    add_executable(Calc3D
    ${MAIN_SOURCES}
)
endif()

# qt_add_resources(Calc3D "app_resources"
#   PREFIX "/"
#   FILES
#     view/resources.qrc
# )

target_link_libraries(Calc3D PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Sql)

# путь к бд в проекте, опционально
# configure_file(
#     ${CMAKE_CURRENT_SOURCE_DIR}/printers.db
#     ${CMAKE_CURRENT_BINARY_DIR}/printers.db
#     COPYONLY
# ) 

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