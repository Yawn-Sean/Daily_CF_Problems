def main():
    n = int(input())
    a = list(map(int, input().split()))
    m = int(input())
    v = [0] * (n + 1)
    for _ in range(m):
        p,s = map(int, input().split())
        v[s] = max(v[s], p)
    for i in range(n-1, 0, -1):
        v[i] = max(v[i], v[i+1])
    if max(a) > v[1]:
        print(-1)
        return
        
    def check(l,r):
        mx = max(a[l:r+1])
        if mx > v[r-l+1]:
            return False
        else:
            return True
    start = 0
    mx = 0
    ans = 1
    for i in range(n):
        mx = max(mx, a[i])
        if mx > v[i - start + 1]:
            start = i
            ans += 1
            mx = a[i]
    print(ans)
    # 二分过不去 nlog(n)的复杂度
    # l,r = 0,n-1
    # res = 0
    # while l <= r:
    #     left = 0
    #     right = r-l+1
    #     while left < right:
    #         mid = (left + right + 1) // 2
    #         if check(l,l + mid - 1):
    #             left = mid
    #         else:
    #             right = mid - 1
    #     l += left
    #     res += 1
    # print(res)

t = int(input())
for _ in range(t):
    main()