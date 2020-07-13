import math

nums = [int(x) for x in input().split()]
M = nums[0]
N = nums[1]

prime_numbers = []

for x in range(M, N+1):
    is_prime = True
    
    if x == 1: # 1은 소수가 아니다
        continue

    # 짝수 인 것 제외
    if x != 2 and x % 2 == 0:
        continue
    
    for i in range(2, int(math.sqrt(x))+1):
        if x % i == 0:
            is_prime = False
            break

    if is_prime :
        prime_numbers.append(x)

for x in prime_numbers:
    print(x)