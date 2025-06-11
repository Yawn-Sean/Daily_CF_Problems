def main():
    def q(x,y):
        print(x,y,flush = True)
        return input()[0] == 'b'
    n = int(input())
    l,r = 0, 10**9
    f = q(r, r)
    for _ in range(n - 1):
        m = (l + r) // 2
        if q(m,m) == f:
            r = m
        else:
            l = m
    print(l,r,r,l)
main()