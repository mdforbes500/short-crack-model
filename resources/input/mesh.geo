// Gmsh project created on Fri Jul 20 11:17:38 2018
SetFactory("OpenCASCADE");
//+
Point(1) = {0, 0, 0, 1};
//+
Point(2) = {10, 10, 0, 1};
//+
Point(3) = {10, 0, 0, 1};
//+
Point(4) = {0, 10, 0, 1};
//+
Line(1) = {1, 4};
//+
Line(2) = {1, 3};
//+
Line(3) = {4, 2};
//+
Line(4) = {3, 2};
//+
Line Loop(1) = {1, 3, -4, -2};
//+
Circle(5) = {5, 5, 0, 2.5, 0, 2*Pi};
//+
Line Loop(2) = {1, 3, -4, -2};
//+
Line Loop(3) = {5};
//+
Plane Surface(1) = {2, 3};
