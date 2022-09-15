"""
메모이제이션을 위한 저장공간 dp를 딕셔너리로 선언하여 나올 수 있는 무게조합에 대해서만
기억하여 저장공간의 낭비를 줄였다
"""

import sys


N, K = map(int, sys.stdin.readline().split())
W, V = [0 for i in range(N)], [0 for i in range(N)]
dp = {0: 0}
for i in range(N):
    W[i], V[i] = map(int, sys.stdin.readline().split())

for i in range(0, N):
    temp = {}
    for weight in dp.keys():
        if weight + W[i] <= K and dp[weight] + V[i] > dp.get(weight + W[i], 0):
            temp[weight + W[i]] = dp[weight] + V[i]
    dp.update(temp) # for문 안에선 딕셔너리 추가가 되지 않기 때문에 temp와 dp.update()를 사용

print(max(dp.values()))