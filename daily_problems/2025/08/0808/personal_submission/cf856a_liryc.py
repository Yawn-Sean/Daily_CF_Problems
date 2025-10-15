'''
https://codeforces.com/problemset/submission/856/332975287
'''
# brute-force

vis = [0] * 1000001
def solve(n: int, a: list[int]) -> list[int]:
    global vis

    for i in range(1, 1000001): 
        vis[i] = 0

    sa = list(set(abs(x - y) for x, y in combinations(a, 2)))
    ans = []
    x = 1
    while len(ans) < n:
        if not vis[x]:
            ans.append(x)
            for y in sa:
                sm = x + y
                if sm <= 1000000:
                    vis[sm] = 1
        x += 1
    return ans
