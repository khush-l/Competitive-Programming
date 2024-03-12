#!/usr/bin/env python3

from functools import cache

clue_data, vals_data = None, None

@cache
def calculate_clue(clue_offset, dig, val_offset, current_run):
    if dig == "E":
        if len(vals_data) == val_offset and current_run == 0:
            return 1
    else:
        if dig == "?":
            return (
                calculate_clue(clue_offset, ".", val_offset, current_run) +
                calculate_clue(clue_offset, "#", val_offset, current_run)
            )
        elif dig == ".":
            if current_run == 0:
                return calculate_clue(clue_offset + 1, clue_data[clue_offset + 1], val_offset, 0)
            elif current_run == vals_data[val_offset]:
                return calculate_clue(clue_offset + 1, clue_data[clue_offset + 1], val_offset + 1, 0)
        else:
            if val_offset < len(vals_data) and current_run < vals_data[val_offset]:
                return calculate_clue(clue_offset + 1, clue_data[clue_offset + 1], val_offset, current_run + 1)

    return 0

def calculate(log, values, mode):
    result = 0
    global clue_data, vals_data

    for row in values:
        clue_data, vals_data = row.split(" ")
        if mode == 2:
            clue_data = "?".join([clue_data] * 5)
            vals_data = ",".join([vals_data] * 5)
        vals_data = tuple(int(x) for x in vals_data.split(","))
        clue_data += ".E"
        calculate_clue.cache_clear()
        result += calculate_clue(0, clue_data[0], 0, 0)

    return result

def run(log, values):
    log(calculate(log, values, 1))
    log(calculate(log, values, 2))

if __name__ == "__main__":
    values_path = "Downloads/input12.txt"
    with open(values_path) as f:
        values = [x.strip("\r\n") for x in f.readlines()]

    run(print, values)
