'''
|cx-hx| + |cy-hy|
四种情况
枚举就好
'''
INF = 10**10
def main():
    n,m = map(int, input().split())
    c = int(input())
    a = [INF, -INF, INF, -INF]
    for _ in range(c):
        x,y = map(int,input().split())
        a[0] = min(a[0], x+y)
        a[1] = max(a[1], x+y)
        a[2] = min(a[2], x-y)
        a[3] = max(a[3], x-y)

    h = int(input())
    ans = INF
    idx = -1
    for i in range(1, h+ 1):
        x,y = map(int,input().split())
        dis = max(abs(x+y-a[0]), abs(x+y-a[1]), abs(x-y-a[2]), abs(x-y-a[3]))
        if ans > dis:
            ans = dis
            idx = i
    print(ans)
    print(idx)
main()