from collections import Counter
def main():
    n,a,b = map(int,input().split())
    v1 = Counter()
    v2 = Counter()
    ans = 0
    for _ in range(n):
        _,vx,vy = map(int,input().split())
        ans += v1[vy - a * vx]
        ans -= v2[(vx, vy)]
        v1[vy - a * vx ] += 1
        v2[(vx, vy)] += 1
    print(ans * 2)

main()