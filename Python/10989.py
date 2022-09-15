# https://www.acmicpc.net/problem/10989

import sys
_input = sys.stdin.readline

num_dict = {x: 0 for x in range(1, 10001)}
N = int(_input())

for _ in range(N):
    num_dict[int(_input())] += 1

for i in range(1, 10001):
    for j in range(num_dict[i]):
        print(i)
