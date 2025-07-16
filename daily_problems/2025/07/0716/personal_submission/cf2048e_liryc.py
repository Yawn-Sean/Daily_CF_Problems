'''
https://codeforces.com/problemset/submission/2048/329128788
'''
def solve(n: int, m: int) -> list[list[int]]:
    return [] if m >= n << 1 else [[(i + j) % (n << 1) // 2 + 1 for j in range(m)] for i in range(n << 1)]
