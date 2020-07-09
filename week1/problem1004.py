# 문제: 어린왕자
# - 풀이 : 두 점이 원안에 포함관계인지 조사한다.
import math

def distance(x1, y1, x2, y2):
    return math.sqrt(((x2 - x1) ** 2 + (y2 - y1) ** 2))

T = int(input())
for i in range(T):
    sol = 0
    nums = [int(x) for x in input().split()]
    x1, y1, x2, y2 = nums[0], nums[1], nums[2], nums[3]
    number_of_circles = int(input())

    # 원을 입력 받는다.
    for j in range(number_of_circles):
        nums = [int(x) for x in input().split()]
        x, y, r = nums[0], nums[1], nums[2]
        d1 = distance(x1, y1, x, y)
        d2 = distance(x2, y2, x, y)

        if d1 < r and d2 < r:
            continue
        elif d1 < r or d2 < r:
            sol = sol + 1
    
    print(sol)