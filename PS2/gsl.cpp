#include <stdio.h>
#include <math.h>
#include <gsl/gsl_integration.h>

// Completed for PS2
// file: gsl.cpp
//
// This program defines our gsl algorithm
//
// Programmer: Matt Bundas bundasma@msu.edu
//
// Revision history:
//    02-26-2019 started and finished
//
// Notes:
// * compile with: "make gsl"




//defining our gsl function
double gsl_int(double x_min, double x_max, double (*f) (double x,void * params)){

  gsl_integration_workspace * w
    = gsl_integration_workspace_alloc (1000);

double result, error;

//parameter because gsl is weird
double alpha = 1.0;

//defines a function gsl can use
gsl_function F;
F.function = f;
F.params = &alpha;

double answer;

//use gsl to get the exact integral
gsl_integration_qags (&F, x_min, x_max, 0, 1e-7, 1000,
                      w, &result, &error);
return result;

}
