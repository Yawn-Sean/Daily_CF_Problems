
def main():
    n,k = map(int, input().split())
    a = list(map(int, input().split()))
    cnt = 0
    l = 0
    res = a.copy()
    mx = 0
    #ans = a
    idx = -1
    for r in range(n):
        if a[r] == 0:
            cnt += 1
            res[r] = 1
        while cnt > k:
            if a[l] == 0:
                cnt -= 1
                res[l] = 0
            l += 1
        if r - l + 1 > mx:
            mx = r - l + 1
            #ans = res.copy()
            idx = r
    
    print(mx)
    if idx == -1:
        print(*a)
    else:
        cnt = 0
        for i in range(idx, -1, -1):
            if a[i] == 0 and cnt < k:
                a[i] = 1
                cnt += 1
        print(*a)



main()
