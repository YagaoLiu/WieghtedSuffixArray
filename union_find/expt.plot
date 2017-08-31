set terminal postscript eps solid font "Times-Roman,25"
set xrange [0:33]
set yrange [0:14000]
set output "time.eps"
f(x) = a*x + b
g(x) = c*x*log(x) + d
set key inside bottom right
fit f(x) "time.dat" using 1:2 via a,b

plot "time.dat" using 1:2 w p ls 7 ps 2 lc 1 notitle,\
	"time.dat" using 1:2 w l ls 7 lw 2 lc 1 title "union find",\
	f(x) ls 7 lw 2 lc 3 title "linear",\

