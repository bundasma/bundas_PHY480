set timestamp

set xlabel 'number of points used'
set ylabel 'relative error'

set title 'relative error in integration'

set log

set term png
set output "error.png"

plot "error.dat" using 1:2 title "simpsons", "error.dat" using 1:3 title "milne"
