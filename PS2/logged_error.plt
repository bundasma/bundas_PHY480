
set timestamp

set xlabel 'log(stepsize) '
set ylabel 'log(number of points used)'

set title 'relative error in integration'


set term png
set output "logerror.png"

f(x) = m*x +b

fit [1:5] f(x) "error_logged.dat" using 1:2 via m,b
fit [1:5] f(x) "error_logged.dat" using 1:3 via m,b


plot "error_logged.dat" using 1:2 title "simpsons", "error_logged.dat" using 1:3 title "milne"
