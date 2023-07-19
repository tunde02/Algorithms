import sys

Input = sys.stdin.readline

N, M = map(int, input().split())

paper = []
for _ in range(N):
    row = list(map(int, Input().split()))
    paper.append(row)

tetromino_list = [
    [(0, 0), (0, 1), (0, 2), (0, 3)],
    [(0, 0), (1, 0), (2, 0), (3, 0)],

    [(0, 0), (0, 1), (1, 0), (1, 1)],

    [(0, 0), (1, 0), (2, 0), (2, 1)],
    [(0, 0), (0, 1), (0, 2), (1, 0)],
    [(0, 0), (0, 1), (1, 1), (2, 1)],
    [(0, 2), (1, 0), (1, 1), (1, 2)],

    [(0, 0), (1, 0), (1, 1), (2, 1)],
    [(0, 1), (0, 2), (1, 0), (1, 1)],

    [(0, 0), (0, 1), (0, 2), (1, 1)],
    [(0, 1), (1, 0), (1, 1), (2, 1)],
    [(0, 1), (1, 0), (1, 1), (1, 2)],
    [(0, 0), (1, 0), (1, 1), (2, 0)],

    [(0, 1), (1, 1), (2, 0), (2, 1)],
    [(0, 0), (1, 0), (1, 1), (1, 2)],
    [(0, 0), (0, 1), (1, 0), (2, 0)],
    [(0, 0), (0, 1), (0, 2), (1, 2)],

    [(0, 1), (1, 0), (1, 1), (2, 0)],
    [(0, 0), (0, 1), (1, 1), (1, 2)]
]

max_sum = 0
for i in range(N):
    for j in range(M):
        for tetromino in tetromino_list:
            now_sum = 0
            check = True
            for n in range(4):
                if i + tetromino[n][0] >= N or j + tetromino[n][1] >= M:
                    check = False
                    break

                now_sum += paper[i + tetromino[n][0]][j + tetromino[n][1]]

            if check and max_sum < now_sum:
                max_sum = now_sum

print(max_sum)
