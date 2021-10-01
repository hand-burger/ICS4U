import math

print('Enter cubic coefficients: ', end='')
coefficients = list(map(int, input().split()))
print(str(coefficients[0]) + 'x^3+(' + str(coefficients[1]) +
      ')x^2+(' + str(coefficients[2]) + ')x+(' + str(coefficients[3]) + ')')

# Get p and q, then p/q list


def factorize(num):
    return [n for n in range(1, num + 1) if num % n == 0]


q_factors = factorize(coefficients[0])
p_factors = factorize(coefficients[3])

if p_factors == []:
    p_factors = [1]
if q_factors == []:
    q_factors == [1]


p_over_qs = [None]

# Now looping over each thing to get p/q


for j in range(len(p_factors)):
    for k in range(len(q_factors)):
        p_over_qs.append(p_factors[j]/q_factors[k])

for i in p_factors:
    p_over_qs.append(i)
p_over_qs.pop(0)

# Alright now we got the p/qs, now test 'em, but first add the negatives

for i in range(len(p_over_qs)):
    p_over_qs.append(p_over_qs[i] * -1)


for i in p_over_qs:
    if (coefficients[0] * i * i * i)+(coefficients[1] * i * i)+(coefficients[2] * i) + (coefficients[3]) == 0:
        print('First root found:', i)
        # Now synthetic division for quadratic

        synthetic1 = coefficients[0]
        synthetic2 = synthetic1 * i + coefficients[1]
        synthetic3 = synthetic2 * i + coefficients[2]
        synthetic4 = synthetic3 * i + coefficients[3]

        # Now quadratic equation for the quadratic

        print(str(synthetic1) + 'x^2+(' + str(synthetic2) +
              ')x+(' + str(synthetic3) + ')')

        d = synthetic2**2-4*synthetic1*synthetic3  # discriminant

        if d < 0:
            print("This quadratic has no real solution")
        elif d == 0:
            x = (-synthetic2 + math.sqrt(synthetic2**2 - 4 *
                 synthetic1*synthetic3)) / (2 * synthetic1)
            print("This quadratic has one solutions: ", x)
        else:
            x1 = (-synthetic2 + math.sqrt(synthetic2**2 - 4 *
                  synthetic1*synthetic3)) / (2 * synthetic1)
            x2 = (-synthetic2 - math.sqrt(synthetic2**2 - 4 *
                  synthetic1*synthetic3)) / (2 * synthetic1)
            print("This quadratic has two solutions: ", x1, " and", x2)

        print('The roots are ' + str(x1) + ', ' + str(x2) + ', ' + str(i))

        break
