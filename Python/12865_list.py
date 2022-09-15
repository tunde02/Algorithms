"""
메모이제이션을 위한 저장공간 dp를 배열로 선언하였고, 무게들의 합의 경우의 수가 아닌
모든 무게들에 대해 공간을 확보했기 때문에 메모리공간 낭비가 심하다
"""

import sys


N, K = map(int, sys.stdin.readline().split())
W, V = [0 for i in range(N)], [0 for i in range(N)]
for i in range(N):
    W[i], V[i] = map(int, sys.stdin.readline().split())

dp = [[0 for _ in range(K + 1)] for _ in range(N + 1)]

for i in range(0, N + 1):
    for j in range(0, K + 1):
        if i == 0 or j == 0:
            dp[i][j] = 0
        elif W[i - 1] > j:
            dp[i][j] = dp[i - 1][j]
        else:
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - W[i - 1]] + V[i - 1])

print(dp[N][K])