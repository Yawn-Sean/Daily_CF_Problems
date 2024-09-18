def main():
    n, s = MII()
    a = LII()

    s -= 1
    ans = int(a[s] != 0)
    total, max_depth = 1, 0

    a = a[:s] + a[s + 1:]
    a.sort(reverse = True)

    while a and a[-1] == 0:
        ans += 1
        a.pop()
    
    for i in range(len(a) - 1, -1, -1):
        cost = max(1, a[i] - max_depth)
        if cost + total <= n:
            total += cost
            max_depth = a[i]
        else:
            ans += 1
    
    print(ans)
