d = {}
num = 2
for i in range(0, 22, 3):
    d[chr(ord('A') + i)] = num
    d[chr(ord('A') + i + 1)] = num
    d[chr(ord('A') + i + 2)] = num
    num += 1

d['S'] = 7
d['V'] = 8
d['Y'] = 9
d['Z'] = 9

word = input()

sum = 0
for spell in word:
    sum += d[spell]

print(sum + len(word))