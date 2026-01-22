'''
https://codeforces.com/gym/103185/submission/359168581
'''
def solve(n: int, a: list[int]) -> bool:
    up, down = [0] * n, [0] * n
    last_pos, last_cmp = 0, -1
    for i, x in enumerate(a):
        if x > last_cmp:
            up[i] = last_pos = i
        else:
            up[i] = last_pos
        if x > 0:
            last_cmp = x
    last_pos, last_cmp = n - 1, -1
    for i in range(n - 1, -1, -1):
        x = a[i]
        if x > last_cmp:
            down[i] = last_pos = i
        else:
            down[i] = last_pos
        if x > 0:
            last_cmp = x
    for k in range(3, n + 1):
        if 1 <= n % k <= 2:
            continue
        for l in range(0, n, k):
            r = min(n - 1, l + k - 1)
            if up[r] > down[l] or up[r] == r or down[l] == l:
                break
        else:
            return True
    return False
