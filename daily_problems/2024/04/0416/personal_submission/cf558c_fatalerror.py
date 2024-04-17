"""
先寻找所有数字的最长公共前缀pref，pref无需变动。对于数字除去pref的后缀部分：首先需要应用右移操作使后缀不含1；然后再应用左移或右移操作使后缀0的个数相同，这一步可以在得到所有数字后缀0的个数以后通过中位数贪心计算。
"""

import sys
input = lambda: sys.stdin.readline().rstrip()
ii = lambda: int(input())
lii = lambda: list(map(int, input().split()))

def solve():
    n = ii()
    arr = lii()
    mx = max(arr)
    cnt = [0] * (mx+1)
    for x in arr:
        while x:
            cnt[x] += 1
            x >>= 1
    pref = max(range(mx, 0, -1), key=cnt.__getitem__)

    ans = 0
    rem = []
    for x in arr:
        for i in range(x.bit_length()):
            if x >> i == pref:
                x -= pref << i
                j = x.bit_length()
                ans += j
                rem.append(i-j)
                break

    rem.sort()
    mid = rem[n//2]
    ans += sum(abs(i-mid) for i in rem)
    return ans

print(solve())