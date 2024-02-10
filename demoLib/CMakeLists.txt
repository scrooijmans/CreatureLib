cmake_minimum_required(VERSION 3.14)

project(intLib LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

#dynamic
add_library(intLib SHARED
  demoLib_global.h
  demolib.cpp
  demolib.h
)

#static
add_library(intLibStatic STATIC
    demoLib_global.h
    demolib.cpp
    demolib.h
)

set_target_properties(intLib PROPERTIES
    PUBLIC_HEADER "demolib.h;"
)
set_target_properties(intLibStatic PROPERTIES OUTPUT_NAME intLib_s)

# common for both dynamic and static
foreach(lib intLib intLibStatic)
    target_link_libraries(${lib} PRIVATE Qt${QT_VERSION_MAJOR}::Core)
    target_compile_definitions(${lib} PRIVATE INTLIB_LIBRARY)
    install(TARGETS ${lib}
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin
        PUBLIC_HEADER DESTINATION include/intLib
    )
endforeach()

