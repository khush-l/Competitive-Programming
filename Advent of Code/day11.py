import sys

input_file = sys.argv[1]
with open(input_file) as file:
    data = file.read().strip()

lines = data.split('\n')
grid = [[char for char in row] for row in lines]

num_rows = len(grid)
num_cols = len(grid[0])

for row in grid:
    assert len(row) == num_cols

empty_rows = [r for r in range(num_rows) if '#' not in grid[r]]
empty_cols = [c for c in range(num_cols) if '#' not in [grid[r][c] for r in range(num_rows)]]

hash_coordinates = [(r, c) for r in range(num_rows) for c in range(num_cols) if grid[r][c] == '#']

for part2 in [False, True]:
    expansion_factor = 10**6 - 1 if part2 else 2 - 1
    total_distance = 0

    for i, (r, c) in enumerate(hash_coordinates):
        for j in range(i, len(hash_coordinates)):
            r2, c2 = hash_coordinates[j]
            distance = abs(r2 - r) + abs(c2 - c)
            for empty_row in empty_rows:
                if min(r, r2) <= empty_row <= max(r, r2):
                    distance += expansion_factor

            for empty_col in empty_cols:
                if min(c, c2) <= empty_col <= max(c, c2):
                    distance += expansion_factor

            total_distance += distance

    print(total_distance)
