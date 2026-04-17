def II():
    return int(input())
def LII():
    return list(map(int, input().split()))

t = II()
for _ in range(t):
    n = II()
    a = LII()
    used = [False] * (n + 1)
    b = [0] * (n + 1)
    for i in range(1, n + 1):
        if not used[a[i - 1]]:
            b[i] = a[i - 1]
            used[a[i - 1]] = True
    comp = []
    for i in range(1, n + 1):
        if b[i] != 0 and not used[i]:
            tail = i
            while b[tail] != 0:
                tail = b[tail]
            comp.append((i, tail))
        elif b[i] == 0 and not used[i]:
            comp.append((i, i))
            
    m = len(comp)
    if m > 0:
        if m == 1 and comp[0][0] == comp[0][1]:
            x = comp[0][0]
            target = a[x - 1]
            for u in range(1, n + 1):
                if b[u] == target:
                    b[u] = x
                    b[x] = target
                    break
        else:
            for j in range(m - 1):
                b[comp[j][1]] = comp[j + 1][0]
            b[comp[m - 1][1]] = comp[0][0]
            
    k = sum(1 for i in range(1, n + 1) if a[i - 1] == b[i])
    print(k)
    print(' '.join(str(x) for x in b[1:]))
