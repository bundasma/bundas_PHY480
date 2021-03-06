//  file: area.cpp
//
//  This program calculates the area of a circle, given the radius.
//
//  Programmer:  Dick Furnstahl  furnstahl.1@osu.edu
//
//  Revision history:
//      02-Jan-2004  original version, for 780.20 Computational Physics
//      01-Jan-2010  updates to "To do" wishlist
//      12-Jan-2016  comment out "using namespace std;"
//
//  Notes:
//   * compile with:  "g++ -o area.x area.cpp"
//
//  To do:
//   1. output the answer with higher precision (more digits)
//   2. use a "predefined" value of pi or generate it with atan
//   3. define an inline square function
//   4. split the calculation off into a function (subroutine)
//   5. output to a file (and/or input from a file)
//   6. add checks of the input (e.g., for non-positive radii)
//   7. rewrite using a Circle class
//
//*********************************************************************//


//Modifications for PS1
// file: area_new.cpp
//
// This program calculates the area of a circle, given the radius.
//
// Programmer: Matt Bundas bundasma@msu.edu
//
// Revision history:
//    02-01-2019 started and finished, added 1-6 in to do
//
// Notes:
// * compile with:  "g++ -o area_new.x area_new.cpp"
//


// include files
#include <iostream>	     // this has the cout, cin definitions
//using namespace std;     // if omitted, then need std::cout, std::cin
#include <iomanip>
#include <math.h>
#include <fstream>
//*********************************************************************//

//const double pi = 3.1415926535897932385;   // define pi as a constant

inline double square(double x){
  return x*x;}

double calc_area(double radius){
  return M_PI*square(radius);}

int
main ()
{
  double radius;    // every variable is declared as int or double or ...

  std::cout << "Enter the radius of a circle: ";	// ask for radius
  std::cin >> radius;

  //if a negative radius is inputted, throws an error
  if (radius < 0){
    throw std::runtime_error("input radius is negative");}
  std::ofstream integ_out ("area.dat");
  
  double area = calc_area(radius);	// standard area formula

  std::cout << std::setprecision(10) << "radius = " << radius << ",  area = " << area << std::endl;

  integ_out << std::setprecision(10) <<  area << std::endl;
  return 0;			// "0" for successful completion
}

//*********************************************************************//
