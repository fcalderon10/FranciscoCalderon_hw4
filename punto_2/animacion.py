import numpy as np
import matplotlib.pyplot as mp
import os

datos=np.loadtxt('cuerda.dat')

for i in range(len(datos[:,0])):
    mp.figure(i)
    mp.plot(np.linspace(0,100,1000),datos[:,i])
    mp.xticks(())
    mp.yticks(())
    mp.xlim(0,100)
    mp.ylim(-1,1)
    mp.savefig(str(i).zfill(3) + ".png")
    mp.close()

os.system("convert -delay 1 -loop 0 *.png cuerda.gif")

mp.figure()
mp.plot(np.linspace(0,100,1000),datos)
mp.show()
