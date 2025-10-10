"""
5 6
1 2 2
1 3 3
1 5 1
2 3 4
2 4 5
3 4 6

11
"""

import heapq
from sys import stdin
input = stdin.readline

V, E = map(int, input().split())
edges = [[] for _ in range(V + 1)]
visited = [False] * (V + 1)
total_weight = 0

for _ in range(E):
    a, b, weight = map(int, input().split())
    edges[a].append([weight, b])
    edges[b].append([weight, a])

heap = [[0, 1]]

while heap:
    weight, node = heapq.heappop(heap)

    if visited[node]:
        continue

    visited[node] = True
    total_weight += weight

    for edge in edges[node]:
        if not visited[edge[1]]:
            heapq.heappush(heap, edge)

print(total_weight)
