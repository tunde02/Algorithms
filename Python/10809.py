d = {}
for i in range(26):
    d[chr(ord('a') + i)] = -1

word = input()

for i in range(len(word)):
    if d[word[i]] == -1:
        d[word[i]] = i

print(*d.values())