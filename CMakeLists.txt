cmake_minimum_required( VERSION "2.6.4" )

project( autometal CXX C )


include_directories(
    src
)

set( AUTOMETAL_SOURCES
    src/autometal/operators/Operator.cc
    src/autometal/operators/RunnableOperator.cc

    src/autometal/operators/kubernetes/KubernetesOperator.cc

    src/autometal/platforms/Platform.cc
    src/autometal/platforms/Linux.cc
    src/autometal/platforms/Ubuntu.cc
)

set( AUTOMETAL_LIBS
    
)


# AutoMetal is built with c++0x to support older kernels, such as in OEL7 (g++ 4.4)

set( AUTOMETAL_COMPILE_OPTIONS
    -Wall
    -Wextra
    -O3
    #-std=c++98
    -std=c++0x
    #-std=gnu++11
    #-std=c++1y
    #-std=c++17
)

add_executable( build/autometal ${AUTOMETAL_SOURCES} src/autometal/main.cc )

target_link_libraries( build/autometal ${AUTOMETAL_LIBS} )

set_target_properties( build/autometal
    PROPERTIES
    COMPILE_OPTIONS  "${AUTOMETAL_COMPILE_OPTIONS}"
)