placas.pdf : placas.dat grafica.py

	python grafica.py placas.dat

placas.dat:placas

	./placas > placas.dat

placas: placas.c

	gcc placas.c -o placas -lm

clean:
	rm placas placas.dat placas.pdf
