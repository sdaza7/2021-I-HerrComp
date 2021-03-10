#Comentarios
#@: Target (Acompañada de $)
#^: Todas las Pertenencias (Acompañada de $)
#<: Primera Dependencia (Acompañada de $)
#%: Todos los archivos de la forma -> Emacs

CXX = g++
CXXFLAGS = -O2 -g
all: datos.pdf

#Implicit Rules
#Forma 1: Caso General
%.x: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@
#Forma 2: Caso Más Específico
#updown.x: sumas.cpp
#	$(CXX) $(CXXFLAGS) updown.cpp -o updown.x

datos.txt: updown.x
	./$< 1000 > $@
datos.pdf: datos.txt updown.gp
	gnuplot updown.gp
clean:
	rm -f datos.txt updown.x datos.pdf
