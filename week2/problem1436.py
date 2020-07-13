import sys
N = int(sys.stdin.readline())

cnt = 0
start = 666

while cnt != N:
    count = 0
    mid = start

    while mid != 0:
        if mid % 10 == 6:
            count = count + 1
        else:
            count = 0
        
        mid = mid // 10
        
        if count >= 3:
            cnt += 1
            mid = 0
    
    start = start + 1

print(start-1)