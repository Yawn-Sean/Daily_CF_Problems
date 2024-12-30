import sys
input = lambda: sys.stdin.readline().strip()
MII = lambda: map(int, input().split())  

def solve():
    # key: 確定關係只要不相等，WLOG可以規定u<v
    # 被規定兩個值就不能swap
    vis = set()
    for _ in range(m):
        i, j = MII()
        i -= 1
        j -= 1
        if i > j:
            i, j = j, i
        vis.add((i, j))
    
    flg = False
    for i in range(n):
        for j in range(i + 1, n):
            if (i, j) not in vis: # 第一組free元素
                si, sj = i, j
                flg = True
                break
        if flg: break
        
    if not flg: # 只有m==c(n,2)才會發生
        print('NO')
        return
    
    ans = [0] * n
    ans[si], ans[sj] = 1, 2
    cnt = 3
    for i in range(n):
        if ans[i] == 0:
            ans[i] = cnt
            cnt += 1
            if cnt == n + 1:
                break
    print('YES')
    print(*ans)
    
    ans[sj] = 1 # 先填改最小，後面也能符合(越填越大)
    print(*ans)
        
for _ in range(1):
    n, m = MII()
    solve()