'''
https://codeforces.com/problemset/submission/1923/330078036
'''
# prefix sum, binary search
pmin = lambda x, y: y if x < 0 or y >= 0 and y < x else x
def solve(n: int, a: list[int]) -> list[int]:
    def solvecore(a):
        nonlocal n
        pre = [0] * n
        sa = [0] * n
        for i, x in enumerate(a):
            pre[i] = x
            sa[i] = 1
            if i:
                pre[i] += pre[i - 1]
                if x == a[i - 1]:
                    sa[i] += sa[i - 1]
        # check if [i..j] can eat [j]
        def check(i, j):
            nonlocal n, a, pre, sa
            if i < 0:
                return True
            if i == j:
                return False
            if pre[j - 1] - (0 if i == 0 else pre[i - 1]) <= a[j]:
                return False
            if j - i > 1 and sa[j - 1] >= j - i:
                return False
            return True
        ans = [0] * n
        for j in range(n):
            if j == 0:
                ans[j] = -1
                continue
            elif a[j - 1] > a[j]:
                ans[j] = 1
                continue
            l, r = -1, j
            while l < r:
                m = l + r + 1 >> 1
                if check(m, j):
                    l = m
                else:
                    r = m - 1
            ans[j] = -1 if l < 0 or l == j else j - l
        return ans
    a1 = solvecore(a)
    a2 = solvecore(a[::-1])
    return [pmin(x, y) for x, y in zip(a1, a2[::-1])]
