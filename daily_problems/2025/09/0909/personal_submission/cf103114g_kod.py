n = ix()
res = [0] * (n + 1)
b = n.bit_length()
for i in range(b):
    tmp = []
    for j in range(1, n + 1):
        if j >> i & 1:
            tmp.append(j)
    if len(tmp):
        print(len(tmp), *tmp, flush=True)
        t = il()
        for v in t:
            res[v] |= 1 << i
ans = [0] * (n + 1)
for i in range(n + 1):
    ans[res[i]] = i
print('!', *ans[1:])
