import numpy as np
import matplotlib.pyplot as mp
import os

datos=np.loadtxt('cuerda.dat')

datos=np.split(datos,1000)

datos=np.array(datos)

for i in range(200):
    mp.figure(i)
    mp.plot(np.linspace(0,100,1000),datos[:,i])
    mp.xticks(())
    mp.yticks(())
    mp.xlim(0,100)
    mp.ylim(-1,1)
    mp.savefig(str(i).zfill(3) + ".png")
    mp.close()

os.system("convert -delay 1 -loop 0 *.png cuerda.gif")
