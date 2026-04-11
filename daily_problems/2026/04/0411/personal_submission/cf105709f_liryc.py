'''
https://codeforces.com/gym/105709/submission/370670741
'''
# fenwick tree
def solve(n: int, k: int, ba: list[int], wa: list[int], va: list[int]) -> int:
    ft = FenwickTree(100001)
    j = 0
    si = list(sorted(range(n), key = lambda idx: ba[idx]))
    ans = 0
    while j < n:
        br = ba[si[j]]
        while j < n and ba[si[j]] <= br:
            i = si[j]
            j += 1
            w, v = wa[i], va[i]
            ft.add(w, v)
        ans = max(ans, ft.sum(k - br))
    return ans
