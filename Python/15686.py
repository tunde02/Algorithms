from itertools import combinations

def calc_chicken_distance(house, chicken_positions):
    min_chicken_distance = 1000

    for chicken_position in chicken_positions:
        chicken_distance = abs(house[0] - chicken_position[0]) + abs(house[1] - chicken_position[1])

        if chicken_distance < min_chicken_distance:
            min_chicken_distance = chicken_distance

    return min_chicken_distance

N, M = map(int, input().split())

house_positions = []
chicken_positions = []

for i in range(N):
    row = list(map(int, input().split()))
    for j in range(N):
        if row[j] == 1:
            house_positions.append((i, j))
        elif row[j] == 2:
            chicken_positions.append((i, j))

comb = list(combinations(chicken_positions, M))

min_city_chicken_distance = 1000000
for case in comb:
    city_chicken_distance = 0

    for house in house_positions:
        city_chicken_distance += calc_chicken_distance(house, case)

    if city_chicken_distance < min_city_chicken_distance:
        min_city_chicken_distance = city_chicken_distance

print(min_city_chicken_distance)

