#Comentarios
#@: Target
#^: Todas las Pertenencias
#<: Primera Dependencia

all: datos.txt

updown.x: sumas.cpp
	g++ sumas.cpp -o updown.x

datos.txt: updown.x
	./updown.x 1000 > datos.txt
clean:
	rm -f datos.txt updown.x
