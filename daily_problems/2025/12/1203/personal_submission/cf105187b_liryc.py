'''
https://codeforces.com/gym/105187/submission/351693461
'''
# counting, two pointers
def solve(n: int, p: list[int], a: list[int]) -> list[int]:
    si = list(sorted(range(n << 1), key = lambda i: -p[i]))
    i, j, pre = 0, 0, 0
    ans = [0] * (n << 1)
    while j < (n << 1):
        sb = p[si[j]]
        sa = sb + 3
        while p[si[i]] > sa:
            pre += 1
            i += 1
        cnt, adds, sames = 0, 0, 0
        while p[si[i]] == sa:
            sc = p[a[si[i]]]
            if sc == sa:
                adds += 1
                sames += 1
            elif sa - 2 <= sc <= sa - 1:
                adds += 1
            i += 1
            cnt += 1
        r = pre + adds - sames // 2 + 1
        while j < (n << 1) and p[si[j]] == sb:
            ans[si[j]] = r
            j += 1
        pre += cnt
    return ans
