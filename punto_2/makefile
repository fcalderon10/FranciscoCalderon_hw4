cuerda.gif : cuerda.dat animacion.py
	python animacion.py cuerda.dat

cuerda.dat : cuerda
	./cuerda > cuerda.dat

cuerda : cuerda.c
	gcc cuerda.c -o cuerda -lm
clean:
	rm cuerda cuerda.dat *.png cuerda.gif
