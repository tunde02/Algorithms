# https://www.acmicpc.net/problem/2133

n = int(input())
d = [0] * 31

def answer(x):
    if x == 0:
        return 1
    if x == 1:
        return 0
    if x == 2:
        return 3

    if d[x] != 0:
        return d[x]

    d[x] = 3 * answer(x - 2)
    for i in range(3, x + 1):
        if i % 2 == 0:
            d[x] += 2 * answer(x - i)

    return d[x]

print(answer(n))
