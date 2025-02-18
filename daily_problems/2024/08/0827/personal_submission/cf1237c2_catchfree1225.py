import sys
input = lambda: sys.stdin.readline().strip()
MII = lambda: map(int, input().split())

def solve():
    # key: 降維計算 + 處理餘項的技巧
    # 能直接與相鄰項合併，只有其他軸都一樣時
    # (引用同一個list, 分批處理)
    
    p = [[-1] * n for _ in range(3)]
    for i in range(n):
        p[0][i], p[1][i], p[2][i] = MII()
    
    outs = []
    def snap(lst):
        while len(lst) >= 2:
            i1, i2 = lst.pop(), lst.pop()
            outs.append((i1 + 1, i2 + 1))
        return lst
    
    def reduct_dim(lst, k): 
        a = p[k - 1]
        lst.sort(key=lambda x: a[x])
        if k == 1:
            return snap(lst)
        tmp, rest = [], []
        for i in lst:
            if not tmp or a[tmp[-1]] == a[i]:
                tmp.append(i)
            else:
                rest.extend(reduct_dim(tmp, k - 1))
                tmp = [i]
        rest.extend(reduct_dim(tmp, k - 1))
        return snap(rest)
    
    lst = list(range(n))
    reduct_dim(lst, 3) # 題目給定偶數點，一定能消完
    for out in outs:   # 不用再檢查rest是否為空
        print(*out)
        
     
for _ in range(1):
    n = int(input())
    solve()