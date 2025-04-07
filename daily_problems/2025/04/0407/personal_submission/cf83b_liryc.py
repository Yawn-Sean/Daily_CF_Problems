'''
https://codeforces.com/problemset/submission/83/314329463
'''
# Binary Search for round r

def solve(n: int, k: int, a: list[int]) -> list[int]:
    sm = sum(a)
    if sm < k:
        return [-1]
    elif sm == k:
        return []
    max_r = max(a)

    def check(t):
        nonlocal a
        return sum(pmin(x, t) for x in a)        

    r = bisect_right(range(max_r + 1), k, key=check) - 1
    k -= check(r)
    ans, suf = [], []
    for i in range(n):
        x = a[i] - r
        if x > 0:
            if k:
                x -= 1
                k -= 1
                if x:
                    suf.append(i + 1)
            else:
                ans.append(i + 1)
    return ans + suf
