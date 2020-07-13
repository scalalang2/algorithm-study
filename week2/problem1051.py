import sys

ROW, COLUMN = [int(x) for x in sys.stdin.readline().split()]

matrix = []
for i in range(ROW):
    txt = input()
    rows = []
    for x in txt:
        rows.append(int(x))
    
    matrix.append(rows)

sol = 1

for x in range(ROW):
    for i in range(COLUMN-1):
        start = matrix[x][i]
        for j in range(i+1, COLUMN):
            end = matrix[x][j]
            if start == end:
                diff = j-i
                if x+diff >= ROW:
                    continue

                if start == matrix[x+diff][i] and start == matrix[x+diff][j]:
                    current_max = (diff+1) * (j-i+1)
                    sol = max(sol, current_max)

print(sol)