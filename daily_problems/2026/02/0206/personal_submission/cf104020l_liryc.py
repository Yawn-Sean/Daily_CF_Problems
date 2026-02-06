'''
Docstring for daily_problems.2026.02.0206.personal_submission.cf104020l_yawn_sean
'''
def solve(n: int, pa: list[list[int]]) -> float:
    pa.sort()
    ans = 4 * 10 ** 18
    
    for i in range(n):
        x1, y1, z1 = pa[i]
        for j in range(max(i - 100, 0), i):
            x2, y2, z2 = pa[j]
            ans = min(ans, (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) + (z2 - z1) * (z2 - z1))
    
    return ans ** 0.5