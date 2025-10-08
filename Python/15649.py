from sys import stdin
input = stdin.readline

N, M = map(int, input().split())
results = []

def recur(n: int, result: list[int], check: list[bool]):
    global results

    if n >= M:
        results.append(" ".join(map(str, result)))
        return

    for i in range(N):
        if not check[i]:
            check[i] = True
            result.append(i + 1)
            recur(n + 1, result, check)
            check[result.pop() - 1] = False

recur(0, [], [False] * N)

for result in results:
    print(result)
