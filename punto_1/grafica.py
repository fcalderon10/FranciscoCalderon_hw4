import numpy as np
import matplotlib.pyplot as mp
import matplotlib.cm as cm

datos = np.loadtxt('placas.dat')

datos=np.split(datos,250)

mp.figure()
mp.imshow(datos,interpolation='bicubic')
mp.savefig('placas.pdf')
