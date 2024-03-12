import sys
from collections import defaultdict

def process_input(file_path):
    with open(file_path) as file:
        return file.read().strip().split('\n')

def main():
    file_path = "Downloads/input4.txt"  # Replace with the actual path to your input file
    lines = process_input(file_path)

    p1 = 0
    N = defaultdict(int)

    for i, line in enumerate(lines):
        N[i] += 1
        first_part, rest_part = line.split('|')
        id_, card = first_part.split(':')
        card_nums = [int(x) for x in card.split()]
        rest_nums = [int(x) for x in rest_part.split()]
        val = len(set(card_nums) & set(rest_nums))

        if val > 0:
            p1 += 2**(val - 1)

        for j in range(val):
            N[i + 1 + j] += N[i]

    print(p1)
    print(sum(N.values()))

if __name__ == "__main__":
    main()
