"""
1~99
111
123
135
147
159
210
222
234
246
258
321
333
345
357
369
432
444
456
468
531
543
555
567
579
642
654
666
678
765
"""


N = int(input())

if N <= 99:
    print(N)
elif 99 < N < 111:
    print(99)
else:
    num = 0
    for i in range(N, 110, -1):
        check = True
        diff = int(str(i)[0]) - int(str(i)[1])

        for j in range(1, len(str(i)) - 1):
            if int(str(i)[j]) - int(str(i)[j + 1]) != diff:
                check = False

        if check:
            num += 1

    print(num + 99)
