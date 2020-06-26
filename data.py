import matplotlib.pyplot as plt
import sys

x1 = []
y1 = []
x2 = []
y2 = []
x3 = []
y3 = []

with open(sys.argv[1]) as f:
    for line in f.readlines():
        line = line.split(',')
        x1.append(float(line[0]))
        y1.append(float(line[1]))

with open(sys.argv[2]) as f:
    for line in f.readlines():
        line = line.split(',')
        x2.append(float(line[0]))
        y2.append(float(line[1]))

with open(sys.argv[3]) as f:
    for line in f.readlines():
        line = line.split(',')
        x3.append(float(line[0]))
        y3.append(float(line[1]))



plt.plot(x1, y1, label='0.20')
plt.plot(x2, y2, label='0.30')
plt.plot(x3, y3, label='0.40')
plt.legend()
plt.axis([0, 80, 0, 4])
plt.axes().set_aspect('equal')
plt.show()
