import sys
input = lambda: sys.stdin.readline().strip()
GMI = lambda: map(lambda x: int(x) - 1, input().split())

def build(n): # 預處理歌德巴赫pair
    primes = []
    is_prime = [False] * 2 + [True] * (n - 1)
    for i in range(2, n + 1): # !注意:找質數要全部遍歷
        if is_prime[i]:
            primes.append(i) 
            for j in range(i * i, n + 1, i):
                is_prime[j] = False
    
    divs = [0] * (n + 1) # 合為偶數的質數配對
    for i in range(4, n + 1, 2): 
        for p in primes:
            if is_prime[i - p]:
                divs[i] = p
                break
    return is_prime, divs

def solve():
    # key: 歌德巴赫猜想(>=4之偶數都可以表示為兩奇質數之和)
    # (數值驗證下，4e18範圍內整數都對)
    # 總op數小於5n, 確保每次操作數<5
    
    pos = [-1] * n # pos[x]->i:數值x在原本i位置
    for i, x in enumerate(a):
        pos[x] = i 
    
    is_prime, divs = build(n)
    ops = []
    def unit_swap(i, j):
        pos[a[i]], pos[a[j]] = pos[a[j]], pos[a[i]]
        a[i], a[j] = a[j], a[i]
        ops.append((i + 1, j + 1))
        
    def swap(i, j):             # 注意，只要確保每次操作小於五次就好
        if is_prime[j - i + 1]: # 不需要保證每次都會還原其他元素
            unit_swap(i, j)
            return
        # 歌德巴赫猜想需要是>=4偶數，統一+2
        if (j - i) % 2 == 0:
            v = j - i + 2
            unit_swap(i + divs[v] - 1, j)
            unit_swap(i, i + divs[v] - 1)
        else:
            i += 1
            v = j - i + 2 # 一定>=4? A:Yes(j-原i>=3，等於1會變成距離2為質數)
            unit_swap(i + divs[v] - 1, j)
            unit_swap(i, i + divs[v] - 1)
            unit_swap(i - 1, i) # 多一個還原動作
    
    for i, pi in enumerate(pos):
        if i != pi:
            swap(i, pi)
    
    print(len(ops))
    for op in ops:
        print(*op)
         
for _ in range(1):
    n = int(input())
    a = list(GMI())
    solve()