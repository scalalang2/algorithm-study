# Complexity : 10^6 * 3 <= 10^7
# 왜?
import sys
nums = sys.stdin.readline()
M, N = [int(x) for x in nums.split()]
result = []
p_sum = []
solutions = []

for i in range(M):
    nums = sys.stdin.readline()
    nums = [int(x) for x in nums.split()]
    _result = []
    for el in nums:
        _result.append(el)
    
    result.append(_result)

for i in range(M+1):
    sol = []
    for j in range(N+1):
        sol.append(0)

    p_sum.append(sol)

# 계산이 복잡하다면!
# 의미없는 0을 써라
for i in range(1, M + 1):
    for j in range(1, N + 1):
        p_sum[i][j] = p_sum[i-1][j] + p_sum[i][j-1] - p_sum[i-1][j-1] + result[i-1][j-1]

K = int(sys.stdin.readline())
for k in range(K):
    # [[0, 0, 0, 0], [0, 1, 3, 7], [0, 9, 27, 63]]
    i, j, x, y = [int(x) for x in sys.stdin.readline().split()]
    sol = p_sum[x][y] - p_sum[i-1][y] - p_sum[x][j-1] + p_sum[i-1][j-1]
    print(sol)
