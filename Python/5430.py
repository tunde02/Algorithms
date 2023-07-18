import sys

T = int(input())
Input = sys.stdin.readline

for _ in range(T):
    is_reversed = False
    is_error = False

    p = Input().rstrip()
    left = 0
    right = int(input()) - 1
    arr = Input().rstrip()[1:-1].split(",")

    for func in p:
        if right < left and func == "D":
            is_error = True
            break
        elif func == "R":
            is_reversed = not is_reversed
        elif func == "D":
            left = left + 1 if not is_reversed else left
            right = right - 1 if is_reversed else right

    if is_error:
        print("error")
        continue

    result_len = right - left + 1
    result = []
    if is_reversed:
        result = [arr[right - i] for i in range(result_len)]
    else:
        result = [arr[left + i] for i in range(result_len)]

    print("[" + ",".join(result) + "]")
