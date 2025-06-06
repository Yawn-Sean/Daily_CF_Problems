'''
https://codeforces.com/problemset/submission/605/318792066
'''
# mst, constructive
def solve(n: int, m: int, wa: list[list[int]]) -> list[str]:
    ans = [""] * m
    mi, j = 0, 1
    vis = [x + 1 for x in range(n)]
    for a, b, i in sorted((a, -b, i) for i, (a, b) in enumerate(wa)):
        if not b:
            while j < mi and vis[j] > mi:
                j += 1
            if j >= mi:
                return []
            ans[i] = f"{j + 1} {vis[j] + 1}"
            vis[j] += 1
        else:
            mi += 1
            ans[i] = f"1 {mi + 1}"
            j = 1
    return ans
