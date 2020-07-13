import sys
N = int(sys.stdin.readline())
result = []
groups = []

# O(n)
def is_equal(arr1, arr2):
    equal = True
    for i in range(len(arr1)):
        if arr1[i] != arr2[i] :
            equal = False
    
    return equal

for x in range(N):
    arr = [int(x) for x in sys.stdin.readline().split()]

    if len(result) == 0:
        # Init
        result.append(arr)
        groups.append([x+1])
    else:
        found = False

        for index, el in enumerate(result):
            if is_equal(arr, el):
                found = True
                groups[index].append(x+1)
                break

        if not found:
            result.append(arr)
            groups.append([x+1])
            
is_stable = True

# check is stable
for x in groups:
    if len(x) == 1:
        is_stable = False
        break

for i in range(len(result)):
    for j in range(len(result)):
        if i == j:
            continue
    
        for k in range(len(result[i])):
            if result[i][k] == result[j][k]:
                is_stable = False
                break

if is_stable:
    print(len(groups))
    for el in groups:
        txt = ''
        for a in el:
            txt = txt + str(a) + ' '

        print(txt)
else:
    print(0)