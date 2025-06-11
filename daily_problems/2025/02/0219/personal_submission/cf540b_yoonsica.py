import sys
RI = lambda: int(sys.stdin.readline().strip())
RS = lambda: sys.stdin.readline().strip()
RII = lambda: map(int, sys.stdin.readline().strip().split())
RILIST = lambda: list(RII())
mx = lambda x, y: x if x > y else y
mn = lambda x, y: y if x > y else x

'''
https://codeforces.com/problemset/problem/540/B
长度为n的序列，给定k项，求剩下的n - k项
每一项范围[1, p]，要求中位数不小于y，和不大于x

小于y的数要小于(n + 1) // 2个, 这部分用1填充够了之后，大于等于y的部分全部用y填充
'''
n, k, p, x, y = RII()
a = RILIST()
s = cnt = 0 # cnt表示小于y的数
for e in a:
    s += e
    cnt += int(e < y)

if s + n - k > x:
    print(-1)
elif cnt >= (n + 1) // 2: # 即使后面全是y，中位数也小于y
    print(-1)
else:
    ans = []
    if y > 1:
        while cnt < (n + 1) // 2 - 1 and k < n:
            ans.append(1)
            s += 1
            cnt += 1
            k += 1
    # n - k项都填y
    ans += [y] * (n - k)
    s += y * (n - k)
    if s > x:
        print(-1)
    else:
        print(' '.join(map(str, ans)))
    