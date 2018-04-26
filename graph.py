import numpy as np
import matplotlib.pyplot as plt
data = np.loadtxt('datos.txt')
plt.figure()
plt.plot(data[:,0] , data[:,1])
plt.savefig('onda.png')
plt.show()

