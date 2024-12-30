from bisect import *
class BIT:
    def __init__(self, n: int):
        self.tree = [0] * n
    def add(self, x: int , val: int):
        while x < len(self.tree):
            self.tree[x] += val
            x += x & -x
    def query(self, x: int)-> int:
        res = 0
        while x > 0:
            res += self.tree[x]
            x &= x - 1
        return res
for _ in range(int(input())):
    n=int(input())
    a=list(map(int,input().split()))
    b=list(set(a))
    b.sort()
    ans=0
    t = BIT(len(b)+1)
    cnt=0
    for x in a:
        i = bisect_left(b,x)
        j = bisect_right(b,x)
        x = t.query(i)
        y = t.query(j)
        ans+=min(cnt-x,x,cnt-y,y)
        t.add(i+1,1)
        cnt+=1

    print(ans)
