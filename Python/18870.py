# https://www.acmicpc.net/step/9

from sys import stdin, stdout
I = stdin.readline
P = stdout.write

N = int(I())
arr = list(map(int, I().split()))
temp = sorted(list(set(arr)))
compressed_position = {temp[x]: x for x in range(len(temp))}

P(" ".join(map(str, [compressed_position[x] for x in arr])))
