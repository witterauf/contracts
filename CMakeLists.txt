cmake_minimum_required(VERSION 3.13)
project(Contracts VERSION 1.0 LANGUAGES CXX)

add_library(CppContracts INTERFACE)
target_include_directories(CppContracts
  INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)
add_library(Contracts::Library ALIAS CppContracts)

##[ installation ]#############################################################

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    CppContractsConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)
configure_file(CppContractsConfig.cmake.in CppContractsConfig.cmake @ONLY)
    
install(TARGETS CppContracts EXPORT CppContracts
    ARCHIVE DESTINATION "lib/"
    LIBRARY DESTINATION "lib/"
    RUNTIME DESTINATION "bin/"
)
install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/include" DESTINATION include)
install(EXPORT CppContracts NAMESPACE Contracts:: DESTINATION lib/cmake/contracts)
install(
    FILES
        ${CMAKE_CURRENT_BINARY_DIR}/CppContractsConfigVersion.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/CppContractsConfig.cmake
    DESTINATION
        lib/cmake/contracts
)