'''
https://codeforces.com/problemset/submission/1227/306943666
'''
# 没有限制操作次数，直接构建答案然后与原串比较即可
def solve(n: int, k: int, s: str) -> list[str]:
    target = '(' * (n // 2 - k + 1) + ')' * (n // 2 - k + 1) + '()' * (k - 1)
    ans = []
    a = [c for c in s]
    for i in range(n):
        if a[i] != target[i]:
            for j in range(i + 1, n):
                if a[j] == target[i]:
                    l, r = i, j
                    ans.append(f'{l + 1} {r + 1}')
                    while l < r:
                        a[l], a[r] = a[r], a[l]
                        l, r = l + 1, r - 1
                    break
    return ans
