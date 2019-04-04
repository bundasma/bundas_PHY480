#  file: derivative_test.plt
#
#  Gnuplot plot file for derivative_test output
#
#  Programmer:  Dick Furnstahl  furnstahl.1@osu.edu
#
#  Revision history
#   2004-01-24  original version for 780.20 session 5
#   2004-01-16  added postscript enhanced and comments for session 4
#

# record the time and date the graph was generated
set timestamp

# titles and labels
set title 'extrapolated wavefunction b= 2.0'
set xlabel 'r'
set ylabel 'u(r)'

# move the legend to a free space
set key right

# set the x and y axis scales (already logs)
#set xrange [-10:-1]
#set yrange [-12:0]


# set the terminal type to be the screen (which is x11 here)
set term x11

# plot the data as well as the fit, with appropriate titles
plot "eigen_basis1_b_2_0.dat" using ($1):($2) title 'est wavefunction,dim = 1', \
   "eigen_basis5_b_2_0.dat" using ($1):($2) title 'est wavefunction,dim = 5', \
   "eigen_basis10_b_2_0.dat" using ($1):($2) title 'est wavefunction,dim = 10', \
   2*x*exp(-x) title 'exact wavefunction'
  # "eigen_basis20_b_1_6.dat" using ($1):($2) title 'est wavefunction,dim = 20',\


set term png
set output "eigen_dim2_0.png"

replot
