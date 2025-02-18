# submission url: https://codeforces.com/contest/1061/submission/280796720

n, x, y = map(int, input().split()) 
a = [list(map(int, input().split())) for _ in range(n)]
 
a.sort() 
b = SortedList()
ans = 0
for l, r in a: 
    ans += (r - l) * y
    ll = bisect.bisect_right(b, - l)
    if len(b) == ll or (l + b[ll]) * y > x: 
        ans += x 
    else:
        ans += (l + b[ll]) * y
        b.remove(b[ll])
    b.add( - r)  
        
print(ans % MOD)
