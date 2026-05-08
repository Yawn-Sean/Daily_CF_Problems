outs = []
for _ in range(int(input())):
    n = int(input())
    s = input()
    d = dict()
    for ch in s:
        if ch in d:
            d[ch] += 1
        else:
            d[ch] = 1

    if len(d) == 1 or (len(d) == 3 and d['a'] == d['b'] == d['c'] == 1):
        outs.append('NO')
    else:
        outs.append('YES')

print('\n'.join(outs))
