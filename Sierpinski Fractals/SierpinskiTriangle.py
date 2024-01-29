import random
from matplotlib import pyplot as plt

HOW_MANY_POINTS=10000

outerPoints=[[0,0],[1,0],[0.5,(3/4)**(1/2)]]
interiorPoints=[]

def random_point_in_triangle(A, B, C):
    r, s = random.random(), random.random()
    if r + s > 1:
        r, s = 1 - r, 1 - s
    P = [(1 - r - s) * A[0] + r * B[0] + s * C[0], 
         (1 - r - s) * A[1] + r * B[1] + s * C[1]]
    return P

def rastgele_dot(outerP,innerP):
    a=random.choice(outerP)
    b=random.choice(innerP)
    c=[(a[0]+b[0])/2,(a[1]+b[1])/2]
    return c

interiorPoints.append(random_point_in_triangle(outerPoints[0],outerPoints[1],outerPoints[2]))

for i in range(HOW_MANY_POINTS):
    interiorPoints.append(rastgele_dot(outerPoints,interiorPoints))

x, y = zip(*interiorPoints)
plt.scatter(x,y)
plt.xlabel("X")
plt.ylabel("Y")
plt.xlim(0, 1)
plt.ylim(0, 1)
plt.show()
