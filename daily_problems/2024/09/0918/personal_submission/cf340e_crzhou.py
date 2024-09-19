def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    mod = 10**9 + 7
    n = int(data[0])
    a = list(map(int, data[1:n + 1]))

    f = [1] * (n + 1)
    for i in range(2, n + 1):
        f[i] = f[i - 1] * i % mod

    m = {}
    p = {}
    c = 0
    s = 0
    r = 0

    for i in range(n):
        if a[i] == i + 1:
            print(0)
            return
        if a[i] == -1:
            p[i + 1] = True
        else:
            m[a[i]] = True
            c += 1

    for i in range(1, n + 1):
        if not m.get(i, False) and p.get(i, False):
            s += 1

    for i in range(s + 1):
        if i & 1:
            r = (r - com(s, i, f, mod) * f[n - c - i] % mod + mod) % mod
        else:
            r = (r + com(s, i, f, mod) * f[n - c - i] % mod) % mod

    print(r)
