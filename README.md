# Conway's Game of Life in C++

This is a simple implementation of Conway's Game of Life using C++ and the Raylib library for rendering. The project is managed using CMake.

## What is the Game of Life?
Conway's Game of Life is a cellular automaton devised by mathematician John Conway. It consists of a grid of cells that evolve over discrete time steps according to simple rules:

1. **Survival**: A live cell with 2 or 3 neighbors stays alive.
2. **Death by Isolation**: A live cell with fewer than 2 neighbors dies.
3. **Death by Overpopulation**: A live cell with more than 3 neighbors dies.
4. **Reproduction**: A dead cell with exactly 3 neighbors becomes alive.

These rules lead to complex, emergent behavior from simple initial configurations.

## Prerequisites
To build and run this project, you will need:

- A C++ compiler that supports C++17 or later.
- CMake version 3.31 or higher.
- Git (to fetch dependencies).

## Build Instructions

1. Clone this repository:

   ```bash
   git clone <repository_url>
   cd <repository_directory>
   ```

2. Create a build directory and navigate to it:

   ```bash
   mkdir build && cd build
   ```

3. Run CMake to configure the project:

   ```bash
   cmake ..
   ```

4. Build the project:

   ```bash
   cmake --build .
   ```

## Run the Application
After building the project, you can run the executable:

```bash
./game_of_life
```

## Dependencies
The project uses Raylib for rendering. Raylib is included as a dependency and will be automatically fetched and built by CMake.
