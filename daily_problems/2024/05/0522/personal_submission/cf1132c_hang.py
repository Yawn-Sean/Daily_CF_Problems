def main():
    n, q = map(int, input().split())
    g = []
    cnt = [0] * (n + 1)
    for _ in range(q): 
        l,r = map(int, input().split())
        for i in range(l, r+1): 
            cnt[i] += 1
        g.append((l,r))
   
    
     
    t = [0] * (n + 1)
    ans = 0
    for i in range(q):
        l,r = g[i]
        
        for j in range(l,r+1): 
            cnt[j] -= 1
        cur = 0

        for j in range(1, n+1):
            t[j] = t[j-1] + int(cnt[j] == 1)
            cur += int(cnt[j] >= 1)

        for j in range(i):
            a,b = g[j]
            z = cur - (t[b] - t[a-1])
            ans = max(ans, z)

        for j in range(l,r+1): 
            cnt[j] += 1
    print(ans)
    
main()