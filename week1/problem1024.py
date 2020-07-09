# t = (L-1) * L / 2
# x = (N - t)/L

nums = [int(x) for x in input().split()]
N = nums[0]
L = nums[1]
x = -1
iter = 0

for i in range(L, 100 + 1):
    t = ( (i - 1) * i ) / 2
    if (N - t) % i == 0 and (N - t) / i > 0:
        x = int((N-t) // i)
        iter = i
        break

if x == -1 :
    print(-1)
else:
    for i in range(x, x+iter):
        print(i)