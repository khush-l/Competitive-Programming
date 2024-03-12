from math import gcd

def calculate_lcm(xs):
    result = 1
    for x in xs:
        result = (x * result) // gcd(x, result)
    return result

def parse_rules(rule_data):
    rules = {'L': {}, 'R': {}}
    steps, rule = rule_data.split('\n\n')
    for line in rule.split('\n'):
        st, lr = line.split('=')
        st = st.strip()
        left, right = lr.split(',')
        left = left.strip()[1:].strip()
        right = right[:-1].strip()
        rules['L'][st] = left
        rules['R'][st] = right
    return steps, rules

def find_positions(part2, rules):
    positions = []
    for s in rules['L']:
        if s.endswith('A' if part2 else 'AAA'):
            positions.append(s)
    return positions

def solve(part2, steps, rules):
    positions = find_positions(part2, rules)
    times = {}
    t = 0

    while True:
        new_positions = []
        for i, p in enumerate(positions):
            p = rules[steps[t % len(steps)]][p]
            if p.endswith('Z'):
                times[i] = t + 1
                if len(times) == len(positions):
                    return calculate_lcm(times.values())
            new_positions.append(p)

        positions = new_positions
        t += 1

    assert False

if __name__ == "__main__":
    with open("Downloads/input8.txt") as file:
        data = file.read().strip()

    steps, rules = parse_rules(data)

    result_part1 = solve(False, steps, rules)
    result_part2 = solve(True, steps, rules)

    print(result_part1)
    print(result_part2)
