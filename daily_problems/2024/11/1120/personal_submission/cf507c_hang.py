def main():
    h,n = map(int,input().split())
    def f(l,r,dir,depth):
        if depth == 0:
            return 0
        m = (l + r) >> 1
        res = 1 << depth if (n <= m) == dir else 1
        if n <= m:
            return res + f(l,m,1,depth - 1)
        else:
            return res + f(m + 1,r,0,depth - 1)
    print(f(1,1<<h,0,h))

main()