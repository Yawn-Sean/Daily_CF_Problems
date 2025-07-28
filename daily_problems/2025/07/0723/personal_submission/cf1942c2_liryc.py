'''
https://codeforces.com/problemset/submission/1942/330476946
'''
# greedy + counting
def solve(n: int, x: int, y: int, a: list[int]) -> int:
    a.sort()
    ans = x - 2
    ds = [j - i for i, j in pairwise(a)]
    ds.append(a[0] + n - a[-1])
    ds.sort(key=lambda d: (d & 1, d))
    for d in ds:
        if d & 1:
            ac = d - 1 >> 1
            if y >= ac:
                y -= ac
                ans += d - 1
            elif y > 0:
                ans += y << 1
                y = 0
        else:
            if d == 2:
                ans += 1
            else:
                ac = d // 2 - 1
                if y >= ac:
                    y -= ac
                    ans += d - 1
                elif y > 0:
                    ans += y << 1
                    y = 0
    return ans
