def read_input(file_path):
    with open(file_path) as file:
        return file.read().split()

def build_data_map():
    return {
        'S': [],
        '|': [width, -width],
        '-': [-1, 1],
        '.': [],
        '7': [-1, width],
        'L': [1, -width],
        'J': [-1, -width],
        'F': [1, width]
    }

def initialize_start_position(data, data_map):
    start = data.find('S')
    path = {start}
    data = [data_map[c] for c in data]

    for i, offsets in enumerate(data):
        if start in (i + o for o in offsets):
            data_map['S'].append(i - start)

    return start, path, data

def explore_path(path, data, width):
    dist = 0
    new = None
    while True:
        new2 = new
        new = set()
        for p in (new2 or path):
            for offset in data[p]:
                if p + offset not in path:
                    new.add(p + offset)

        if new:
            path |= new
            dist += 1
        else:
            break

    return dist

def main(file_path):
    inp = read_input(file_path)
    width = len(inp[0])
    height = len(inp)
    data = ''.join(inp)
    
    data_map = build_data_map()

    start, path, data = initialize_start_position(data, data_map)

    dist = explore_path(path, data, width)

    print('Part 1:', dist)

if __name__ == "__main__":
    main('Downloads/input10.txt')
def read_input(file_path):
    with open(file_path) as file:
        return file.read().split()

def build_data_map():
    return {
        'S': [],
        '|': [width, -width],
        '-': [-1, 1],
        '.': [],
        '7': [-1, width],
        'L': [1, -width],
        'J': [-1, -width],
        'F': [1, width]
    }

def initialize_start_position(data, data_map):
    start = data.find('S')
    path = {start}
    data = [data_map[c] for c in data]

    for i, offsets in enumerate(data):
        if start in (i + o for o in offsets):
            data_map['S'].append(i - start)

    return start, path, data

def explore_path(path, data, width):
    dist = 0
    new = None
    while True:
        new2 = new
        new = set()
        for p in (new2 or path):
            for offset in data[p]:
                if p + offset not in path:
                    new.add(p + offset)

        if new:
            path |= new
            dist += 1
        else:
            break

    return dist

def main(file_path):
    inp = read_input(file_path)
    width = len(inp[0])
    height = len(inp)
    data = ''.join(inp)
    
    data_map = build_data_map()

    start, path, data = initialize_start_position(data, data_map)

    dist = explore_path(path, data, width)

    print('Part 1:', dist)

main('Downloads/input10.txt')
