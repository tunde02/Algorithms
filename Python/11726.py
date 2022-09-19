# https://www.acmicpc.net/problem/11726

import sys
sys.setrecursionlimit(10000)

n = int(input())
d = [0] * (n + 1)

def answer(x):
    if x == 1:
        return 1
    if x == 2:
        return 2
    if d[x] != 0:
        return d[x]

    d[x] = answer(x - 1) + answer(x - 2)
    return d[x]

print(answer(n) % 10007)
