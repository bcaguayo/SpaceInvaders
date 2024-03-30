## Space Invaders - C++ Version

**Date:** March 30, 2024

**Author:** Miles Soto Aguayo

**Course:** CIS 1901

## Overview

This project aims to develop a C++ adaptation of the classic 1978 arcade game Space Invaders. It leverages C++'s memory management capabilities to create a robust and lightweight terminal-based experience that simulates the core mechanics of resource management, survival, and decision-making, capturing the essence of the original game.

## Features

1. Classic Gameplay
2. Custom Assets
3. Responsiveness
4. Thorough Testing
* Leaderboard (Optional)

## Stack

* **Language:** C++
* **Graphics Library (Preferred):** OpenGL (Option 1)
* **Graphics Library (Alternative):** SFML (Option 2)
* **Additional Libraries:** GLFW + GLEW

## Why C++?

C++ is a popular choice for graphics programming due to its efficiency in speeding up the rendering process. This project aims to utilize C++ to deliver a high frame rate GUI with responsive gameplay.

## Design Considerations

Similar to the original, this version won't include a tutorial.

## Project Structure

* **main.cpp:** Runs the game, manages game state (running, end), creates entities, manages the game loop, handles user interface elements, and utilizes the input class for keyboard control.
* **entity.hpp:** Base class for all renderable game components. It defines fields like position, velocity, health points (HP), sprite, projectile rate, a "weak" boolean flag (dies on first collision), etc.
* **player.cpp:** Represents the player ship, controllable via keyboard input. Loses health upon collision with enemy projectiles.
* **enemy.cpp:** Defines static enemy behavior, including periodic projectile creation. Collisions with player projectiles affect enemy health.
* **projectile.cpp:** Represents weak and non-controllable projectiles.
* **barrier.cpp:** Defines destroyable barriers with static position and speed (non-controllable).
* **gui.cpp:** Manages GUI elements for menus and gameplay, including HP indicators, score display, etc.
* **input.cpp:** Handles keyboard input, capturing key presses and sending them to the game for updating player controls, shooting, starting/quitting the game, etc.
* **resources.cpp:** Wrapper class for managing game sprites.
* **audio.hpp (Optional):** Wrapper class for audio functionalities (e.g., sound effects for projectiles).
* **File Extensions:** When not explicitly mentioned, the structure uses the `.hpp` and `.cpp` convention for header and implementation files, respectively.

## Work Style

This is a single-developer project intended for my game development portfolio. Collaboration is open to anyone interested. 

## Milestones

* **Basic Demo (April 17):**
    * Playable core game without UI (entities only).
    * No menus implemented.
    * Player controls and enemy movement established.
    * Enemies have 1 HP, while the player has 3 HP.
* **Polishing & Testing (April 24):**
    * All planned functionalities implemented.
    * Final sprites finalized.
    * Thorough testing completed.
* **Full Game Functionality (May 1):**
    * Menu implemented with options to play and quit.
    * Win condition implemented (ending the game).
    * Enemies have increased HP (closer to the original game).
* **Stretch Goals (Optional):**
    * Score system with three-letter name input and file I/O.
    * Sound design implementation.
    * Physics engine integration (tentative).

## Testing Approach

The project will undergo extensive manual testing. Additionally, unit tests will be written for non-GUI classes to ensure their proper functionality.
