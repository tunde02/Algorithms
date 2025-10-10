from sys import stdin
input = stdin.readline

N, M = map(int, input().split())
start_i, start_j, direction = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(N)]
di = [-1, 0, 1, 0]
dj = [0, 1, 0, -1]

def sweep(i: int, j: int, direction: int) -> int:
    count = 0

    while True:
        # 1.
        if board[i][j] == 0:
            board[i][j] = 2
            count += 1

        all_clean = True
        for n in range(4):
            ni, nj = i + di[n], j + dj[n]
            if board[ni][nj] == 0:
                all_clean = False
                break

        # 2.
        if all_clean:
            ni, nj = i - di[direction], j - dj[direction]
            # 2-1.
            if board[ni][nj] != 1:
                i, j = ni, nj
            # 2-2.
            else:
                break
        # 3.
        else:
            # 3-1.
            direction = (direction - 1) % 4
            ni, nj = i + di[direction], j + dj[direction]
            # 3-2.
            if board[ni][nj] == 0:
                i, j = ni, nj

    return count

print(sweep(start_i, start_j, direction))
