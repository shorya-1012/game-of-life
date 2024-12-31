add_library(game_utils STATIC 
  constants.hpp
  grid.hpp
  grid.cpp
)

target_include_directories(game_utils INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})


target_link_libraries(game_utils raylib)
