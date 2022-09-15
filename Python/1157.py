d = {}
for i in range(26):
    d[chr(ord('A') + i)] = 0

word = input()

for spell in word:
    d[spell.upper()] += 1

max_cnt = max(d.values())

check = 0
for cnt in d.values():
    if max_cnt == cnt:
        check += 1

if check > 1:
    print('?')
else:
    print(max(d.keys(), key=(lambda k: d[k])))