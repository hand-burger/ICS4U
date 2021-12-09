# Draw pentagon with turtle
import turtle


def draw_circle(t, length):
    """Draws a circle with the given turtle and length"""
    for i in range(18):
        t.forward(length)
        t.left(20)


def draw_octagon(t, length):
    """Draws an octagon with the given turtle and length"""
    for i in range(8):
        t.forward(length)
        t.left(45)


def draw_heptagon(t, length):
    """Draws a heptagon with the given turtle and length"""
    for i in range(7):
        t.forward(length)
        t.left(51.42)


def draw_hexagon(t, length):
    """Draws a hexagon with the given turtle and length"""
    for i in range(6):
        t.forward(length)
        t.left(60)


def draw_pentagon(t, length):
    """Draws a pentagon with the given turtle and length"""
    for i in range(5):
        t.forward(length)
        t.left(72)


def draw_square(t, length):
    """Draws a square with the given turtle and length"""
    for i in range(4):
        t.forward(length)
        t.left(90)


def draw_triangle(t, length):
    """Draws a triangle with the given turtle and length"""
    for i in range(3):
        t.forward(length)
        t.left(120)


def main():
    """Main function"""
    wn = turtle.Screen()
    wn.bgcolor("lightblue")

    # Create turtle
    tess = turtle.Turtle()
    tess.color("red")
    tess.pensize(3)

    # Draw circle
    draw_circle(tess, 50)

    # Draw octagon
    draw_octagon(tess, 50)

    # Draw heptagon
    draw_heptagon(tess, 50)

    # Draw hexagon
    draw_hexagon(tess, 50)

    # Draw pentagon
    draw_pentagon(tess, 50)

    # Draw square
    draw_square(tess, 50)

    # Draw triangle
    draw_triangle(tess, 50)

    wn.exitonclick()


if __name__ == "__main__":
    main()
