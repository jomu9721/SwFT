cmake_minimum_required(VERSION 2.8.8 FATAL_ERROR)
project(Clone1)

FIND_PACKAGE(ParaView REQUIRED)
INCLUDE(${PARAVIEW_USE_FILE})
if (NOT PARAVIEW_BUILD_QT_GUI)
  message(FATAL_ERROR
    "Clone1 example requires PARAVIEW_BUILD_QT_GUI to be enabled. "
    "Please rebuild ParaView (or point to a different build of ParaView) "
    "with PARAVIEW_BUILD_QT_GUI set to TRUE")
endif()


# include rules for creating custom applications.
include(ParaViewBranding)

#------------------------------------------------------------------------------
# Add extra library containing custom code for the client.
QT4_WRAP_CPP(MOC_BUILT_SOURCES
  myMainWindow.h)

QT4_WRAP_UI(UI_BUILT_SOURCES
  myMainWindow.ui
)

SOURCE_GROUP("Generated" FILES
  ${MOC_BUILT_SOURCES}
  ${UI_BUILT_SOURCES}
)

SET(ParaView_SOURCE_FILES
  myMainWindow.cxx
  myMainWindow.h
  swftparaviewmenubuilders.cpp
  swftparaviewmenubuilders.h
  swft_controler_ui.h
  pqMainControlsToolbar.cxx
  pqMainControlsToolbar.h
  ${MOC_BUILT_SOURCES}
  ${UI_BUILT_SOURCES})

INCLUDE_DIRECTORIES(
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_BINARY_DIR})

build_paraview_client(SwFT
  TITLE "LASP Space weather Forecast Tools (SwFT)"
  ORGANIZATION  "LASP, CU Boulder"
  VERSION_MAJOR 0
  VERSION_MINOR 1
  VERSION_PATCH 1
  SPLASH_IMAGE "${CMAKE_CURRENT_SOURCE_DIR}/1.png"
  PVMAIN_WINDOW myMainWindow
  PVMAIN_WINDOW_INCLUDE myMainWindow.h
  GUI_CONFIGURATION_XMLS
    ${CMAKE_CURRENT_SOURCE_DIR}/ParaViewSources.xml
    ${CMAKE_CURRENT_SOURCE_DIR}/ParaViewFilters.xml
    ${CMAKE_CURRENT_SOURCE_DIR}/ParaViewReaders.xml
    ${CMAKE_CURRENT_SOURCE_DIR}/ParaViewWriters.xml
  SOURCES ${ParaView_SOURCE_FILES}
)