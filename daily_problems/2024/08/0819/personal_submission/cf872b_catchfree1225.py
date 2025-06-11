import sys
input = lambda: sys.stdin.readline().strip()
MII = lambda: map(int, input().split())

def solve():
    # key: 先抓兩個exit_node, 構造出具體直徑大小
    # 把新鏈掛在經過直徑的點上，距離兩端的長度不可吃過鏈長
    # 平均考慮，掛在中間最好，因此鏈長為扣掉根節點後的平均
    
    sz, rest = divmod(n - 1, k) # 不整除就把rest平分，最多多2(餘數)
    diameter = sz * 2 + min(rest, 2)
    print(diameter)
    
    outs = []
    for i in range(2, k + 2): # 接到根結點上(餘數分組)
        outs.append((1, i))   # 0,1,2,3,...,k-1 (mod k)
    for i in range(k + 2, n + 1): # 每個節點往下接(同鏈同餘)
        outs.append((i - k, i))   # 一次接一層
    
    for out in outs:
        print(*out)
        
for _ in range(1):
    n, k = MII()
    solve()