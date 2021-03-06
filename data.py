import matplotlib.pyplot as plt
import sys

x = []
y = []
labels=['3m/s headwind', '3m/s tailwind']

# load data from file
with open('results.dat', 'r') as f:
    for (i, line) in enumerate(f.readlines()):
        line = line.split(',')
        line.pop()

        for (k, data) in enumerate(line):
            line[k] = float(data)

        if i % 2 == 0:
            x.append(line)
        else:
            y.append(line)


# plot all simulations on same axis
for (i, sim) in enumerate(x):
    plt.plot(x[i], y[i], label=labels[i])



plt.axes().set_aspect('equal')
plt.xlabel('displacement, m')
plt.ylabel('height, m')
plt.title('Flight Path of BB with Head/Tail Wind')

axes = plt.gca()


plt.legend(bbox_to_anchor=(1.0, 1.225))
plt.tight_layout()
plt.show()
