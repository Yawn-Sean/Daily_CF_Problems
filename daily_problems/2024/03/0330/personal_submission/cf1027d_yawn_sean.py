def main():
    n = II()
    nums = LII()
    perm = LGMI()

    in_circle = perm[:]
    for _ in range(n.bit_length() + 1):
        in_circle = [in_circle[i] for i in in_circle]

    vis = [0] * n
    for x in in_circle:
        vis[x] = 1

    ans = 0
    for i in range(n):
        if vis[i]:
            res = inf
            while vis[i]:
                vis[i] = 0
                res = min(res, nums[i])
                i = perm[i]
            ans += res

    print(ans)