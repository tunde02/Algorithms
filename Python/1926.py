from sys import stdin
from collections import deque

I = stdin.readline
N, M = map(int, I().split())
board = [list(map(int, I().split())) for _ in range(N)]
check = [[False] * M for _ in range(N)]
shape_num = 0
max_shape_size = 0
q = deque()

for i in range(N):
    for j in range(M):
        if board[i][j] == 1 and not check[i][j]:
            q.append((i, j))
            check[i][j] = True
            size = 1

            while q:
                x, y = q.popleft()

                if x - 1 >= 0 and board[x - 1][y] == 1 and not check[x - 1][y]:
                    q.append((x - 1, y))
                    check[x - 1][y] = True
                    size += 1
                if x + 1 < N and board[x + 1][y] == 1 and not check[x + 1][y]:
                    q.append((x + 1, y))
                    check[x + 1][y] = True
                    size += 1
                if y - 1 >= 0 and board[x][y - 1] == 1 and not check[x][y - 1]:
                    q.append((x, y - 1))
                    check[x][y - 1] = True
                    size += 1
                if y + 1 < M and board[x][y + 1] == 1 and not check[x][y + 1]:
                    q.append((x, y + 1))
                    check[x][y + 1] = True
                    size += 1

            shape_num += 1
            max_shape_size = max(max_shape_size, size)

print(f"{shape_num}\n{max_shape_size}")
