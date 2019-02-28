#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Completed for PS2
// file: simpsons.cpp
//
// This program defines our simpsons rule algorithm
//
// Programmer: Matt Bundas bundasma@msu.edu
//
// Revision history:
//    02-26-2019 started and finished
//
// Notes:
// * compile with: "make simpsons"

//defining our simpsons rule integration
double simpsons_rule ( int num_pts, double x_min, double x_max,
                      double (*integrand) (double x) )
{
   //defines our stepsize
   double interval = ((x_max - x_min)/double(num_pts - 1));  // called h in notes
   double sum=  0.;  // initialize integration sum to zero

   for (int n=2; n<num_pts; n+=2)                // loop for odd points
   {
     double x = x_min + interval * double(n-1);
     sum += (4./3.)*interval * integrand(x);
   }
   for (int n=3; n<num_pts; n+=2)                // loop for even points
   {
     double x = x_min + interval * double(n-1);
     sum += (2./3.)*interval * integrand(x);
   }
   // add in the endpoint contributions
   sum +=  (interval/3.) * (integrand(x_min) + integrand(x_max));

   return (sum);
}
