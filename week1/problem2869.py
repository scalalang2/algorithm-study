nums = [int(x) for x in input().split()]
A = nums[0]
B = nums[1]
V = nums[2]

sol = int(((V-A) / (A - B)))+1

if (V-A) % (A-B) != 0:
    sol += 1

print(sol)