import sys
read = sys.stdin.readline


N = int(read().rstrip())
cnt = 0

for _ in range(N):
    word = read().rstrip()
    temp = [word[0]]
    check = True

    for i in range(1, len(word)):
        if word[i] in temp and word[i - 1] != word[i]:
            check = False
            break

        temp.append(word[i])

    if check:
        cnt += 1

print(cnt)