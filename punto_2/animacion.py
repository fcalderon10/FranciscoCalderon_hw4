import numpy as np
import matplotlib.pyplot as mp
import os

datos = np.loadtxt('cuerda.dat')

x=np.linspace(0,100,500)

datos=np.split(datos,180)

datos=np.array(datos)

for i in range(180):
    mp.figure(i)
    mp.plot(x,datos[i,:])
    mp.xticks(())
    mp.yticks(())
    mp.xlim(0,100)
    mp.ylim(-1,1)
    mp.savefig(str(i).zfill(3) + ".png")
    mp.close()

os.system("convert -delay 1 -loop 0 *.png cuerda.gif")
