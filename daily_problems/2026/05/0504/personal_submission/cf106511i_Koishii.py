def query(a, b):
    print('?', len(a), *a, len(b), *b, flush=True)
    return map(int, input().split())

n = int(input())
se = [[] for i in range(22)]
sb = [[] for i in range(22)]

for i in range(n):
    se[i // 20 + 1].append(i + 1)
    sb[i // 20 + 1].append(i + 1)

ans = [-1] * n

for i in range(1, 21):
    if (len(sb[i]) == 0): break
    for j in range(1, 21):
        while True and len(se[j]) >= 1:
            i1, i2 = query(se[j], sb[i])
            if i1 == -1:
                break
            ans[i1 - 1] = i2
            se[j].remove(i1)

print('!', *ans, flush=True)
