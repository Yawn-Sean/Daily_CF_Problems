import sys
input = lambda: sys.stdin.readline().strip()
MII = lambda: map(int, input().split())

def GosperHack(n, k):
    res = []
    cur, hi = (1 << k) - 1, 1 << n
    while cur < hi:
        res.append(cur)
        lb = cur & -cur
        r = cur + lb
        cur = ((cur ^ r) // lb >> 2) | r
    return res

def solve():
    # key: 值域很小，可以^k-bit的msk(兩數之和+對稱去重)
    # GosperHack: 枚舉大小為k的所有集合
    # 值域很小: 使用數組紀錄比較快
    # !注意: 特判k==0(沒msk)
    
    m = max(a)
    cnt = [0] * (m + 1)
    for x in a:
        cnt[x] += 1
    
    if k == 0:
        print(sum(x * (x - 1) // 2 for x in cnt))
        return    
    
    ans = 0
    msks = GosperHack(m.bit_length(), k)
    for x in range(m + 1):
        for msk in msks:
            if x ^ msk <= m: 
                ans += cnt[x] * cnt[x ^ msk]
    print(ans // 2)

               
for _ in range(1):
    n, k = MII()
    a = list(MII())
    solve()