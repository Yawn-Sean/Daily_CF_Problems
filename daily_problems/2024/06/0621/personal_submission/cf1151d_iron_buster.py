# fx = a[i] * (j - 1) + b[i] * (n - j)
# a[i] * j - a[i] + b[i] * n - b[i] * j
# j * (a[i] - b[i]) + b[i] * n - a[i]


def solve():
    n = II()
    c = []
    for _ in range(n): 
        a, b = MII()
        c.append([a, b, a-b])
    c.sort(key=lambda x:-x[2])

    ans = 0
    for i, (a, b, val) in enumerate(c):
        ans += (i + 1) * val + b * n - a
    print(ans)



 
if __name__ == '__main__':
    t = 1
    for _ in range(t):
        solve()
