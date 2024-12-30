def solve():
    n, m = MII()
    a = LII()
    pre = [0] * n
    for i in range(n):
        if i == 0 or a[i] != a[i - 1]:
            pre[i] = i - 1
        else:
            pre[i] = pre[i - 1]
    while m:
        l, r, val = MII()
        l -= 1
        r -= 1
        if a[r] != val:
            print(r + 1)
        elif pre[r] >= l:
            print(pre[r] + 1)
        else:
            print(-1)
        m -= 1
def main():
    t = 1
    while t:
        solve()
        t -= 1
main()
