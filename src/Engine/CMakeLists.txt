file(GLOB EngineSources *.cpp)
add_library(Engine INTERFACE ${EngineSources})

target_include_directories(Engine INTERFACE ${CMAKE_CURRENT_SOURCE_DIR} ${INCL_DIR})
target_link_directories(Engine INTERFACE ${LIBS_DIR})
target_link_libraries(Engine INTERFACE ${LIBS_TO_LINK})
