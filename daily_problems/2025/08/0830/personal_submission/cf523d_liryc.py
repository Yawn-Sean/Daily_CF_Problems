'''
https://codeforces.com/problemset/submission/523/336237271
'''
# 任务管理，优先队列
def solve(n: int, k: int, a: list[list[int]]) -> list[int]:
    ans = []
    hp = [0] * k
    for s, m in a:
        t = max(s, hp[0]) + m
        ans.append(t)
        heapreplace(hp, t)
    return ans
