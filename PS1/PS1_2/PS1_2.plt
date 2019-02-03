set terminal x11
set title "summation of 1/n differing orders"
set xlabel "N"
set ylabel "difference divided by sum"

set key bottom right # move the key away from the lines

set timestamp # turn on a date/time indicator

set term png
set output "summation.png"

set log


plot "summation.dat" using 1:2 title "difference divided by sum"
