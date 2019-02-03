//The calculations are not equally precise across all possible N
//There is a general trend that as N increases the summations become more and
//more similar as the graph shows the difference/sum generally decreasing from left
//to right. This however isn't always the case as there are points in the graph
//where N is larger but the difference/sum is also larger, especially for small N
//such as from N=30 to N=40, where the difference/sum goes from .203 to .207.
//It seems like the two summations are never "equally as precise" as this would
//mean they calculated essentially the exact same value and the difference/sum
//would be zero but the differnce/sum is never zero.
//There is one region from N=10 to N=100 where the difference/sum does seem
//to behave like a power law as there is a constant, noticable slope. In This
//region N changes by 1 factor of 10 and the difference/sum changes by .2 factors of
//10 so the slope here is about .2. In the region after this, from 100 onward There
//is a constant slope but it is very gradual as you change 5 factors of 10 in N
//but hardly change the difference/sum, if you would like you could say the
//difference/sum changes by about .3 factors of 10 so the slope would be about .06

//The downward sum is most precise because it reduces round off errors as we
//are summing starting with small numbers. It is easier for the computer to sum
//small numbers to small numbers than it is for it to add a very small number to a big
//number. In the upwards sum we start with large numbers then begin adding smaller
//and smaller numbers so the computer gives less accurate results.


#include <iostream>		// note that .h is omitted
#include <iomanip>		// note that .h is omitted
#include <fstream>		// note that .h is omitted
#include <cmath>
using namespace std;

int main(){

  float N;
  float sum_up = 0.0;
  float sum_down = 0.0;
  float error_business;
  float x = 1.1;
  std::ofstream sum_out ("summation.dat");
  sum_out << "#  N" << "    difference/sum " << endl;
  while(x < 7){
    N = pow(10,x);
    //summing up from 1 to N
    for(float n = 1.0; n <= N; n++){
      sum_up = sum_up + (1/n);}

    //summing down from N to 1
    for (float n = N; n >= 1; n--){
      sum_down = sum_down + (1/n);}

    //finding difference divided by sum
    error_business = 2.0*(abs(sum_up - sum_down))/(abs(sum_up) + abs(sum_down));
    sum_out << setprecision(10) << N << "   " << error_business << endl;
    x = x + .1;
  }





}
