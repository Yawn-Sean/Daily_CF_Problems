outs = []
for _ in range(int(input())):
    s = input()
    t = ''
    for x in s:
        for y in "ezpc":
            if x == y:
                t += y
                break
    if t in ("ezpc", "zepc", "zpec"):
        outs.append('YES')
    else:
        outs.append('NO')

print('\n'.join(outs))
