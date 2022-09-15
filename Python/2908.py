A, B = map(list, input().split())

A.reverse()
B.reverse()

for i in range(3):
    if int(A[i]) == int(B[i]):
        continue

    if int(A[i]) > int(B[i]):
        print(''.join(A))
    elif int(A[i]) < int(B[i]):
        print(''.join(B))

    break