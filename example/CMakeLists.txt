cmake_minimum_required (VERSION 2.8)

project(ragemp-cppsdk)

set(PROJECT_NAME ragemp-cppsdk)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE PROJECT_SOURCE_FILES "src/*.h" "src/*.hpp" "src/*.cpp" "include/*.h" "include/*.hpp" "include/*.cpp")

macro(GroupSources curdir groupindex)
  file(GLOB children RELATIVE ${curdir} ${curdir}/*)

  foreach(child ${children})
    if(IS_DIRECTORY ${curdir}/${child})
      GroupSources(${curdir}/${child} ${groupindex}/${child})
    else()

      string(REPLACE "/" "\\" groupname ${groupindex})

      source_group(${groupname} FILES ${curdir}/${child})
    endif()
  endforeach()
endmacro()

GroupSources(${PROJECT_SOURCE_DIR}/src "Source Files")
GroupSources(${PROJECT_SOURCE_DIR}/include "Include Files")

include_directories(
  ${PROJECT_SOURCE_DIR}/src
  ${PROJECT_SOURCE_DIR}/include
  ../
)

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  target_compile_options(${PROJECT_NAME} PRIVATE
    -Wno-deprecated-declarations
    -Wno-switch-enum
    -Wno-unused-command-line-argument
    -Wno-macro-redefined
    -Wno-inconsistent-missing-override
    -Wno-deprecated-declarations
    -Wno-return-type
    -Wno-switch-enum
    -Wno-switch
    -Wno-parentheses
    -Wno-unused-private-field
    -Wno-unused-variable
    -Wno-format
    -Wno-reorder
    -Wno-delete-non-virtual-dtor
    -Wno-microsoft-cast
    -Wno-unused-function
    -Wno-unused-lambda-capture
    -Wno-missing-braces
    -Wno-unused-local-typedef
    -Wno-tautological-constant-out-of-range-compare
    -Wno-delete-incomplete
    -Wno-c++11-narrowing
    -Wno-comment
  )

    target_compile_options(${PROJECT_NAME} PRIVATE
      -fms-compatibility
      -fms-extensions
      /EHsc
	  /FORCE
    )
    set_target_properties(${PROJECT_NAME} PROPERTIES
      COTIRE_ENABLE_PRECOMPILED_HEADER FALSE
      COTIRE_ADD_UNITY_BUILD FALSE
    )
endif()

add_library(
  ${PROJECT_NAME} SHARED
  ${PROJECT_SOURCE_FILES}
)