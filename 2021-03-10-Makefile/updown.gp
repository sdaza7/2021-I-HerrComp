set xlabel 'N'
set ylabel 'Delta'
set log y
set term pdf
set out 'datos.pdf'
plot 'datos.txt' u 1:4
