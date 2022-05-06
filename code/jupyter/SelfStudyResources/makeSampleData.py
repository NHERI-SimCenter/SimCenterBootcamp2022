from numpy import sin, cos, pi, array, linspace

th = linspace(0,10*pi,500)
x = (1+0.1*th)*cos(th)
y = (1+0.1*th)*sin(th)

f = open('ExampleData.txt','w')
for (u,v) in zip(x,y):
    f.write("{},{},\n".format(u,v))
f.close()


