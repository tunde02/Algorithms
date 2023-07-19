class Node:
    def __init__(self, pos, prev, next = None):
        self.prev = prev
        self.next = next
        self.pos = pos

N = int(input())
K = int(input())
apples = [tuple(map(int, input().split())) for _ in range(K)]
L = int(input())
operates = {}
for _ in range(L):
    op = input().split()
    operates[int(op[0])] = op[1]

directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
d_index = 0
cur_dir = directions[d_index]

head = Node(None, None, None)
tail = Node(None, None, None)
start = Node((1, 1), tail, head)
head.prev = start
tail.next = start

snakes = [start.pos]
time = 0
while True:
    time += 1

    cur_snake_head = head.prev
    next_pos = (cur_snake_head.pos[0] + cur_dir[0], cur_snake_head.pos[1] + cur_dir[1])

    if 1 <= next_pos[0] <= N and 1 <= next_pos[1] <= N and next_pos not in snakes:
        next_node = Node(next_pos, cur_snake_head, head)
        head.prev = next_node
        cur_snake_head.next = next_node
        snakes.append(next_pos)
    else:
        print(time)
        break

    if next_node.pos in apples:
        apples.remove(next_node.pos)
    else:
        snakes.remove(tail.next.pos)
        tail.next.next.prev = tail
        tail.next = tail.next.next

    if time in operates.keys():
        if operates[time] == "L":
            d_index = (d_index - 1) % 4
        else:
            d_index = (d_index + 1) % 4

        cur_dir = directions[d_index]
        operates.pop(time)
