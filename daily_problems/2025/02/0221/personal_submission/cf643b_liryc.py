'''
https://codeforces.com/problemset/submission/643/307079693
'''
# 起点和终点构建一个三角形的环，中间点连一条直线，注意特判n=4时无解
def solve(n: int, k: int, a: int, b: int, c: int, d: int) -> list[list[int]]:
    if n == 4 or k < n + 1:
        return []
    ep = [a, b, c, d]
    p1 = [a, c] + [x for x in range(1, n + 1) if not x in ep] + [d, b]
    p2 = [c, a] + [x for x in range(1, n + 1) if not x in ep] + [b, d]
    return [p1, p2]