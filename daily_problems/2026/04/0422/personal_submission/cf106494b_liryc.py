'''
https://codeforces.com/gym/106494/submission/372090240
simple math
'''
def solve(n: int, la: list[int], ra: list[int]) -> list[int]:
    mli = max(range(n), key = lambda i: la[i])
    if sum(ra) - ra[mli] >= la[mli]:
        ans = []
        for i in range(n):
            if i == mli:
                ans.append(la[i])
            elif ra[i] > la[mli]:
                ans.append(la[mli])
            else:
                ans.append(ra[i])
        return ans
    else:
        return [-1]
