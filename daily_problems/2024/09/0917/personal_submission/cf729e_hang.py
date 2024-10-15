def main():
    n,s = map(int,input().split())
    s -= 1
    a = list(map(int,input().split()))
    ans = int(a[s] != 0)
    a[s] = 0
    a.sort(reverse=True)
    a.pop()
    cur = 1 # 代表当前员工最多可以有多少个上级
    l,r = 0,len(a) - 1
    cnt = 0 # 需要对 0 特殊处理
    while l <= r:
        x = a[r]
        if x == 0:
            cnt += 1
            ans += 1
            # cur += 1
            r -= 1
        elif x > cur:
            
            cur += 1
            if cnt:
                cnt -= 1
            else:
                ans += 1
                l += 1
        else:
            if x == cur:
                cur += 1
            r -= 1

    print(ans)

main()