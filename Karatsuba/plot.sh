#!/bin/sh

#
#TODO Automate number of client data we are plotting,
# assuming we are having 5 clients for now.

gnuplot << EOF

set terminal pdf enhanced
set output 'results.pdf'

set key autotitle columnhead right top maxrows 4 font "Helvetica,9"
set style data linespoints
set size 1.0,1.0

set style line 1 lt 1 lw 4.0 pt 6 ps 0.6 linecolor rgb "dark-red"
set style line 2 lt 1 lw 4.0 pt 6 ps 0.6 linecolor rgb "navy-blue"
set style line 3 lt 1 lw 4.0 pt 6 ps 0.6 linecolor rgb "#DAA520"
set style line 4 lt 1 lw 4.0 pt 6 ps 0.6 linecolor rgb "forest-green"
set style line 5 lt 1 lw 4.0 pt 6 ps 0.6 linecolor rgb "#2F4F4F"

set font "Helvetica,10"
set ytics nomirror font "Helvetica,10"
set xlabel "Length of number" font "Helvetica,9"
set ylabel "Execution Time (sec)" font "Helvetica,9"
set log x

plot "results_old.dat" using 1:2 ls 1, \
        '' using 1:3 ls 2, \
        '' using 1:4 ls 3

EOF
