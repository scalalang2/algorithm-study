# 색종이
import sys
N = int(sys.stdin.readline())

sol = 0
maps = []

for i in range(100):
    _map = []
    for j in range(100):
        _map.append(0)
    
    maps.append(_map)

for i in range(N):
    x, y = [int(x) for x in sys.stdin.readline().split()]

    for i in range(x, x + 10):
        for j in range(y, y + 10):
            maps[i][j] = 1

for i in range(100):
    for j in range(100):
        if maps[i][j] == 1:
            sol = sol + 1

print(sol)
