# https://codeforces.com/problemset/problem/891/A
# 每次只能将相邻两个元素的其中一个替换为 gcd(a1, a2) 求数组全变1的最少操作次数

def solve():
    n = II()
    a = LII()
    # 如果数组中有1，则答案是n-cnt(1)
    if a.count(1):
        print(n - a.count(1))
        return
    # 构造一个最小的区间[L,R] 使gcd(L,R) = 1
    t = 0x3f3f3f
    for i in range(n):
        g = 0
        for j in range(i, n):
            g = gcd(g, a[j])
            if g == 1:
                t = min(t, j - i)
                break
    if t == 0x3f3f3f:
        print(-1)
    else:
        print(t + n - 1)
        
def main():
    t = 1
    for _ in range(t):
        solve()

main()
