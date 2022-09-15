"""
00121000100
010121000V0
00001210010
10V00121000

00121000100
010121000V0
00001210010
10V00121000

시간초과남

얼음을 녹는 날짜로 치환한 배열에서,
백조끼리 언제부터 만날 수 있는지 어떻게 구할까?

converted_board 에서 1번 백조 기준으로 모든 타일에 대해 BFS 실행
몇 일째에 해당 타일에 갈 수 있는지
그후 2번 백조가 있는 타일의 일을 출력
"""


import sys
from queue import Queue
read = sys.stdin.readline
dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]

r, c = map(int, read().split())
board = []
starts = []
temp = [read().rstrip() for _ in range(r)]


def convert(board):
    days = 1
    q = {}

    for i in range(len(board)):
        for j in range(len(board[0])):
            if board[i][j] == 0:
                q[(i, j)] = 'hello'

    while len(q) > 0:
        temp = {}
        for now in q.keys():
            for i in range(4):
                nowX = now[0] + dx[i]
                nowY = now[1] + dy[i]

                if nowX < 0 or nowX >= r or nowY < 0 or nowY >= c:
                    continue

                if board[nowX][nowY] == -1:
                    board[nowX][nowY] = days
                    temp[(nowX, nowY)] = 'hello'

        q = temp
        days += 1

    return board



def melt(board):
    q = {}

    for i in range(len(board)):
        for j in range(len(board[0])):
            if board[i][j] == 0:
                q[(i, j)] = 1

    for room in q.keys():
        for i in range(4):
            nowX = room[0] + dx[i]
            nowY = room[1] + dy[i]

            if nowX < 0 or nowX >= r or nowY < 0 or nowY >= c:
                continue

            # print((nowX, nowY))
            if board[nowX][nowY] == 1:
                board[nowX][nowY] = 0

    return board


def search(board, x1, y1, x2, y2):
    # DFS
    s = []
    visit = [[False for _ in range(len(board[0]))] for _ in range(len(board))]

    s.append((x1, y1))
    visit[x1][y1] = True
    while len(s) > 0:
        now = s.pop()

        if now[0] == x2 and now[1] == y2:
            return True

        for i in range(4):
            nowX = now[0] + dx[i]
            nowY = now[1] + dy[i]

            if nowX < 0 or nowX >= r or nowY < 0 or nowY >= c:
                continue

            if not visit[nowX][nowY] and board[nowX][nowY] == 0:
                s.append((nowX, nowY))

            visit[nowX][nowY] = True

    return False


def search_2(board, x1, y1, x2, y2):
    days = 0

    s = []
    visit = [[False for _ in range(len(board[0]))] for _ in range(len(board))]

    s.append((x1, y1))
    visit[x1][y1] = True
    while len(s) > 0:
        now = s.pop()

        for i in range(4):
            nowX = now[0] + dx[i]
            nowY = now[1] + dy[i]

            if nowX < 0 or nowX >= r or nowY < 0 or nowY >= c:
                continue

            if board[nowX][nowY] <= days and nowX == x2 and nowY == y2:
                return days

            if not visit[nowX][nowY] and board[nowX][nowY] == 0:
                s.append((nowX, nowY))

            visit[nowX][nowY] = True

        days += 1

    # q = {}

    # q[(x1, y1)] = 'hello'

    # while len(q) > 0:
    #     temp = {}

    #     for now in q.keys():
    #         for i in range(4):
    #             nowX = now[0] + dx[i]
    #             nowY = now[1] + dy[i]

    #             if nowX < 0 or nowX >= r or nowY < 0 or nowY >= c:
    #                 continue

    #             if board[nowX][nowY] <= days:
    #                 temp[(nowX, nowY)] = 'hello'
    #                 continue

    #             if nowX == x2 and nowY == y2:
    #                 return days

    #     q = temp
    #     days += 1

    # return days


def print_board(board):
    print('------------------')
    for i in range(len(board)):
        line = ''
        for j in range(len(board[0])):
            if board[i][j] == 0:
                line += '.'
            else:
                line += 'X'
        print(line)


def print_converted_board(board):
    print('------------------')
    for i in range(len(board)):
        line = ''
        for j in range(len(board[0])):
            line += str(board[i][j])
        print(line)


for i in range(len(temp)):
    line = []
    for j in range(len(temp[0])):
        if temp[i][j] == '.':
            line.append(0)
        elif temp[i][j] == 'X':
            line.append(-1)
        else:
            starts.append((i, j))
            line.append(0)
    board.append(line)

board = convert(board)
print_converted_board(board)
count = search_2(board, starts[0][0], starts[0][1], starts[1][0], starts[1][1])
print(count)
# print_converted_board(board)

# count = 0
# while not search(board, starts[0][0], starts[0][1], starts[1][0], starts[1][1]):
#     board = melt(board)
#     # print_board(board)
#     count += 1

# print(count)

