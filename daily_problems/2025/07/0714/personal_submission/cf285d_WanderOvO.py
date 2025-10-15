"""
固定第一个数组为 0, 1, ... n - 1，只看第二个数组怎么搞
折半，对于左边，跑 A(n, n / 2)，右边跑 A(n, n - n / 2)，记录下来每个结果用了哪些数以及算出来哪些 c 中的值
枚举左边的结果，假设用的数字为 used，算出的 c 的值为 calculated
则右边应该是用的数字为 (1 << n) - 1 - used，算出来的 c 的值为 (1 << n) - 1 - calculated
"""
from collections import defaultdict

def print_table():
    mod = int(1e9 + 7)
    res = [0 for _ in range(17)]
    for n in range(1, 16, 2):
        cnt1, cnt2 = defaultdict(int), defaultdict(int)
        vis1, vis2 = [False for _ in range(n)], [False for _ in range(n)]
    
        def dfs1(step, max_step, used_b, calculated_c):
            if step == max_step:
                cnt1[(used_b, calculated_c)] += 1
                return
    
            for i in range(n):
                if not vis1[i] and not vis2[(i + step) % n]:
                    vis1[i] = True
                    vis2[(i + step) % n] = True
                    dfs1(step + 1, max_step, used_b | (1 << i), calculated_c | (1 << ((i + step) % n)))
                    vis1[i] = False
                    vis2[(i + step) % n] = False
    
    
        def dfs2(step, max_step, used_b, calculated_c):
            if step == max_step:
                cnt2[used_b, calculated_c] += 1
                return
    
            for i in range(n):
                if not vis1[i] and not vis2[(i + step + n // 2) % n]:
                    vis1[i] = True
                    vis2[(i + step + n // 2) % n] = True
                    dfs2(step + 1, max_step, used_b | (1 << i), calculated_c | (1 << ((i + step + n // 2) % n)))
                    vis1[i] = False
                    vis2[(i + step + n // 2) % n] = False
    
        dfs1(0, n // 2, 0, 0)
        dfs2(0, n - n // 2, 0, 0)
    
        ans = 0
        for key, value in cnt1.items():
            another_used_b = (1 << n) - 1 - key[0]
            another_calculated_c = (1 << n) - 1 - key[1]
            if cnt2.get((another_used_b, another_calculated_c)):
                ans += value * cnt2[(another_used_b, another_calculated_c)]
        for i in range(1, n + 1):
            ans *= i
        ans %= mod
        res[n] = ans
    print(res)

res = [0, 1, 0, 18, 0, 1800, 0, 670320, 0, 734832000, 0, 890786230, 0, 695720788, 0, 150347555, 0]
n = int(input())
print(res[n])
