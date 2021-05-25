import matplotlib.pyplot as plt

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
with open("./dane1a.txt","r") as plik:
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

C=[]
with open("./dane2a.txt","r") as plik:
 linia=plik.readlines()
 for i in linia:
  C.append([i.split(";")])
x2=[float(i[0][0])for i in C]
y2=[float(i[0][1])for i in C]
plt.plot(x1,y1, color='red')
plt.title("Lab_7_PSK: ")
plt.ylabel("A")
plt.xlabel("t[s]")
plt.show()

D=[]
with open("./dane3a.txt","r") as plik:
 linia=plik.readlines()
 for i in linia:
  C.append([i.split(";")])
x3=[float(i[0][0])for i in D]
y3=[float(i[0][1])for i in D]
plt.plot(x1,y1, color='red')
plt.title("Lab_7_FSK: ")
plt.ylabel("A")
plt.xlabel("t[s]")
plt.show()