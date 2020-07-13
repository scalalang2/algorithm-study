import sys

lst = {'a': 1, 'e':1, 'i':1, 'o':1, 'u':1}
N, M = [int(x) for x in sys.stdin.readline().split()]
given_words = sys.stdin.readline().split()
given_words = sorted(given_words)

# vowel: 모음
# consonant: 자음
def f(words, vowel_count, consonant_count, word=''):
    if len(word) == N:
        if vowel_count > 0 and consonant_count > 1:
            print(word)
    else:
        for index, x in enumerate(words):
            if x in lst:
                f(words[index+1:], vowel_count+1, consonant_count, word+x)
            else:
                f(words[index+1:], vowel_count, consonant_count+1, word+x)

f(given_words, 0, 0)