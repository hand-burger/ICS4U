# Factorial recursion

# Factorial of a number
def factorial(n):
    # Base case
    if n == 0:
        return 1
    # Recursive case
    else:
        return n * factorial(n-1)


print(factorial(5))
