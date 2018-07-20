// Gmsh project created on Fri Jul 20 12:07:04 2018
SetFactory("OpenCASCADE");
//+
Point(1) = {0, 0, 0, 1.0};
//+
Point(2) = {0, 10, 0, 1.0};
//+
Point(3) = {10, 10, 0, 1.0};
//+
Point(4) = {10, 0, 0, 1.0};
//+
Line(1) = {1, 2};
//+
Line(2) = {2, 3};
//+
Line(3) = {3, 4};
//+
Line(4) = {4, 1};
//+
Circle(5) = {5, 5, 0, 2.5, 0, 2*Pi};
//+
Line Loop(1) = {1, 2, 3, 4};
//+
Line Loop(2) = {5};
//+
Plane Surface(1) = {1, 2};
//+
Recombine Surface {1};
