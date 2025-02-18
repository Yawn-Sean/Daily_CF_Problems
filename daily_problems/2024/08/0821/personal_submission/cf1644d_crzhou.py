data = input().split()
index = 0
T = int(data[index])
index += 1
results = []

def solve(n, m, k, q, operations):
    row = set()
    col = set()
    crow = ccol = ss = 0

    for i in range(q - 1, -1, -1):
        x, y = operations[i]
        bz = False
        if crow < n and ccol < m:
            if x not in row:
                row.add(x)
                crow += 1
                bz = True
            if y not in col:
                col.add(y)
                ccol += 1
                bz = True
            if bz:
                ss += 1
        if crow == n and ccol == m:
            break
    return pow(k, ss, MOD)

for _ in range(T):
    n = int(data[index])
    m = int(data[index + 1])
    k = int(data[index + 2])
    q = int(data[index + 3])
    index += 4
    
    operations = []
    for i in range(q):
        x = int(data[index])
        y = int(data[index + 1])
        operations.append((x, y))
        index += 2
    
    result = solve(n, m, k, q, operations)
    results.append(result)

sys.stdout.write('\n'.join(map(str, results)) + '\n')
