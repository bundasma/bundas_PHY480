//From x=0 to x=1 the difference between the two values calulated are so large
//that you essentially get the same result when you add and subtract the upward
//and downward recursion values. This makes the relative difference fraction equal
//to essentially 1.

//From x=1 to x=10 the values calculated by upward and downward recursion become
//closer and closer to the same value so their relative difference becomes smaller and smaller
//the relative difference shows as linear with x in the graph, so it can be assumed
//that the relative difference scales as x to a power because the graph is in log scale

//From x=10 to x=30 we are in the range where the two bessel functions are oscillating
//so there is some deviation resulting less of a pattern in the relative difference
//but the two methods still calculate very similar values and the relative difference
//is low

//from x=30 to x=40 the two methods begin to deviate more so their relative difference
//increases again in a linear-appearing fashion so we can assume it scales a to
//the power of x

//from x=40 to x=100 the values are again different enough that we get a relative
//error of close to 1. There is even more ossillation in the values in this region
//so the relative difference also ossilates here but stays close to one because
//the two values are fairly different

//  file: bessel.cpp
//
//  Spherical Bessel functions via up and down recursion
//
//
//  Programmer:  Dick Furnstahl  furnstahl.1@osu.edu
//
//  Revision history:
//      02-Jan-2011  new version, for 780.20 Computational Physics
//
//  Notes:
//   * compile with:  "g++ -o bessel bessel.cpp"
//   * adapted from: "Projects in Computational Physics" by Landau and Paez
//             copyrighted by John Wiley and Sons, New York
//             code copyrighted by RH Landau
//   * data saved as: x y1 y2  --- should print column headings!!
//
//************************************************************************




// Modified for PS1
// file: PS1_2.cpp
//
// Spherical Bessel functions via up and down recursion, gsl function
//
// Programmer: Matt Bundas bundasma@msu.edu
//
// Revision history:
//    02-02-2019 started and finished
//
// Notes:
// * g++ -o PS1_3.x PS1_3.cpp -lgsl -lgslcblas"
//
//




// include files
#include <iostream>		// note that .h is omitted
#include <iomanip>		// note that .h is omitted
#include <fstream>		// note that .h is omitted
#include <cmath>
#include <gsl/gsl_sf_bessel.h>
using namespace std;		// we need this when .h is omitted

// function prototypes
double down_recursion (double x, int n, int m);	// downward algorithm
double up_recursion (double x, int n);	        // upward algorithm

// global constants
const double xmax = 100.0;	// max of x
const double xmin = 0.1;	// min of x >0
const double step = 0.1;	// delta x
const int order = 10;		// order of Bessel function
const int start = 50;		// used for downward algorithm

//********************************************************************
int
main ()
{
  double ans_down, ans_up, reldiff, gslbessel;

  // open an output file stream
  ofstream my_out ("PS1_3.dat");

  my_out << "# Spherical Bessel functions via up,down recursion and using GSL"
         << endl;

my_out << "#     x" << "       downward" << "          upward" << "            GSL" << "               relative difference up vs down" << endl;

  // step through different x values
  for (double x = xmin; x <= xmax; x += step)
    {
      ans_down = down_recursion (x, order, start);
      ans_up = up_recursion (x, order);
      gslbessel = gsl_sf_bessel_jl(10,x);
      reldiff = (abs(ans_down-ans_up))/(abs(ans_down) + abs(ans_up));

      my_out << fixed << setprecision (10) << setw (8) << x << " "
	<< scientific << setprecision (10)
	<< setw (17) << ans_down << " "
	<< setw (17) << ans_up << " "
  << setw (17) << gslbessel  << " "
  << setw (17) << reldiff
        << endl;
    }
  cout << "data stored in PS1_3.dat" << endl;

  // close the output file
  my_out.close ();
  return (0);
}


//------------------------end of main program-----------------------

// function using downward recursion
double
down_recursion (double x, int n, int m)
{
  double j[start + 2];		// array to store Bessel functions
  j[m + 1] = j[m] = 1.;		// start with "something" (choose 1 here)
  for (int k = m; k > 0; k--)
    {
      j[k - 1] = ((2.* double(k) + 1.) / x) * j[k] - j[k + 1];  // recur. rel.
    }
  double scale = (sin (x) / x) / j[0];	// scale the result
  return (j[n] * scale);
}


//------------------------------------------------------------------

// function using upward recursion
double
up_recursion (double x, int n)
{
  double term_three = 0.;
  double term_one = (sin (x)) / x;	// start with lowest order
  double term_two = (sin (x) - x * cos (x)) / (x * x);	// next order
  for (int k = 1; k < n; k += 1)	// loop for order of function
    { // recurrence relation
      term_three = ((2.*double(k) + 1.) / x) * term_two - term_one;
      term_one = term_two;
      term_two = term_three;
    }
  return (term_three);
}
