import sys
input = lambda: sys.stdin.readline().strip()

def solve():
    m = n * 2
    zeros = a.count(0)
    non_zeros = m - zeros
    
    # 往下平移所有數字後，變成面積增減問題
    # 只有非零的數字可被提升為1
    # 非零數字or零都可被降為0
    # 因為有2n數字，配對一定足夠，只需考慮提升多少1即可
    # 最多1: 非零數量，最少1: n - 提升零
    # 自然限制: 邊界>=0, <=n
    tot = sum(a)
    ans = 1000 * m
    max_non_zeros = min(non_zeros, n)
    min_non_zeros = max(n - zeros, 0)
    for i in range(min_non_zeros, max_non_zeros + 1):
        new_sum = i * 1000
        ans = min(ans, abs(new_sum - tot))
    
    p, q = divmod(ans, 1000)    
    ans = str(p) + '.' + str(q).zfill(3)
    print(ans)
               
for _ in range(1):
    n = int(input())
    a = [int(s.split('.')[1]) for s in input().split()] # 存小數，新技巧
    solve()