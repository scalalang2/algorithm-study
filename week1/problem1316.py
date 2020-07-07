N = int(input())
sol = N

for i in range(N):
    word = input()
    word_list = {}

    for j in range(len(word)):
        if word[j] in word_list and word[j-1] != word[j]:
            sol -= 1
            break
        elif word[j] not in word_list:
            word_list[word[j]] = 0

print(sol)