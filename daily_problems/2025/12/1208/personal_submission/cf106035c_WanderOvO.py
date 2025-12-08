import sys
from collections import defaultdict

"""
求一个形如 (1000...010...0) 的二进制数的 k 次方中有多少个 1
(8 + 2)^3 = (1010)^3
(1010)^2 = 1100100
我们知道，* 2 就是左移，不影响 1 的个数
现在乘的是 10，把 * 10 当成 * 8 和 * 2 的和？
1010000
  10100
1100100
其实还有个关键的特点，就是 (2^m + 2^n) 至多只有 2 个位为 1
以及 k 不大
每次多乘一个 2^m + 2^n，本质上至多增加 2 个新的为 1 的位
所以为 1 的位的数量到计算结束都不会很多
为 0 的位我们毫不关心，这样要考虑的就很少了

我们使用 map 记录 pos 位的 1 的个数吧
每次乘时，相当于创建两个新的 map，把当前的 map 做两次“移位”
然后把两个 map merge 起来，处理进位
"""

def solve():
    n, m, k = map(int, input().split())

    if k == 0:
        print(1)
        return

    cnt = defaultdict(int)

    if n == m:
        cnt[n + 1] = 1
    else:
        cnt[n] = 1
        cnt[m] = 1
    
    for _ in range(2, k + 1):
        new_cnt = defaultdict(int)
        for pos, one_cnt in cnt.items():
            new_cnt[pos + n] += one_cnt
            new_cnt[pos + m] += one_cnt
        cnt = new_cnt
    
    while True:
        to_check = [pos for pos, val in cnt.items() if val > 1]
        
        if not to_check:
            break
        
        to_check.sort()
        
        for pos in to_check:
            c = cnt[pos]
            
            if c <= 1:
                continue
            
            carry = c // 2
            cnt[pos] %= 2
            
            i = pos + 1

            while carry > 0:
                cnt[i] += carry
                carry = cnt[i] // 2
                cnt[i] %= 2
                i += 1
            
    res = 0
    for val in cnt.values():
        if val == 1:
            res += 1
            
    print(res)

solve()
