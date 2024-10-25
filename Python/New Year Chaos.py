# New Year Chaos
# https://www.hackerrank.com/challenges/one-week-preparation-kit-new-year-chaos/problem


# Input
# 4
# 5
# 2 1 5 3 4
# 5
# 2 5 1 3 4
# 8
# 5 1 2 3 7 8 6 4
# 8
# 1 2 5 3 7 8 6 4

# Output
# 3
# Too chaotic
# Too chaotic
# 7


def minimumBribes(q):
    count = 0

    for i in range(len(q) - 1, -1, -1):
        if i + 1== q[i]:
            continue

        check = False
        for j in range(1, 3):
            if i + 1 == q[i - j]:
                check = True
                count += j
                # change list
                # i-j <-> i-j + 1
                # i-j + 1 <-> i-j + 2
                # i-j + k, k in range(j)
                for k in range(j):
                    q[i-j+k], q[i-j+k+1] = q[i-j+k+1], q[i-j+k]

                break

        if not check:
            print("Too chaotic")
            return

    print(count)

if __name__ == '__main__':
    t = int(input().strip())

    for t_itr in range(t):
        n = int(input().strip())

        q = list(map(int, input().rstrip().split()))

        minimumBribes(q)
