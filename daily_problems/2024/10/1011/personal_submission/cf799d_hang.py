INF = 10**18
from collections import Counter
def main():
    a,b,h,w,n = map(int,input().split())
    s = list(map(int,input().split()))
    s.sort(reverse=True)
    n = min(n, 35)
    def f(x,y):
        vis = dict()
        vis[(x,y)] = 0
        for i in range(n):
            for (x,y) in list(vis.keys()):
                nx = (x + s[i] - 1) // s[i]
                ny = (y + s[i] - 1) // s[i]
                if (nx,y) not in vis:
                    vis[(nx,y)] = vis[(x,y)] + 1
                if (x,ny) not in vis:
                    vis[(x,ny)] = vis[(x,y)] + 1
        return vis[(1,1)] if (1,1) in vis else INF
    ans = min(f((a + h - 1)//h, (b + w - 1)//w ), f((a + w - 1)//w, (b + h - 1)//h))
    print(ans if ans < INF else -1)
main()