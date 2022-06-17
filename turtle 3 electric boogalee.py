import turtle
size = 1
turtle.speed(0)
while(True):
    for _ in range(4):
        turtle.forward(size)
        turtle.right(90)
        size = size + 1
    turtle.right(10)