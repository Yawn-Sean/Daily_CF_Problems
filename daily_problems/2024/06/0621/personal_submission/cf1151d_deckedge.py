def solve():
    n = II()
    a = [0] * n
    b = [0] * n
    #d = [0] * n
    for i in range(n):
        a[i], b[i] = MII()
        #d[i] = i;
    d = list(range(n))
    d.sort(key=lambda i : a[i] - b[i], reverse=True)
    res = 0
    for i in range(n):
        pos = d[i]
        res += a[pos] * i + b[pos] * (n - i - 1)
    print(res)
def main():
    t = 1
    for _ in range(t):
        solve()
main()