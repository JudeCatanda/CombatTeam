file(GLOB GameSources *.cpp)

add_executable(CombatTeam ${GameSources})

target_include_directories(CombatTeam PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${INCL_DIR})
target_link_directories(CombatTeam PUBLIC ${LIBS_DIR})
target_link_libraries(CombatTeam PUBLIC Engine ${LIBS_TO_LINK})
