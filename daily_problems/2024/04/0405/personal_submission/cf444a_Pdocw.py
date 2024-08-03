def main():
    n, m = MII()
    nums = [0] + LII()
    ans = 0
    for _ in range(m):
        u, v, w = MII()
        ans = max(ans, (nums[u] + nums[v]) / w)
    print(ans)
    return
