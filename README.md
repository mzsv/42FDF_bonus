# FDF - Wireframe Model

## Overview

The FDF project is a basic computer graphics project using the MiniLibX library. It involves creating a simple wireframe model of a landscape by linking various points (x, y, z) with line segments. The project aims to familiarize you with the MiniLibX library and the basics of graphics programming, such as placing points in space and viewing the scene from a specific viewpoint. Bonus requirements included.

## Objectives

- Create a wireframe model representation of a 3D landscape.
- Use the MiniLibX library to handle graphics.
- Implement isometric projection for rendering the model.
- Provide interactive controls for manipulating the model (bonus):
    - Zoom in/out
    - Translation
    - Rotation
- Implement weak-perspective projection (bonus).
- Implement color rendering (bonus).
- Implement depth shading (bonus).

## Features

- **Isometric Projection**: Displays the 3D model in an isometric view.
- **Interactive Controls**: Allows users to manipulate the model using mouse and keyboard inputs.
- **Graphical Window**: Displays the model in a graphical window that supports smooth interactions.
- **Depth Shading**: Renders the model such that the deepest (further away from the screen) points are darker, enhancing the illusion of depth.
- **Color Rendering Mode**: Reads the color from the input file and creates color gradients over the segments between different points. Additional default color mode, assigned based on the height of each point.
- **Multiple Projections (Bonus)**: Includes additional weak-perspective projection.

## Controls

### Mouse Controls

- **Left Mouse Button**: Rotate the model.
- **Right Mouse Button**: Translate the model.
- **Scroll Up/Down**: Zoom in/out.

### Keyboard Controls

- **C**: Change color mode.
- **H**: Display help.
- **I**: Switch to isometric mode.
- **P**: Switch to perspective mode.
- **S**: Toggle depth-shade mode.
- **ESC**: Close the window and quit the program.

## Getting Started

### Installation

1. Clone the repository:
   ```sh
   git clone <repository-url>

2. Compile the project:
   ```sh
   make bonus

3. Run the project with a test map:
   ```sh
   ./fdf maps/test_maps/42.fdf

## Acknowledgements

- The 42 School for providing the project specifications and environment.

