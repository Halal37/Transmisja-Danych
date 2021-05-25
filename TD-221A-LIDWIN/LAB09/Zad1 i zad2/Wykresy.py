import matplotlib.pyplot as plt
import math
import numpy as np


#ASK
A=[]
with open("./dane1.txt","r") as plik:
 linia=plik.readlines()
 for i in linia:
  A.append([i.split(";")])
x=[float(i[0][0])for i in A]
y=[float(i[0][1])for i in A]
plt.plot(x,y, color='red')
plt.title("Lab_9_z_a: ")
plt.ylabel("A")
plt.xlabel("t(s)")
plt.show()

B=[]
with open("./dane4.txt","r") as plik:
 linia=plik.readlines()
 for i in linia:
  B.append([i.split(";")])
x1=[float(i[0][0])for i in B]
y1=[float(i[0][1])for i in B]
plt.plot(x1,y1, color='red')
plt.title("Lab_9_x_a: ")
plt.ylabel("x(t)")
plt.xlabel("t(s)")
plt.show()

C=[]
with open("./d_pa.txt","r") as plik:
 linia=plik.readlines()
 for i in linia:
  C.append([i.split(";")])
x2=[float(i[0][0])for i in C]
y2=[float(i[0][1])for i in C]
plt.plot(x2,y2, color='red')
plt.title("Lab_9_p_a: ")
plt.ylabel("p(t)")
plt.xlabel("t(s)")
plt.show()


D=[]
with open("./d_ca.txt","r") as plik:
 linia=plik.readlines()
 for i in linia:
  D.append([i.split(";")])
x3=[float(i[0][0])for i in D]
y3=[float(i[0][1])for i in D]
plt.plot(x3,y3, color='red')
plt.title("Lab_9_c_a: ")
plt.ylabel("c(t)")
plt.xlabel("t(s)")
plt.show()

#PSK
E=[]
with open("./dane2.txt","r") as plik:
 linia=plik.readlines()
 for i in linia:
  E.append([i.split(";")])
x4=[float(i[0][0])for i in E]
y4=[float(i[0][1])for i in E]
plt.plot(x4,y4, color='red')
plt.title("Lab_9_z_p: ")
plt.ylabel("A")
plt.xlabel("t(s)")
plt.show()



F=[]
with open("./dane5.txt","r") as plik:
 linia=plik.readlines()
 for i in linia:
  F.append([i.split(";")])
x5=[float(i[0][0])for i in F]
y5=[float(i[0][1])for i in F]
plt.plot(x5,y5, color='red')
plt.title("Lab_9_x_p: ")
plt.ylabel("x(t)")
plt.xlabel("t(s)")
plt.show()


G=[]
with open("./d_pp.txt","r") as plik:
 linia=plik.readlines()
 for i in linia:
  G.append([i.split(";")])
x6=[float(i[0][0])for i in G]
y6=[float(i[0][1])for i in G]
plt.plot(x6,y6, color='red')
plt.title("Lab_9_p_p: ")
plt.ylabel("p(t)")
plt.xlabel("t(s)")
plt.show()


H=[]
with open("./d_cp.txt","r") as plik:
 linia=plik.readlines()
 for i in linia:
  H.append([i.split(";")])
x7=[float(i[0][0])for i in H]
y7=[float(i[0][1])for i in H]
plt.plot(x7,y7, color='red')
plt.title("Lab_9_c_p: ")
plt.ylabel("c(t)")
plt.xlabel("t(s)")
plt.show()


#FSK
I=[]
with open("./dane3.txt","r") as plik:
 linia=plik.readlines()
 for i in linia:
  I.append([i.split(";")])
x8=[float(i[0][0])for i in I]
y8=[float(i[0][1])for i in I]
plt.plot(x8,y8, color='red')
plt.title("Lab_9_z_f: ")
plt.ylabel("A")
plt.xlabel("t(s)")
plt.show()


J=[]
with open("./dane6.txt","r") as plik:
 linia=plik.readlines()
 for i in linia:
  J.append([i.split(";")])
x9=[float(i[0][0])for i in J]
y9=[float(i[0][1])for i in J]
plt.plot(x9,y9, color='red')
plt.title("Lab_9_x1_f: ")
plt.ylabel("x1(t)")
plt.xlabel("t(s)")
plt.show()


K=[]
with open("./dane7.txt","r") as plik:
 linia=plik.readlines()
 for i in linia:
  K.append([i.split(";")])
x10=[float(i[0][0])for i in K]
y10=[float(i[0][1])for i in K]
plt.plot(x10,y10, color='red')
plt.title("Lab_9_x2_f: ")
plt.ylabel("x2(t)")
plt.xlabel("t(s)")
plt.show()


L=[]
with open("./d_pf1.txt","r") as plik:
 linia=plik.readlines()
 for i in linia:
  L.append([i.split(";")])
x11=[float(i[0][0])for i in L]
y11=[float(i[0][1])for i in L]
plt.plot(x11,y11, color='red')
plt.title("Lab_9_p1_f: ")
plt.ylabel("p1(t)")
plt.xlabel("t(s)")
plt.show()


M=[]
with open("./d_pf2.txt","r") as plik:
 linia=plik.readlines()
 for i in linia:
  M.append([i.split(";")])
x12=[float(i[0][0])for i in M]
y12=[float(i[0][1])for i in M]
plt.plot(x12,y12, color='red')
plt.title("Lab_9_p2_f: ")
plt.ylabel("p2(t)")
plt.xlabel("t(s)")
plt.show()


M_d=[]
with open("./d_pf.txt","r") as plik:
 linia=plik.readlines()
 for i in linia:
  M_d.append([i.split(";")])
x12_d=[float(i[0][0])for i in M_d]
y12_d=[float(i[0][1])for i in M_d]
plt.plot(x12_d,y12_d, color='red')
plt.title("Lab_9_p2_f: ")
plt.ylabel("p(t)")
plt.xlabel("t(s)")
plt.show()

N=[]
with open("./d_cf.txt","r") as plik:
 linia=plik.readlines()
 for i in linia:
  N.append([i.split(";")])
x13=[float(i[0][0])for i in N]
y13=[float(i[0][1])for i in N]
plt.plot(x13,y13, color='red')
plt.title("Lab_9_c_f: ")
plt.ylabel("c(t)")
plt.xlabel("t(s)")
plt.show()
