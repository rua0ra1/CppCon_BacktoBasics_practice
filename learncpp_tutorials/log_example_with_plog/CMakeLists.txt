if (NOT CMAKE_VERSION VERSION_LESS 3.3.0)
    if(${CMAKE_VERSION} VERSION_LESS 3.27.0)
        cmake_minimum_required(VERSION 3.3)
    else()
        cmake_minimum_required(VERSION 3.6)
    endif()

    project(test1)

    find_package(plog)

    if(cxx_std_11 IN_LIST CMAKE_CXX_COMPILE_FEATURES)
        add_executable(CXX11 main.cpp)
        target_link_libraries(CXX11 plog::plog)
        set_target_properties(CXX11 PROPERTIES FOLDER Samples CXX_STANDARD 11 CXX_STANDARD_REQUIRED ON)
    endif()
endif()