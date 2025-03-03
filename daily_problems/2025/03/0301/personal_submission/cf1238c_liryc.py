'''
https://codeforces.com/problemset/submission/1238/308437623
'''
# 对于每一个y，只有y和y-1同时存在时不需要用魔晶，否则使用魔晶到达y-1
def solve(h: int, n: int, a: list[int]) -> int:
    i, ans = 1, 0
    while i < n:
        y = a[i]
        if h > y + 1: 
            h = y + 1
        if h <= 2:
            break
        if i + 1 < n and a[i + 1] == y - 1:
            h = y - 1
            i += 2
        else:
            ans += 1
            h = y - 1
            i += 1
    return ans
