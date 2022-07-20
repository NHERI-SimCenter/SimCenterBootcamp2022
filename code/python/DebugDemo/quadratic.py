# import math functions
import math

# defining the solver function
def quadratic(a, b, c):
    p = -b / 2. / a
    q = math.sqrt(b * b - 4 * a * c) / 2. / a

    x1 = p + q
    x2 = p - q

    return (x1, x2)

# demo the function
sol = quadratic(1., 2., 3.)
print("sol = ", *sol)