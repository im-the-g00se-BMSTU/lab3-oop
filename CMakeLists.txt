cmake_minimum_required(VERSION 3.16)

project(lab3 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    commands.h
    constants.h
    facade.cpp
    facade.h
    expression_editor.cpp
    expression_editor.h
    expression_calculator.cpp
    expression_calculator.h
    lexeme.h
    lexeme_factory.h
    number_lexeme.cpp
    number_lexeme.h
    math_operator.cpp
    math_operator.h
    binary_operator.h
    unary_operator.h
    paren_lexeme.h
    lexer_exception.h
    math_exception.h
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(lab3
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        res.qrc
    )
else()
    if(ANDROID)
        add_library(lab3 SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(lab3
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(lab3 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

if(${QT_VERSION} VERSION_LESS 6.1.0)
    set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.lab3)
endif()

set_target_properties(lab3 PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS lab3
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(lab3)
endif()
