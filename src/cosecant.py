# Cosecant calculator

import math


def cosecant(x):
    """
    Calculates the cosecant of x
    x: float or int
    returns: float
    """
    return 1/math.sin(x)


print(cosecant(1))
