'''
https://codeforces.com/problemset/submission/847/316635521
'''
# 括号嵌套等同于构造一棵树，嵌套的总数等于树节点的深度之和，因此k<=n(n-1)/2的话，总能构造出一个最多两个分叉的树满足题目要求
def solve(n: int, k: int) -> str:
    if k == 0:
        return "()" * n
    m = (n - 1) * n // 2
    if m == k:
        return '(' * n + ')' * n
    elif m > k:
        l = bisect_right(range(n + 1), k, key = lambda x: (x - 1) * x // 2) - 1
        r = k - (l - 1) * l // 2 + 1
        return '(' * l + ')' * (l - r + 1) + '()' + ')' * (r - 1) + '()' * max(n - l - 1, 0)
    else:
        return "Impossible"
