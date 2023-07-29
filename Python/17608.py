import sys
input = sys.stdin.readline

N = int(input())
sticks = [int(input()) for _ in range(N)]
biggest_h = sticks[-1]
count = 1

for i in range(1, N + 1):
    if sticks[-i] > biggest_h:
        count += 1
        biggest_h = sticks[-i]

print(count)
