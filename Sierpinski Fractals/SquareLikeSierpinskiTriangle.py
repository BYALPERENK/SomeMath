import random
from matplotlib import pyplot as plt

outerPoints=[[0,0],[1,0],[1,1],[0,1]]
interiorPoints=[]

HOW_MANY_POINTS=10000
FIRST_COEFFICIENT=2
SECOND_COEFFICIENT=1
total_c=FIRST_COEFFICIENT+SECOND_COEFFICIENT

def first_dot(outerP):
    x_max,x_min=max([outerP[0][0],outerP[1][0],outerP[2][0],outerP[3][0]]),min([outerP[0][0],outerP[1][0],outerP[2][0],outerP[3][0]])
    y_max,y_min=max([outerP[0][1],outerP[1][1],outerP[2][1],outerP[3][1]]),min([outerP[0][1],outerP[1][1],outerP[2][1],outerP[3][1]])
    x=random.uniform(x_min, x_max)
    y=random.uniform(y_min, y_max)
    return [x,y]

def random_dot(outerP,innerP):
    a=random.choice(outerP)
    b=random.choice(innerP)
    c=[(FIRST_COEFFICIENT*a[0]+SECOND_COEFFICIENT*b[0])/total_c,(FIRST_COEFFICIENT*a[1]+SECOND_COEFFICIENT*b[1])/total_c]
    return c

interiorPoints.append(first_dot(outerPoints))

for i in range(HOW_MANY_POINTS):
    interiorPoints.append(random_dot(outerPoints,interiorPoints))

x, y = zip(*interiorPoints)
plt.scatter(x,y)
plt.xlabel("X")
plt.ylabel("Y")
plt.xlim(0, 1)
plt.ylim(0, 1)
plt.show()

