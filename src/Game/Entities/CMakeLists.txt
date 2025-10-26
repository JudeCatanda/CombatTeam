file(GLOB Entities *.cpp)
add_library(Entity ${Entities})

target_include_directories(Entity PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/.. ${INCL_DIR})
target_link_directories(Entity PUBLIC ${LIBS_DIR})
target_link_libraries(Entity PUBLIC ${LIBS_TO_LINK})

