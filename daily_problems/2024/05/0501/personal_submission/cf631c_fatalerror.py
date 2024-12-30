"""
先操作的较短区间会被后操作的较长区间覆盖，因此只需要保留区间长度单调递减、并且前后两次操作类型不同的序列。
最终结果结果相当于在排序后的 arr[0...r0] 上作多次 arr[0...r_i] 的翻转。用双指针代替多次翻转的模拟。
"""

import sys
input = lambda: sys.stdin.readline().rstrip()
ii = lambda: int(input())
lii = lambda: list(map(int, input().split()))

def solve():
    n, m = lii()
    arr = lii()
    stk = []
    for _ in range(m):
        op = lii()
        op[1] -= 1
        while stk and stk[-1][1] <= op[1]:
            stk.pop()
        if not stk or stk[-1][0] != op[0]:
            stk.append(op)

    l, r = 0, stk[0][1]
    nums = sorted(arr[:r+1])

    pt = 0
    stk.append([1, -1])
    for idx in range(r, -1, -1):
        if idx == stk[pt+1][1]:
            pt += 1
        tp = stk[pt][0]
        if tp == 1:
            arr[idx] = nums[r]
            r -= 1
        else:
            arr[idx] = nums[l]
            l += 1

    return arr

print(*solve())