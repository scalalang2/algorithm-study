import sys

N,M = [int(x) for x in sys.stdin.readline().split()]

def f(current_length, series='', prev=0):
    if current_length != M:
        for x in range(prev, N):
            f(current_length + 1, series + str(x+1) + ' ', x+1)
    else:
        print(series)

f(0)