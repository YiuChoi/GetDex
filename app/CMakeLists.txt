# Sets the minimum version of CMake required to build the native
# library. You should either keep the default value or only pass a
# value of 3.4.0 or lower.

cmake_minimum_required(VERSION 3.4.1)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds it for you.
# Gradle automatically packages shared libraries with your APK.

add_library( # Sets the name of the library.
             DumpDex.cy

             # Sets the library as a shared library.
             SHARED

             # Provides a relative path to your source file(s).
             # Associated headers in the same location as their source
             # file are automatically included.
             src/main/cpp/DumpDex.cy.cpp)

include_directories(src/main/cpp/)

# Searches for a specified prebuilt library and stores the path as a
# variable. Because system libraries are included in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
              log-lib

              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )

add_library( substrate-dvm

             SHARED

             IMPORTED )

set_target_properties( # Specifies the target library.
                       substrate-dvm

                       # Specifies the parameter you want to define.
                       PROPERTIES IMPORTED_LOCATION

                       # Provides the path to the library you want to import.
                       src/main/cpp/libsubstrate-dvm.so)

add_library( substrate

             SHARED

             IMPORTED )

set_target_properties( # Specifies the target library.
                       substrate

                       # Specifies the parameter you want to define.
                       PROPERTIES IMPORTED_LOCATION

                       # Provides the path to the library you want to import.
                       src/main/cpp/libsubstrate.so)

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in the
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
                       DumpDex.cy

                       # Links the target library to the log library
                       # included in the NDK.
                       ${log-lib} )
target_link_libraries( # Specifies the target library.
                       DumpDex.cy

                       # Links the target library to the log library
                       # included in the NDK.
                       libsubstrate.so)
