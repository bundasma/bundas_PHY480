//The calculations are not equally precise across all possible N
//There is a general trend that as N increases the summations become further apart
//from eachother as you increase N, but this is certainly not a hard rule. For
//example at N = 10 the difference/sum is 1e-7, but at N=10000 the difference/sum
//is 1e-6. The summations however in general are always very close as their sum/difference
//never gets higher than 1e-4. It does not look like the error behaves like a power law
//in any region as it is highly discontinuous. There is a "slope" to the error after
//about N=10,000 but this is more af an artifical slope constructed by all of the
//discontinuities in the errors. You could perhaps say that the slope is close to 2
//because the error rises about 2 orders of magnitude in one order of magnitude
//change in N. There seem to be 3 main regions of the error graph, from 1 to 100 where
//the error is the smallest and disontinuous. This could perhaps have the smallest
//error beause we are summing relatively large values so computer error will be the smallest
//as computers are relatively good at adding large numbers compared to small numbers.
//Another region is between about 100 and 10,000 where there are again discontinuities
//but there are also osscilations in the error which span a few orders of magnitude.
//This because we may have gotten to a point where we are adding small enough numbers
//such that the two algorithms behave differently and we get funny results. The next
//region of the graph is from 10,000 to 100,000, where the error increases generally
//but still has discontinuities.

//The downward sum is most precise because it reduces round off errors as we
//are summing starting with small numbers. It is easier for the computer to sum
//small numbers to small numbers than it is for it to add a very small number to a big
//number. In the upwards sum we start with large numbers then begin adding smaller
//and smaller numbers so the computer gives less accurate results.



// Completed for PS1
// file: PS1_2.cpp
//
// This program finds  the summation of 1/n summing up and summing down
//
// Programmer: Matt Bundas bundasma@msu.edu
//
// Revision history:
//    02-01-2019 started and finished
//
// Notes:
// * compile with: "make -f make_PS1_2"
//
//

#include <iostream>		// note that .h is omitted
#include <iomanip>		// note that .h is omitted
#include <fstream>		// note that .h is omitted
#include <cmath>
using namespace std;

int main(){

  //float N;
  float sum_up = 0.0;
  float sum_down = 0.0;
  float error_business;
  //float x = 1.1;
  std::ofstream sum_out ("summation.dat");
  sum_out << "#  N" << "    difference/sum " << endl;
  for (int N =1; N<100000;++N){

    sum_up = 0.0;
    sum_down = 0.0;
    //summing up from 1 to N
    for(float n = 1.0; n <= N; n++){
      sum_up = sum_up + (1.0/n);}

    //summing down from N to 1
    for (float n = N; n >= 1; n--){
      sum_down = sum_down + (1.0/n);}

    //finding difference divided by sum
    error_business = 2.0*(abs(sum_up - sum_down))/(abs(sum_up) + abs(sum_down));
    sum_out << setprecision(10) << N << "   " << error_business << "    " << sum_up << "     " << sum_down << endl;
}






}
