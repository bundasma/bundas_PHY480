#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;

// Completed for PS2
// file: milne.cpp
//
// This program defines our milne algorithm
//
// Programmer: Matt Bundas bundasma@msu.edu
//
// Revision history:
//    02-26-2019 started and finished
//
// Notes:
// * compile with: "make milne"

//defining our milne function
double milne(int num_pts, double x_min, double x_max,
        double (*integrand) (double x)){

        //defining our stepsize
        double interval = ((x_max - x_min)/double(num_pts - 1));  // called h in notes
        double sum=  0.;  // initialize integration sum t

        for (int n=2; n<num_pts; n+=2)                // loop for odd points
        {
          double x = x_min + interval * double(n-1);
          sum += (64./45.)*interval * integrand(x);
        }
        for (int n=3; n<num_pts; n+=4)                // loop for even points
        {
          double x = x_min + interval * double(n-1);
          sum += (24./45.)*interval * integrand(x);}

        for (int n=5; n<num_pts; n+=4)                // loop for even points
        {
          double x = x_min + interval * double(n-1);
          sum += (28./45.)*interval * integrand(x);}
        // add in the endpoint contributions
        sum +=  (interval*14./45.) * (integrand(x_min) + integrand(x_max));
        return (sum);

}
