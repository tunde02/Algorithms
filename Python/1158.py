import sys

N, K = map(int, sys.stdin.readline().split())
l = [str(i + 1) for i in range(N)]
answer = []

last_index = 0
for _ in range(N):
    index = ((K - 1) + last_index) % len(l)
    answer.append(l[index])
    l.pop(index)
    last_index = index

print("<" + ", ".join(answer) + ">")
