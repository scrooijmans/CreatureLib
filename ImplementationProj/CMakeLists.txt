cmake_minimum_required(VERSION 3.5)

project(ImplementationProj LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#find Qt
# find_package(QT NAMES Qt6 Qt5 COMPONENTS Core REQUIRED)
# find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core REQUIRED)
find_package(Qt6 COMPONENTS Core REQUIRED)
message(STATUS "Install prefix: ${CMAKE_INSTALL_PREFIX}")

add_executable(ImplementationProj main.cpp)

# Find intLib library
find_library(INTLIB_LIBRARY NAMES intLib intLibStatic #looks for the compile defition.
             # HINTS "/usr/local/lib" "/path/to/custom/lib/location"
)

 # Verify if intLib was found
 if(NOT INTLIB_LIBRARY)
   message(FATAL_ERROR "intLib library not found")
 else()
   # If found, extract the directory and include it
   get_filename_component(INTLIB_INCLUDE_DIR ${INTLIB_LIBRARY} DIRECTORY)
   include_directories(${INTLIB_INCLUDE_DIR}/../include/intLib)
 endif()


include(GNUInstallDirs)
install(TARGETS ImplementationProj
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

target_link_libraries(ImplementationProj PRIVATE
    # Qt${QT_VERSION_MAJOR}::Core
    Qt6::Core
    ${INTLIB_LIBRARY}

)


