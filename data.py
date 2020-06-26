import matplotlib.pyplot as plt

x = []
y = []

with open('results.csv') as f:
    for line in f.readlines():
        line = line.split(',')
        x.append(float(line[0]))
        y.append(float(line[1]))

plt.plot(x, y)
plt.axis([0,80,0,5])

plt.axes().set_aspect('equal')
plt.show()
