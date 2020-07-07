import math

X = int(input())
bagsA = 5
bagsB = 3

sol = math.inf

for i in range(int(X / bagsA) + 1):
    if X - i * bagsA == 0:
        sol = min(sol, i)
        continue

    for j in range(int((X - i * bagsA) / bagsB)):
        if (X - i * bagsA) % bagsB == 0:
            _sol = i
            _sol = _sol + int((X - i * bagsA) / bagsB)
            sol = min(sol, _sol)

if sol == math.inf :
    print(-1)
else:
    print(sol)