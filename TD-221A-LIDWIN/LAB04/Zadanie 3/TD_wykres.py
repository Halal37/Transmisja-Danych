import matplotlib.pyplot as plt
A=[]
with open("./danez2.txt","r") as plik:
 linia=plik.readlines()
 for i in linia:
  A.append([i.split(";")])
x=[float(i[0][0])for i in A]
y=[float(i[0][1])for i in A]
plt.plot(x,y, color='red')
plt.title("Lab_2_z_9 M: ")
plt.ylabel("A")
plt.xlabel("f[Hz]")
plt.show()
