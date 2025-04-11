n, x1, x2 = map(int, input().split())
C = list(map(int, input().split()))
servers = [(c, i) for i, c in enumerate(C, start=1)]
servers.sort(reverse=True)

def check(x1, x2):
    k1 = k2 = -1
    for t in range(1, n+1):
        if servers[t-1][0] * t >= x1:
            k1 = t
            break
    else:
        return None
    for t in range(1, n - k1 + 1):
        if servers[k1 + t - 1][0] * t >= x2:
            k2 = t
            break
    else:
        return None
    group1 = [servers[i][1] for i in range(k1)]
    group2 = [servers[k1 + j][1] for j in range(k2)]
    return (k1, k2, group1, group2)

res1 = check(x1, x2)
res2 = check(x2, x1)
if res1 is not None:
    k1, k2, group1, group2 = res1
elif res2 is not None:
    k2, k1, group2, group1 = res2
else:
    exit(print("No"))
    
print("Yes")
print(k1, k2)
print(*group1)
print(*group2)
