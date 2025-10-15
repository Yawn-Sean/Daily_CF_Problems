'''
https://codeforces.com/problemset/submission/1017/304798767
'''
def solve(n: int) -> list[int]:
    ans = []
    sr = int(n ** 0.5)
    for i in range(1, n // sr + 2):
        for j in range(i * sr, (i - 1) * sr, -1):
            if 1 <= j <= n:
                ans.append(j)
    return ans
