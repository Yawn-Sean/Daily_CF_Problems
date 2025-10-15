x = input()
nonzero_start, nonzero_end, dot = None, None, None
for i, ch in enumerate(x):
    if ch == '.':
        dot = i
    elif ch != '0':
        nonzero_start = i if nonzero_start is None else nonzero_start
        nonzero_end = i
print(x[nonzero_start], end='')
if nonzero_end != nonzero_start:
    print('.', end='')
    for i in range(nonzero_start + 1, nonzero_end + 1):
        if x[i] != '.':
            print(x[i], end='')
if dot is None:
    exp = len(x) - nonzero_start - 1
elif nonzero_start < dot:
    exp = dot - 1 - nonzero_start
else:
    exp = dot - nonzero_start
if exp != 0:
    print(f"E{exp}", end='')
print()