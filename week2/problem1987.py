import sys

R, C = [int(x) for x in sys.stdin.readline().split()]
maps = []
hist = [0] * 26
sol = 1

for r in range(R):
    text = input()
    maps.append(text)

def f(i, j, cnt=1):
    global sol

    for k in range(4):
        next_i = i
        next_j = j

        if k == 0 :
            next_j = j+1
        elif k == 1:
            next_i = i+1
        elif k == 2:
            next_i = i-1
        else:
            next_j = j-1
        
        if next_i >= 0 and next_i < R and next_j >= 0 and next_j < C:
            _chr = ord(maps[next_i][next_j]) - 65
            if hist[_chr] != 1:
                print(next_i, next_j, _chr, hist)
                hist[_chr] = 1
                f(next_i, next_j, cnt + 1)
                hist[_chr] = 0

    sol = max(sol, cnt)

_chr = ord(maps[0][0]) - 65
hist[_chr] = 1
f(0, 0, 1)
print(sol)