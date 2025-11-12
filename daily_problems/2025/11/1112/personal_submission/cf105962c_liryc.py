'''
https://codeforces.com/gym/105962/submission/348587178
'''
# enumerations
def solve(n: int, a: list[list[int]]) -> int:
    if sum(sum(r) for r in a) == 0:
        return 0
    ans = 1 

    sc = [sum(a[r][c] for r in range(n)) for c in range(n)]

    for i, j in combinations(range(n), 2):
        nr, nc = 0, 0
        for c in range(n):
            if a[i][c] == a[j][c] == 1:
                nr += 1
                nc = max(nc, sc[c]) 
        ans = max(ans, min(nr, nc))
    return ans
