import sys
input = lambda: sys.stdin.readline().strip()
MII = lambda: map(int, input().split())

def solve():
    # Key: 狀態數很少，使用sosdp技巧預處理數組
    # !注意: 相同位的處理->使用u
    
    cnt = [0] * (1 << n)
    for _ in range(m):
        cnt[int(input(), 2)] += 1
    
    val = [0] * (1 << n) # val[s]: 相同位置狀態對應之w和
    for i in range(1, 1 << n): # 類sosdp
        x = i & -i
        val[i] = val[i ^ x] + w[n - x.bit_length()]
    
    ans = [[0] * (1 << n) for _ in range(101)]
    u = (1 << n) - 1
    for x in range(1 << n):
        for y in range(1 << n): # 注意不能直接add，也可以0相同
            if (ki := val[u ^ (x ^ y)]) < 101:
                ans[ki][x] += cnt[y]
        for ki in range(100):
            ans[ki + 1][x] += ans[ki][x]
    
    for _ in range(q):
        t, k = input().split()
        t, k = int(t, 2), int(k)
        print(ans[k][t])
        
                
for _ in range(1):
    n, m, q = MII()
    w = list(MII())
    solve()