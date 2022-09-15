# https://www.acmicpc.net/problem/2108

from sys import stdin, stdout
_input = stdin.readline
_print = stdout.write

N = int(_input())
arr = []
_max = -4001
_min = 4001
_sum = 0
_mode = 0 # 최빈값

for _ in range(N):
    num = int(_input())
    arr.append(num)
    _max = max(_max, num)
    _min = min(_min, num)
    _sum += num

arr.sort()

num_dict = {x: 0 for x in set(arr)}
for num in arr:
    num_dict[num] += 1
num_list = sorted(num_dict.items(), key=lambda x: (-x[1], x[0]))

if len(num_list) > 1 and num_list[0][1] == num_list[1][1]:
    _mode = num_list[1][0]
else:
    _mode = num_list[0][0]

_print("\n".join(map(str, [round(_sum / N), arr[N // 2], _mode, _max - _min])))
