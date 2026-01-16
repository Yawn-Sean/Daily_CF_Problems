'''
https://codeforces.com/gym/104375/submission/358064879
'''
# brute-force
def solve(n: int, q: int, a: list[int], qa: list[list[int]]) -> list[int]: 
    a.sort()
    ans = []
    for t, *r in qa:
        if t == 1:
            k = r[0]
            if k > a[-1]:
                a.append(k)
            else:
                i = bisect_left(a, k)
                a[i] = k
        else:
            lo, hi = r
            ans.append(bisect_right(a, hi) - bisect_left(a, lo))
    return ans
