from sys import stdin
input = stdin.readline

N = int(input())
A = list(map(int, input().split()))
M = int(input())
lst = list(map(int, input().split()))

def binary_search(left: int, right: int, target: int) -> bool:
    if left >= right:
        return target == A[left]

    mid = (right + left) // 2
    if A[mid] >= target:
        return binary_search(left, mid, target)
    else:
        return binary_search(mid + 1, right, target)

A.sort()

for num in lst:
    if binary_search(0, N - 1, num):
        print(1)
    else:
        print(0)
