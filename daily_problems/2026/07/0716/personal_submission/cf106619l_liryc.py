'''
https://codeforces.com/gym/106619/submission/382882733
LIS, simple math
'''
def solve(n: int, k: int, a: list) -> list[int]:
    ans, lis = [], []
    sm = 0
    for x in a:
        sm += x
        if not lis or lis[-1] < x:
            lis.append(x)
        else:
            f = bisect_left(lis, x)
            lis[f] = x
        r = len(lis)
        if r > lis[-1]:
            ans.append(sm + (r + r + k - 1) * k // 2)
        else:
            ans.append(sm + r * k)
    return ans
