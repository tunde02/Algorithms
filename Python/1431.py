# https://www.acmicpc.net/problem/1431

N = int(input())
guitars = []

for _ in range(N):
    serial = input()
    serial_sum = 0
    for word in serial:
        if ord(word) < ord("A"):
            serial_sum += int(word)

    guitars.append({
        "serial": serial,
        "len": len(serial),
        "sum": serial_sum
    })

guitars = sorted(guitars, key=lambda x: (x["len"], x["sum"], x["serial"]))

for guitar in guitars:
    print(guitar["serial"])
