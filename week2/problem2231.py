# 분해 합
# 왜지?
import sys
N = int(sys.stdin.readline())
found = False

size = len(str(N))

for x in range(1, N):
    x = x
    sol = x
    remainder = x

    while remainder != 0:
        sol = sol + (remainder % 10)
        remainder = remainder // 10

    if sol == N:
        found = True
        print(x)
        break

if not found :
    print(0)