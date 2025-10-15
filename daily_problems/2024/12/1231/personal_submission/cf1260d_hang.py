def main():
    m, n, k, t = map(int, input().split())
    a = list(map(int, input().split()))
    ls = []
    rs = []
    ds = []
    for _ in range(k):
        l, r, d = map(int, input().split())
        ls.append(l)
        rs.append(r)
        ds.append(d)
    a.sort(reverse=True)
    l, r = 0, m
    dif = [0] * (n + 1)
    while l < r:
        mid = (l + r + 1) // 2
        for i in range(k):
            if a[mid - 1] < ds[i]:
                dif[ls[i] - 1] += 1
                dif[rs[i]] -= 1
        res = n + 1
        cur = 0
        for i in range(n + 1):
            cur += dif[i]
            if cur: 
                res += 2
            dif[i] = 0
        
        if res > t: 
            r = mid - 1
        else: 
            l = mid
    print(r)
# main()

def main_1():
    m,n,k,t = map(int, input().split())
    a = list(map(int, input().split()))
    g = []
    for _ in range(k):
        l,r,d = map(int, input().split())
        g.append((l,r,d))
    a.sort(reverse=True)
    left,right = 0,m
    dif = [0] * (n + 1)
    while left < right:
        mid = (left + right + 1) // 2
        for l,r,d in g:
            if a[mid - 1] < d:
                dif[l - 1] += 1
                dif[r] -= 1
        cnt = n + 1
        cur = 0
        for i in range(n + 1):
            cur += dif[i]
            if cur:
                cnt += 2
            dif[i] = 0

        if cnt <= t:
            left = mid
        else:
            right = mid - 1
    print(left)
            
main_1()