import sys
input = lambda: sys.stdin.readline().strip()
MII = lambda: map(int, input().split())
MOD = 998244353
MX = int(2e5 + 1)

vis1, vis2 = [-1] * MX, [-1] * MX # 多次testcase優化
def solve():
    # key: 著色覆蓋問題，倒序計算
    # 因為最後覆蓋的肯定留到最後，討論誰蓋誰較複雜
    # Q:如何判斷覆蓋？ A:討論行列對彼此的影響
    # 倒序枚舉每次染的行跟列都不同，對另一方向貢獻為1
    # 無法填列: 此列已填過(vis1[x]=t) or 行把列填滿(c2=n)
        
    xs, ys = [-1] * q, [-1] * q
    for i in range(q - 1, -1, -1):
        xs[i], ys[i] = MII()
    
    c1 = c2 = 0
    ans = 1
    for x, y in zip(xs, ys):
        if (vis1[x] != t and c2 < m) or (vis2[y] != t and c1 < n):
            ans = ans * k % MOD
            if vis1[x] != t:
                vis1[x] = t
                c1 += 1
            if vis2[y] != t:
                vis2[y] = t
                c2 += 1
    print(ans)
    
for t in range(int(input())):
    n, m, k, q = MII()
    solve()