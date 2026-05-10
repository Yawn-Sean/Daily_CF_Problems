def solve():
    n,m=MII()
    r1,c1,r2,c2=MII()
    ans=0
    def calc(a, b):
        d = abs(a - b)
        if d == 0:
            return 0
        if d % 2 == 1:
            return 1
        return 2
    print(calc(r1, r2) + calc(c1, c2))


T=1
T=II()

res=[]
for _ in range(T):

    solve()
