file(GLOB EngineSources *.cpp)
add_library(Engine ${EngineSources})

target_include_directories(Engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${INCL_DIR})
target_link_directories(Engine PUBLIC ${LIBS_DIR})
target_link_libraries(Engine PUBLIC ${LIBS_TO_LINK})
