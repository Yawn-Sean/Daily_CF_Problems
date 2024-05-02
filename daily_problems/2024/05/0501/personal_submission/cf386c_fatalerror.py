"""
对 s 的子串 t ， d(t)<=d(s)<=26 。
可以从 1 到 d(s) 枚举不同字母种类数 k 。每次计算时利用同向双指针，对右端点为 i 的子串 t ，计算 d(t)=k 的左端点的可能区间 [j1, j2] 。
"""

import sys
input = lambda: sys.stdin.readline().rstrip()

nums = [ord(ch)-97 for ch in input()]

def calc(k):
    ans = 0
    cnt1 = [0] * 26
    cnt2 = [0] * 26
    j1, j2 = 0, 0
    tp1, tp2 = 0, 0
    for x in nums:
        if cnt1[x] == 0:
            tp1 += 1
        cnt1[x] += 1
        if cnt2[x] == 0:
            tp2 += 1
        cnt2[x] += 1
        while tp1 == k:
            y = nums[j1]
            cnt1[y] -= 1
            if cnt1[y] == 0:
                tp1 -= 1
            j1 += 1
        while tp2 > k:
            y = nums[j2]
            cnt2[y] -= 1
            if cnt2[y] == 0:
                tp2 -= 1
            j2 += 1
        if tp2 == k:
            ans += j1-j2
    return ans

n = len(set(nums))
print(n)
for k in range(1, n+1):
    print(calc(k))