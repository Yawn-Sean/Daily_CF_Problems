'''
https://codeforces.com/problemset/submission/1423/317557140
'''
# 二分图匹配+二分
# ref
# def hopcroft_karp(graph, n, m):
def solve(n: int, m: int, edges: list[list[int]]) -> int:
    sa = list(sorted((d, u - 1, v - 1) for u, v, d in edges))
    def check(x):
        nonlocal n, sa
        ug = [[] for _ in range(n)]
        for d, u, v in sa:
            if d <= x:
                ug[u].append(v)
            else:
                break

        m1, m2 = hopcroft_karp(ug, n, n)
        if -1 in m1:
            return False
        else:
            return True
        
    maxd = sa[-1][0]
    ans = bisect_left(range(maxd + 1), True, key = check)
    return -1 if ans > maxd else ans
