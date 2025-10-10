from sys import stdin
input = stdin.readline

N, K = map(int, input().split())
A = [int(input()) for _ in range(N)]
count = 0

for a in reversed(A):
    count += K // a
    K %= a

print(count)
