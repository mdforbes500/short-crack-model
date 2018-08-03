// Gmsh project created on Wed Jul 25 15:40:41 2018
SetFactory("OpenCASCADE");
//+
Point(1) = {-1, -1, 0, 1.0};
//+
Point(2) = {1, -1, 0, 1.0};
//+
Point(3) = {1, 1, 0, 1.0};
//+
Point(4) = {-1, 1, 0, 1.0};
//+
Line(1) = {4, 1};
//+
Line(2) = {1, 2};
//+
Line(3) = {2, 3};
//+
Line(4) = {3, 4};
//+
Line Loop(1) = {1, 2, 3, 4};
//+
Plane Surface(1) = {1};
//+
Physical Line("left") -= {1};
//+
Physical Line("right") -= {3};
//+
Physical Line("upper") -= {4};
//+
Physical Line("bottom") -= {2};
//+
Transfinite Surface {1} = {4, 3, 2, 1};
//+
Transfinite Line {1, 3, 4, 2} = 33 Using Progression 1;
//+
Recombine Surface {1};
//+
Transfinite Line {1} = 1 Using Progression 1;
//+
Transfinite Line {3} = 1 Using Progression 1;
//+
Transfinite Line {4} = 1 Using Progression 1;
//+
Transfinite Line {2} = 1 Using Progression 1;
//+
Transfinite Line {1, 3, 4, 2} = 2 Using Progression 1;
