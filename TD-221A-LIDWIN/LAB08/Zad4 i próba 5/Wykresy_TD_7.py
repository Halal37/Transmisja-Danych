import matplotlib.pyplot as plt
import numpy as np
import math

A=[]
with open("./dane.txt","r") as plik:
 linia=plik.readlines()
 for i in linia:
  A.append([i.split(";")])
x=[float(i[0][0])for i in A]
y=[float(i[0][1])for i in A]
plt.plot(x,y, color='red')
plt.title("Lab_7_S_B: ")
plt.ylabel("A")
plt.xlabel("t[s]")
plt.show()

B=[]
with open("./dane1.txt","r") as plik:
 linia=plik.readlines()
 for i in linia:
  B.append([i.split(";")])
x1=[float(i[0][0])for i in B]
y1=[float(i[0][1])for i in B]
plt.plot(x1,y1, color='red')
plt.title("Lab_7_ASK: ")
plt.ylabel("A")
plt.xlabel("t[s]")
plt.show()

Tb = 1.0/700.0
Tc = 14.0 * Tb
fs = 250000
Ts = 1 / fs
N = math.ceil(Tc / Ts)

xd=[0 for i in B]
yd=[0 for i in B]
do_wykresu1 = np.fft.fft(y1)
es=0
for i in do_wykresu1:
        yd[es]=math.sqrt((i.real*i.real)+(i.imag*i.imag))
        yd[es] = math.log10(abs(yd[es] )) * 10
        xd[es]=es*fs/N
        es=es+1

plt.plot(xd, yd,color='red')
plt.ylabel("M'za(k)")
plt.xlabel("f[Hz]")
plt.show()

C=[]
with open("./dane2.txt","r") as plik:
 linia=plik.readlines()
 for i in linia:
  C.append([i.split(";")])
x2=[float(i[0][0])for i in C]
y2=[float(i[0][1])for i in C]
plt.plot(x2,y2, color='red')
plt.title("Lab_7_PSK: ")
plt.ylabel("A")
plt.xlabel("t[s]")
plt.show()

yd1=[0 for i in C]
do_wykresu2 = np.fft.fft(y2)
es=0
for i in do_wykresu2:
        yd1[es]= math.sqrt((i.real*i.real)+(i.imag*i.imag))
        yd1[es] = math.log10(abs(yd1[es] )) * 10
        es=es+1
plt.plot(xd, yd1,color='red')
plt.ylabel("M'zp(k)")
plt.xlabel("f[Hz]")
plt.show()


D=[]
with open("./dane3.txt","r") as plik:
 linia=plik.readlines()
 for i in linia:
  D.append([i.split(";")])
x3=[float(i[0][0])for i in D]
y3=[float(i[0][1])for i in D]
plt.plot(x3,y3, color='red')
plt.title("Lab_7_FSK: ")
plt.ylabel("A")
plt.xlabel("t[s]")
plt.show()

yd2=[0 for i in D]
do_wykresu3 = np.fft.fft(y3)
es=0
for i in do_wykresu3:
        yd2[es]= math.sqrt((i.real*i.real)+(i.imag*i.imag))
        yd2[es] = math.log10(abs(yd2[es] )) * 10
        es=es+1
plt.plot(xd, yd2,color='red')
plt.ylabel("M'zf(k)")
plt.xlabel("f[Hz]")
plt.show()

#4
def szerokosc(x,y,B):
 max=x[0]
 for i in range(len(y)):
     if(y[i]>max):
         max=y[i]
         max_int=i
 print("Maks: ", max ," max_int: " , max_int )
 print()
 f_min=0
 f_max=0
 war= B
 for i in range(0,len(y)-max_int,2):
     if(y[i]<(max-war)):
         f_max=i-1
         break
     else:
         f_max=i
 for i in range(max_int,0,-2):
     if(y[i]<(max-war)):
         f_min=i+1
         break
     else:
         f_min=i
 print("FKMaks: ", x[f_max] ," FKMin: " , x[f_min] )
 print()
 print(B ,"dB " , abs(x[f_max]-x[f_min]) )
 print()
 #for i in range(len())
szerokosc(xd,yd,3)
szerokosc(xd,yd,6)
szerokosc(xd,yd,12)
szerokosc(xd,yd1,3)
szerokosc(xd,yd1,6)
szerokosc(xd,yd1,12)
szerokosc(xd,yd2,3)
szerokosc(xd,yd2,6)
szerokosc(xd,yd2,12)