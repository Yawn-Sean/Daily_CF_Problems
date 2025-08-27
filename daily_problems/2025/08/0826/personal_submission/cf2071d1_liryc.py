'''
https://codeforces.com/problemset/submission/2071/335600716
'''
# 位运算，找规律
def solve(n: int, l: int, r: int, a: list[int]) -> int:
    pre = [0] * n
    for i, x in enumerate(a):
        pre[i] = x
        if i:
            pre[i] ^= pre[i - 1]
    for k in range(n + 1, 2 * n + 1):
        a.append(pre[k // 2 - 1])
    def calc(m):
        nonlocal n, a, pre
        h = m >> 1
        if m <= 2 * n:
            return a[m - 1]
        elif h <= n: 
            return pre[h - 1]
        elif n & 1:
            if h & 1:
                return pre[-1]
            else:
                return pre[-1] ^ calc(h)
        else:
            if h & 1:
                return pre[-1] ^ calc(n + 1)
            else:
                return pre[-1] ^ calc(n + 1) ^ calc(h)
    return calc(l)
