import sys
Input = sys.stdin.readline
sys.setrecursionlimit(10**6)

T = int(Input())

for _ in range(T):
    N, K = map(int, Input().split())

    delay_list = list(map(int, Input().split()))
    expect_list = [-1 for _ in range(N)]

    dependencies = {}
    for i in range(N):
        dependencies[i] = []

    for _ in range(K):
        a, b = map(int, Input().split())
        dependencies[b - 1].append(a - 1)

    for k, v in dependencies.items():
        if len(v) == 0:
            expect_list[k] = delay_list[k]

    def get_delay(n):
        if expect_list[n] == -1:
            d = [get_delay(i) for i in dependencies[n]]
            expect_list[n] = max(d) + delay_list[n]
        return expect_list[n]

    print(get_delay(int(Input()) - 1))
