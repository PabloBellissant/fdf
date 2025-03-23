FDF

FDF is a 3D wireframe representation program built in C using the MiniLibX graphics library. It takes a map file (a simple text file containing altitude values) and renders it in an isometric projection. The program supports antialiasing, gradient shading, and other graphical enhancements.

Features

Isometric Projection: Displays a 3D representation of the terrain.

Antialiasing: Smooths out jagged edges for a cleaner look.

Gradient Coloring: Applies color gradients based on altitude values.

Zoom & Rotation: Allows interactive zooming and rotation.

Customizable Colors: Different color palettes for a better visual experience.

Installation

# Clone the repository
git clone https://github.com/yourusername/fdf.git
cd fdf

# Compile the program
make

# Run FDF with a map file
./fdf maps/42.fdf

Controls

Key

Action

Arrow Keys

Move the map

+ / -

Zoom In / Out

A / D

Rotate left / right

W / S

Rotate up / down

ESC

Exit the program

Antialiasing Showcase

Below is an example of the antialiasing feature in action:



Gradient Shading

The program applies smooth gradient shading based on altitude values:



Supported Map Format

The FDF program accepts maps in the following format:

0  0  0  0  0  0  0  0  0  0
0  1  2  3  4  3  2  1  0  0
0  2  4  6  8  6  4  2  0  0
0  3  6  9 12  9  6  3  0  0

Each number represents an altitude value for the corresponding point on the map.

Dependencies

MiniLibX (included in the repository)

Make (for compilation)

License

This project is licensed under the MIT License.

Author

Pablo Bellissant
