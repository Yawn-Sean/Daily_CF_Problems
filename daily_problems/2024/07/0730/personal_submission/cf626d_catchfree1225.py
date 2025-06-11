import sys
input = lambda: sys.stdin.readline().strip()
MII = lambda: map(int, input().split())

def solve():
    m = a[-1]
    cnt = [0] * m # 枚舉差值，避免每次枚舉n^2
    for i in range(n):
        for j in range(i + 1, n):
            cnt[a[j] - a[i]] += 1
    
    # Q: 為啥必須額外計算cnt2? 不能用背包枚舉差值嗎
    # A: 必須考慮排列組合，非線性
    cnt2 = [0] * m # 只需枚舉差值到m, 否則無法抵銷
    for i in range(m):
        for j in range(m):
            if i + j < m:
                cnt2[i + j] += cnt[i] * cnt[j]
    
    for i in range(m - 1):
        cnt2[i + 1] += cnt2[i]
    
    ans = 0
    for i in range(m):
        ans += cnt[i] * cnt2[i - 1]
        
    sz = n * (n - 1) // 2
    print(ans / sz**3)
         
for _ in range(1):
    n = int(input())
    a = sorted(MII())
    solve()