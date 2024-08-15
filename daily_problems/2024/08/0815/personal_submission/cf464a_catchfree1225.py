import sys
input = lambda: sys.stdin.readline().strip()
MII = lambda: map(int, input().split())

def solve():
    # Key: 原本字符串符合要求，只需檢查修改後是否正確
    # 回文中心基底: 偶數，奇數(往前check兩個)
    # 如何修改? 考慮前綴計算，比較好算最小字典序
    
    def checkPrefix(end: int, c: chr) -> bool:
        for i in range(max(end - 2, 0), end):
            if s[i] == c:
                return False
        return True
    
    for i in range(n - 1, -1, -1): # 從最後面開始填，一定是最小的
        for c in range(s[i] + 1, p):
            if checkPrefix(i, c):
                s[i] = c
                break
        else:
            continue
        
        for j in range(i + 1, n): # 構造剩餘字符串
            for c in range(p):
                if checkPrefix(j, c):
                    s[j] = c
                    break
        print(''.join(chr(x + 97) for x in s))
        return
        
    print('NO')         
    
               
for _ in range(1):
    n, p = MII()
    s = [ord(c) - 97 for c in input()]
    solve()