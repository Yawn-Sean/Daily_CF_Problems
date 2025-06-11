# Submission link: https://codeforces.com/contest/799/submission/285243569
def main():
    a, b, h, w, n = MII()
    nums = LII()

    nums.sort(reverse=True)
    n = min(n, 34)

    def solve(x, y):
        vis = {}
        vis[(x, y)] = 0
        
        for i in range(n):
            for (x, y) in list(vis.keys()):
                nx = (x + nums[i] - 1) // nums[i]
                if (nx, y) not in vis:
                    vis[(nx, y)] = vis[(x, y)] + 1
                ny = (y + nums[i] - 1) // nums[i]
                if (x, ny) not in vis:
                    vis[(x, ny)] = vis[(x, y)] + 1
        
        return vis[(1, 1)] if (1, 1) in vis else inf

    ans = fmin(solve((a + h - 1) // h, (b + w - 1) // w), solve((a + w - 1) // w, (b + h - 1) // h))

    print(ans if ans < inf else -1)