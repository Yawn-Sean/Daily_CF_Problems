
def main():
    n,d = map(int,input().split())
    a = list(map(int,input().split()))
    pre = 0
    lim = 0
    ans = 0
    for x in a:
        pre += x
        lim += x
        if x == 0:
            if lim < 0:
                ans += 1
                lim = d
            pre = max(0, pre)
        else :
            lim = min(lim, d)
            if pre > d:
                print(-1)
                return
    print(ans)

if __name__ == '__main__':
    main()
