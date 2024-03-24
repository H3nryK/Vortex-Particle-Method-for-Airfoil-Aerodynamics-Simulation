# Vortex-Particle-Method-for-Airfoil-Aerodynamics-Simulation

## Overview

This program simulates the aerodynamics of a lifting airfoil using the vortex particle method. The vortex particle method represents the flow field around the airfoil by tracking discrete vortices shed from the trailing edge.

## Features:

- Calculates induced velocity at a point from vortex particles.
- Computes lift coefficient from airfoil data.
- Simulates time evolution of vortex particles shedding from the airfoil.
- Separates bound and wake vortex particles.
- Calculates lift and drag forces on the airfoil.
- Prints lift force, drag force, and wake particle positions.
  
## Dependencies:

- C++ compiler supporting C++11 or later.
- Standard C++ libraries (iostream, vector, cmath, algorithm).
- Code blocks IDE.

## How to Use:

1. Clone the repository:

   ```bash
   git clone https://github.com/H3nryK/Vortex-Particle-Method-for-Airfoil-Aerodynamics-Simulation.git

2. open the project folder

   ```bash
   cd Vortex-Particle-Method-for-Airfoil-Aerodynamics-Simulation

3. Compilation: Compile the source code (airfoil_simulation.cpp) using a C++ compiler. For example:

   ```bash
   g++ airfoil_simulation.cpp -o airfoil_simulation

4. Execution: Run the compiled executable:

   ```bash
   ./airfoil_simulation

5. Output: The program will output the lift force, drag force, and positions of wake particles to the console.

6. Alternatively, you can open with Code Blocks then build and the program to execute it.

## Customization:

- Modify the main function to adjust blade geometry, inflow conditions, time step size, and simulation duration.
- Update the calcLiftCoefficient function to use more complex airfoil data or lift coefficient models.
- Extend the code to include more sophisticated aerodynamic models or boundary conditions.
  
## Contributing:

Contributions are welcome! Feel free to fork the repository, make improvements, and submit pull requests.

## License:

This program is provided under the MIT License.

## Acknowledgments:

This code is inspired by principles of computational fluid dynamics and vortex methods.
Thanks to contributors to the field of aerodynamics and numerical simulation for their valuable insights.
