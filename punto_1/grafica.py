import numpy as np
import matplotlib.pyplot as mp
import matplotlib.cm as cm

datos = np.loadtxt('placas.dat')

V=datos[:,0]
Ex=datos[:,1]
Ey=datos[:,2]

V=np.split(V,250)
Ex=np.split(Ex,250)
Ey=np.split(Ey,250)

V=np.array(V)
Ex=np.array(Ex)
Ey=np.array(Ey)

x=np.linspace(0,250,250)
y=np.linspace(0,250,250)

x, y = np.meshgrid(x, y)

mp.figure()
mp.imshow(V)
mp.streamplot(x,y,Ex,Ey)
mp.xlim(0,250)
mp.ylim(250,0)
mp.savefig('placas.pdf')
