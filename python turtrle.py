import turtle
import time
import random



turtle.bgcolor('red')
turtle.speed(0)
turtle.color('black')
turtle.pen(pencolor='black', pensize=10)



turtle.penup()
turtle.goto(0,300)
turtle.pendown()
for _ in range(45):
    turtle.forward(5)
    turtle.right(2)

turtle.penup()
turtle.goto(0,300)
turtle.pendown()
turtle.setheading(180)
for _ in range(45):
    turtle.forward(5)
    turtle.left(2)


turtle.penup()
turtle.goto(145.72490407689898, 159.27509592310105)
turtle.setheading(270)
turtle.pendown()
turtle.forward(250)
turtle.penup()

turtle.goto(-145.72490407689898, 159.27509592310105)
turtle.setheading(180)
turtle.pendown()
for _ in range (90):
    turtle.forward(2)
    turtle.left(2)
#print(turtle.xcor(), turtle.ycor())
turtle.forward(75)

for _ in range(90):
    turtle.forward(2)
    turtle.left(2)
    
turtle.forward(75)
turtle.penup()
turtle.goto(-147.72490407689892, 44.69517266158143)
turtle.pendown()
turtle.setheading(270)
turtle.forward(130)
#print(turtle.xcor(), turtle.ycor())
turtle.penup()

turtle.goto(20, -125.30482733842013)

turtle.pendown()

turtle.setheading(90)


for _ in range(89):
    turtle.forward(1)
    turtle.left(2)


for _ in range(90):
    turtle.forward(1.9)
    turtle.right(2)

turtle.forward(20)