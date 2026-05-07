'''
https://codeforces.com/gym/106414/submission/373788907
Mex, simple greedy
'''

def solve(n: int, k: int, a: list[int]) -> list[int]:
    x = a[k - 1]
    vis = [False] * (x + 1)
    for i in range(n):
        if i != k - 1 and a[i] <= x:
            vis[a[i]] = True
    if not all(vis):
        return [-1, -1]
    return [k, n]
