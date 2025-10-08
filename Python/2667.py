from sys import stdin

input = stdin.readline
N = int(input())
board = [list(map(int, input().strip())) for _ in range(N)]
check = [[False for _ in range(N)] for _ in range(N)]
dx = [0, 0, -1, 1]
dy = [-1, 1, 0, 0]
count = 0
sizes = []

def dfs(i: int, j: int) -> int:
    size = 1
    for x, y in zip(dx, dy):
        nx, ny = i + x, j + y
        if 0 <= nx < N and 0 <= ny < N and board[nx][ny] == 1 and not check[nx][ny]:
            check[nx][ny] = True
            size += dfs(nx, ny)

    return size

for i in range(N):
    for j in range(N):
        if board[i][j] == 1 and not check[i][j]:
            check[i][j] = True
            count += 1
            sizes.append(dfs(i, j))

sorted_sizes = sorted(sizes)

print(count)
for num in sorted_sizes:
    print(num)
