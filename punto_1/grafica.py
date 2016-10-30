import numpy as np
import matplotlib.pyplot as mp

datos = np.loadtxt('placas.dat')

datos=np.split(datos,250)

mp.figure()
mp.imshow(datos)
mp.show()
