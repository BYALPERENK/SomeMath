import random
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

HOW_MANY_POINTS = 10000

# Outer points of Tetrahedron
outerPoints = [[0, 0, 0], [1, 0, 0], [0.5, (3**0.5) / 2, 0], [0.5, (3**0.5) / 6, (2 / 3)**0.5]]

interiorPoints = []

def random_point_in_tetrahedron(A, B, C, D):
    r, s, t = random.random(), random.random(), random.random()
    if r + s > 1:
        r, s = 1 - r, 1 - s
    if r + s + t > 1:
        t = 1 - r - s
    P = [(1 - r - s - t) * A[0] + r * B[0] + s * C[0] + t * D[0], 
         (1 - r - s - t) * A[1] + r * B[1] + s * C[1] + t * D[1],
         (1 - r - s - t) * A[2] + r * B[2] + s * C[2] + t * D[2]]
    return P

def random_dot(outerP, innerP):
    a = random.choice(outerP)
    b = random.choice(innerP)
    c = [(a[0] + b[0]) / 2, (a[1] + b[1]) / 2, (a[2] + b[2]) / 2]
    return c

# First point
interiorPoints.append(random_point_in_tetrahedron(outerPoints[0], outerPoints[1], outerPoints[2], outerPoints[3]))

for i in range(HOW_MANY_POINTS):
    interiorPoints.append(random_dot(outerPoints, interiorPoints))

x, y, z = zip(*interiorPoints)

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ax.scatter(x, y, z)
ax.set_xlabel('X Axis')
ax.set_ylabel('Y Axis')
ax.set_zlabel('Z Axis')
plt.show()
