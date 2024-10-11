def solve():
    n = II()
    a = [int(s.split('.')[1]) for s in LI()]
    tot = sum(a)
    cnt = a.count(0)
    res = 2000 * n
    for i in range(max(0, n - cnt), min(n, 2 * n - cnt) + 1):
        res = min(res, abs(i * 1000 - tot))
    print(res // 1000, '.', str(res % 1000).zfill(3), sep='')
def main():
    t = 1
    while t:
        solve()
        t -= 1
main()
