from math import gcd

def calculate_difference(xs):
    differences = [xs[i + 1] - xs[i] for i in range(len(xs) - 1)]
    return differences

def calculate_result(xs, part2):
    if all(x == 0 for x in xs):
        return 0
    differences = calculate_difference(xs)
    return xs[0 if part2 else -1] + (-1 if part2 else 1) * calculate_result(differences, part2)

def main():
    with open("Downloads/input9.txt") as file:
        lines = file.read().strip().split('\n')

    for part2 in [False, True]:
        total_result = 0
        for line in lines:
            values = [int(x) for x in line.split()]
            total_result += calculate_result(values, part2)
        print(total_result)

if __name__ == "__main__":
    main()
