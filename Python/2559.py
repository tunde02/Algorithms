from sys import stdin
input = stdin.readline

N, K = map(int, input().split())
l = list(map(int, input().split()))

"""
# prefix sum
answer = -1000000000
prefix_sum = [0] * N
prefix_sum[0] = l[0]

for i in range(1, N):
    prefix_sum[i] = prefix_sum[i - 1] + l[i]

for i in range(N - K):
    answer = max(answer, prefix_sum[i + K] - prefix_sum[i])

if K == N:
    answer = prefix_sum[-1]

answer = max(answer, prefix_sum[K - 1])

print(answer)
"""

# two pointer
left, right = 0, K - 1
answer = sum(l[left:right + 1])
temp = answer

while right < N - 1:
    right += 1
    temp = temp - l[left] + l[right]
    left += 1
    answer = max(answer, temp)

print(answer)
