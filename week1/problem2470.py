import math

N = int(input())
numbers = sorted([int(x) for x in input().split()])

solA = 0
solB = 0
close_to_zero = math.inf

i = 0
j = len(numbers) - 1

while i < j :
    _sum = abs(numbers[i] + numbers[j])
    if _sum < close_to_zero:
        close_to_zero = _sum
        solA = numbers[i]
        solB = numbers[j]

    if numbers[i] + numbers[j] < 0 :
        i += 1
    else:
        j -= 1

print("{} {}".format(solA, solB))