N = int(input())
arr = []

for i in range(N):
    num = int(input())
    arr.append(num)

result = sorted(arr)
for x in result:
    print(x)