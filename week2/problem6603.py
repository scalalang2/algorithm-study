# 7 1 2 3 4 5 6 7
# 8 1 2 3 5 8 13 21 34
# 0

import sys

N = 6
nums = [int(x) for x in sys.stdin.readline().split()]
K = nums[0]
nums = nums[1:]

def pick_n(current_length, arr, series=''):
    if len(arr) < K:
        pass

    if current_length == N:
        print(series)
    else:
        for index, x in enumerate(arr):
            pick_n(current_length+1, arr[index+1:], series + str(x) + ' ')
        

while K != 0:
    pick_n(0, nums)
    print()

    nums = [int(x) for x in sys.stdin.readline().split()]
    K = nums[0]
    nums = nums[1:]