class FenwickTree:
    '''Reference: https://en.wikipedia.org/wiki/Fenwick_tree'''

    def __init__(self, n: int = 0) -> None:
        self._n = n
        self.data = [0] * n

    def add(self, p: int, x: typing.Any) -> None:
        assert 0 <= p < self._n

        p += 1
        while p <= self._n:
            self.data[p - 1] += x
            p += p & -p

    def sum(self, left: int, right: int) -> typing.Any:
        assert 0 <= left <= right <= self._n

        return self._sum(right) - self._sum(left)

    def _sum(self, r: int) -> typing.Any:
        s = 0
        while r > 0:
            s += self.data[r - 1]
            r -= r & -r

        return s

def main():
    n=II()
    a=[LII() for _ in range(n)]
    U,D,L,R,ul,dr=[
        [[0]*n for _ in range(n)]
        for _ in range(6)
    ]
    ans=0
    for i in range(n):
        for j in range(n):
            if a[i][j]==0:
                continue
            U[i][j]=U[i-1][j]+1 if i else 1
            L[i][j]=L[i][j-1]+1 if j else 1
            ans+=1
    for i in range(n-1,-1,-1):
        for j in range(n-1,-1,-1):
            if a[i][j]==0:
                continue
            D[i][j]=D[i+1][j]+1 if i!=n-1 else 1
            R[i][j]=R[i][j+1]+1 if j!=n-1 else 1
    for i in range(n):
        for j in range(n):
            ul[i][j]=min(U[i][j],L[i][j])
            dr[i][j]=min(D[i][j],R[i][j])
    dbg(ul)
    dbg(dr)
    """
    j>i
    i+di>j
    or
    j<i+di
    j-uj<i
    consider as points
    type 0: (j,j-uj)
    type 1: (i+di,i)
    sort all type together
    touch type 0, fen.add(j-uj,1)
    touch type 1, fen._sum(i)
    note when i>j, it is always true,
    so we sub these
    """
    def work(sx,sy):
        nonlocal ans
        dbg(f"sx={sx}, sy={sy}")
        i,j,k=sx,sy,0
        data=[]
        while i<n and j<n:
            if a[i][j]:
                dbg(f"i={i} j={j} k={k} ul={ul[i][j]} dr={dr[i][j]} ({k},{k-ul[i][j]+1},0) ({k+dr[i][j]},{k+1},1)")
                data.append((k,k-ul[i][j]+1,0))
                data.append((k+dr[i][j],k+1,1))
            i+=1
            j+=1
            k+=1
        data.sort(key=lambda x: x[0])
        fen=FenwickTree(n+1)
        cc=len(data)//2
        res=-cc*(cc+1)//2
        for _,x in enumerate(data):
            if x[2]: # type: 1
                res+=fen._sum(x[1]);
            else: # type: 0
                fen.add(x[1],1);
        dbg(f"res={res}")
        ans+=res;
        return
    work(0,0)
    for i in range(1,n):
        work(i,0)
        work(0,i)
    print(ans)
    return

multi_test = 0
if __name__ == "__main__":
    T = II() if multi_test else 1
    for _ in range(T):
        main()
