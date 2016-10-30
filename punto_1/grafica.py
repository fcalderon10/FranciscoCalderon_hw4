import numpy as np
import matplotlib.pyplot as mp
import matplotlib.cm as cm

datos = np.loadtxt('placas.dat')

V=datos[:,0]
Ex=datos[:,1]
Ey=datos[:,2]

V=np.reshape(V,(250,250))
Ex=np.reshape(Ex,(250,250))
Ey=np.reshape(Ey,(250,250))

x=np.linspace(0,5,250)
y=np.linspace(0,5,250)

x, y = np.meshgrid(x, y)

f , em = mp.subplots(2)
em[0].imshow(datos,interpolation='bicubic')
em[1].streamplot(x,y,Ex,Ey)
mp.savefig('placas.pdf')
