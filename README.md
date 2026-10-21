Header guards.

In your answers, explain what these mechanisms prevent and how the two approaches differ?

Header guards prevent the same header file from being included more than once. A conventional header guard uses #ifndef, #define and #endif, while #pragma once uses one line. 


1. struct and class

Explain the difference between the default access rules of struct and class.

In a struct, members are public by default. In a class, members are private by default.

2. TObject

Why do we need our class to be derived from the TObject?

Deriving from TObject allows the class to work with ROOT and be stored and read using ROOT I/O

3. Compilation

Implement the class interface and verify that the class compiles without errors.

The class interface was implemented in MovingObject.h and MovingObject.cxx. It compiled successfully in ROOT using:

.L MovingObject.cxx+


4. Constructors, getters and SetVelocity

Add the three velocity components to the class and initialize them correctly in both constructors. Verify that the getters and SetVelocity work.

The default constructor initializes vx, vy and vz to 0.0. The second constructor initializes them from the given values.

The getters Vx(), Vy() and Vz() returned the expected values. SetVelocity() was also tested and updated the three velocity components correctly.


5. Speed calculations

Implement Speed() and HorizontalSpeed(). Check the functions using the two given examples.

Example A: vx = 0.30 m/s, vy = 0.40 m/s, vz = 0.00 m/s

Speed = 0.50 m/s
Horizontal speed = 0.50 m/s

Example B: vx = 0.30 m/s, vy = 0.40 m/s, vz = 0.50 m/s

Speed = 0.70710678 m/s
Horizontal speed = 0.50 m/s

Changing vz changes the total speed because vz is included in the total speed calculation. It does not change the horizontal speed because horizontal speed only uses vx and vy.

For both examples, 0 <= vxy <= v.


6. TTree generation

10,000 measurements were generated and stored in tree_file.root.

The tree name is 'tree' and the branch name is 'object'.

The random seed used was 12345. Each velocity component was generated independently from a Gaussian distribution with mean 0.0 m/s and standard deviation 0.30 m/s.

The number of entries was checked with 'tree->GetEntries()' and the result was 10000.


7.  Plots

The velocity components plot was saved as 'velocity_components.pdf'. The distribution is centered close to zero in both vx and vy, as expected from the generated Gaussian distributions.

The selected velocities plot was saved as 'selected_velocities.pdf'. It shows vxy versus vz for measurements with total speed greater than 0.50 m/s. The empty region near the bottom is caused by this speed selection.


Commands used

To generate the ROOT file:

root -l
.L MovingObject.cxx+
.x write.cxx
.q

To read the ROOT file and create the plots:

root -l
.L MovingObject.cxx+
.x read.C
.q





