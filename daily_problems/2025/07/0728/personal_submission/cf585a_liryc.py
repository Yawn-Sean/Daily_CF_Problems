'''
https://codeforces.com/problemset/submission/585/331276960
'''
# brute-force
def solve(n: int, v: list[int], d: list[int], p: list[int]) -> list[int]:
    i = 0
    leave = [False] * n
    ans = []
    while True:
        while i < n and leave[i]:
            i += 1
        if i >= n:
            break
        ans.append(i + 1)
        v1, d1, j = v[i], 0, i + 1
        while (v1 or d1) and j < n:
            if leave[j]:
                j += 1
            else:
                p[j] -= v1 + d1
                if p[j] < 0:
                    leave[j] = True
                    d1 += d[j]
                if v1:
                    v1 -= 1
                j += 1
        i += 1
    return ans

