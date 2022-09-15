import sys
read = sys.stdin.readline


T = int(read().rstrip())
for _ in range(T):
    R, S = map(str, read().split())
    R = int(R)

    word = [S[i // R] for i in range(R * len(S))]
    print(''.join(word))