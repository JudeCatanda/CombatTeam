add_library(Core INTERFACE)
target_include_directories(Core INTERFACE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/src/Engine ${INCL_DIR})
target_link_libraries(Core INTERFACE Engine)
