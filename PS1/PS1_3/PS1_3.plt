set terminal x11
set title "relative difference upward vs downward recursion j10"
set xlabel "x"
set ylabel "relative difference j10(x)"

set key bottom left # move the key away from the lines

set timestamp # turn on a date/time indicator

set yrange[:10]

set term png
set output "PS1_3.png"

set log

plot "PS1_3.dat" using 1:5 title "relative difference j10(x)"
