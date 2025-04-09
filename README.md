# CurveExample

Design a small program in C++ that would implement support of 3D curves hierarchy.
1. Support a few types of 3D geometric curves – circles, ellipses and 3D helixes. (Simplified
definitions are below). Each curve should be able to return a 3D point and a first derivative (3D
vector) per parameter t along the curve.
2. Populate a container (e.g. vector or list) of objects of these types created in random manner with
random parameters.
3. Print coordinates of points and derivatives of all curves in the container at t=PI/4.
4. Populate a second container that would contain only circles from the first container. Make sure the
second container shares (i.e. not clones) circles of the first one, e.g. via pointers.
5. Sort the second container in the ascending order of circles’ radii. That is, the first element has the
smallest radius, the last - the greatest.
6. Compute the total sum of radii of all curves in the second container
