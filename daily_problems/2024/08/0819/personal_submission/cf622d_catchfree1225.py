import sys
input = lambda: sys.stdin.readline().strip()

def solve():
    # Key: 整理式子後，發現距離只與(n-i)有關
    # 從i最小開始構造，討論構造方法:
    # 包起來(dist差2)->奇偶性分組 
    # d=1,3,5,...可以完全包圍區間
    # d=2,4,6,...中間會空一格
    # 空格跟最右邊塞剩下的n
    
    odd, even = [], []
    for i in range(1, n):
        if i & 1:
            odd.append(i)
        else:
            even.append(i)
    
    ans = [0] * (n * 2)
    i = 0
    for x in odd:
        d = n - x
        ans[i] = ans[i + d] = x
        i += 1
    
    if odd:
        i = n - odd[0] + 1
        for x in even:
            d = n - x
            ans[i] = ans[i + d] = x
            i += 1
    
    for i, x in enumerate(ans):
        if x == 0:
            ans[i] = n
    print(*ans)
    
                
for _ in range(1):
    n = int(input())
    solve()