"""
1
1

1
-----
4
1
5
1
5

1
1
1
1
"""

"""
시간 초과된 코드
-----
모든 입력을 우선 다 받고, 입력값 리스트를 정렬한 뒤 값이 입력된 역순으로
중간값을 저장하며 리스트에서 지우고, 최종 완성된 중간값 리스트를 역순으로 출력한다
-----

    n = int(input().rstrip())
    numbers = [int(input().rstrip()) for _ in range(n)]
    temp = numbers[:]
    answers = []

    numbers.sort()

    for i in range(n):
        mid_index = int(len(numbers) / 2) if len(numbers) % 2 != 0 else int(len(numbers) / 2) - 1
        answers.append(numbers[mid_index])
        numbers.remove(temp[-i - 1])

    for i in range(1, n + 1):
        print(answers[-i])
"""


"""
결국 중간값은 입력된 수들의 중앙부근에 있다.
중간값, 중간값보다 작은 수들, 중간값보다 큰 수들을 수가 입력될 때마다 최신화한다.
중간값보다 큰 수가 입력되면 다음 중간값은 중간값보다 큰 수들 중 가장 작은 수가 된다.
중간값보다 작은 수가 입력되면 다음 중간값은 중간값보다 작은 수들 중 가장 큰 수가 된다.
"""

import sys
from heapq import heappush, heappop
read = sys.stdin.readline


n = int(read().rstrip())
smalls = []
bigs = []
answers = []

mid = int(read().rstrip())
answers.append(mid)

is_even = False
for _ in range(n - 1):
    new_num = int(read().rstrip())

    if is_even:
        if mid >= new_num:
            heappush(smalls, -new_num)
        else:
            heappush(smalls, -mid)
            heappush(bigs, new_num)
            mid = heappop(bigs)
    else:
        if mid > new_num:
            heappush(smalls, -new_num)
            heappush(bigs, mid)
            mid = -heappop(smalls)
        else:
            heappush(bigs, new_num)

    answers.append(mid)
    is_even = not is_even

for i in range(n):
    print(answers[i], end='\n')