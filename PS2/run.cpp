#include "milne.cpp"
#include "gsl.cpp"
#include "simpsons.cpp"
#include <fstream>
#include <math.h>

// Completed for PS2
// file: run.cpp
//
// This program runs our three integration algorithms and outputs the relative
// errors for our simpsons and milne algorithm to a file
//
// Programmer: Matt Bundas bundasma@msu.edu
//
// Revision history:
//    02-26-2019 started and finished
//
// Notes:
// * compile with: "make run"


//There seem to be just two regions to my error graph, where the error changes as
//stepsize to a power and where the error change with stepsize has no real structure.
//Simpsons method has a structured slope until about 1100 points are used. Milnes
//method has a structured slope until about 250 points are used. These numbers
//are much different and are due to the fact that milne's method has a much
//steeper slope of -6.26 compared to simpsons slope of -4.19. This means that
//the error using milne's method behaves like h^6 while simpsons rule behaves
//like h^4. So to get the same error in integration you can have
//a larger stepsize with milnes rule compared to simpsons rule. This is as expected
//because simpsons rule is a second order method while milnes rule is a fourth
//order method.

//The graph also shows that for all stepsizes shown before the unstructured
//regions that milne's integration method is more accurate than simpson's method

//Our second region where there is no defined slope is due to the error reaching
//the machine precision limit. Up until the point where there is a nonsensical
//slope the error is behaving according to a power of h, but at some point we reach
//a point where the error becomes small enough that it bottoms out and is
//determined more by machine precision and how the computer decides to handle
//the numbers at the time.


//The optimum number of points based on the graph will be the point where
//we reach this bottoming out point and machine precision takes over. This
//will be the number of steps which gives the smallest error while not using
//more steps than are necessary to reach the best precision possible. You can
//use more points than where the error bottoms out but you will not see
//an increase in accuracy but will see an increase in the time for the algorithm
//to complete so you might as well use the smallest number of steps that still gets
//you the best accuracy possible. Based on this reasoning the ideal number of points
//for simpsons rule is about 1200, while the ideal number of steps for milne's
//rule is about 250 steps. This is where the error for each method bottom's out
//with stepsize. This discrepency agrees with what is expected, as the higher
//order method should have less error and require less points to get the same
//or better precision than the lower order method.


//defining the function I want to integrate
double
my_integrand (double x)
{
  return (exp (x) + cos(x) +(x*x*x));
}

//defining a function that GSL can use
double f (double x, void * params) {
  double f = my_integrand(x);
  return f;}


int main(){

  //opening dat file to write to
  ofstream error ("error.dat");

  double result_simp;
  double result_milne;
  double result_gsl;

  //setting our integration bounds
  double begin = 0;
  double end = 2;

  //i used to calculate number of points used
  double i = 1;

  double rel_error_simp;
  double rel_error_milne;
  double nsteps;
  error << setprecision(15) << "nsteps       simpsons                    milne" << endl;


 //looping through different number of points
 while (i < 10000){

  //number of steps used in integration
  nsteps = 4*i + 1;

  //integrating with different algorithms
  result_simp = simpsons_rule(nsteps,begin,end,&my_integrand);
  result_milne = milne(nsteps,begin,end,&my_integrand);
  result_gsl = gsl_int(begin,end,&f);

  //calculating error in our written algorithms
  rel_error_simp = abs(result_simp - result_gsl)/result_gsl;
  rel_error_milne = abs(result_milne - result_gsl)/result_gsl;

  error << setprecision(15) <<  nsteps << "          " << rel_error_simp << "        " << rel_error_milne << endl;

  //if nsteps is already large we dont change it by much to make our graph look nice
  if (nsteps < 100){
  i = i + 1;}
  if ((nsteps > 100) and (nsteps < 1000))
  i = i + 5;
  if (nsteps > 1000)
  i = i + 19;

}}
