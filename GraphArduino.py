
# coding: utf-8

# In[1]:

import matplotlib.pyplot as plt
import serial
import time 
import numpy as np
get_ipython().magic('matplotlib inline')



# In[2]:

ser = serial.Serial('COM3', 9600)
######## Definitions
sr=200.; #in hertz			Change here
total_time=3.; #in seconds
buton_list = []
volume_list = []


# In[3]:


#########
period = 1/sr;
n_period = total_time/period

print(period )

print(n_period)


# In[4]:

timevec = np.array(range(int(n_period)))*period


# In[5]:

#######

t_ini = time.time()
for i in range(int(n_period)):
    tic=time.time();
    ser.write(b'0')
    frase = ser.readline()
    #buton_list += [500*int(frase.split()[0])]
    #volume_list += [int(frase.split()[1])] 
    delay = time.time()-tic
    print(delay)
    #time.sleep(period-delay)

    
plt.plot(timevec, volume_list, label = 'volume', linewidth=2)
plt.plot(timevec,buton_list, label = 'botao',linewidth=2)
plt.legend()
plt.show()


# In[ ]:

buton_list


# In[ ]:



