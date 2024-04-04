# Submission link: https://codeforces.com/contest/1468/submission/254909292
def main():
    t = II()
    outs = []

    for _ in range(t):
        n = II()
        ans = 0
        cnt = Counter()
        
        for _ in range(n):
            x, y, u, v = MII()
            dx = u - x
            dy = v - y
            g = math.gcd(dx, dy)
            dx //= g
            dy //= g
            
            ans += cnt[(-dx, -dy)]
            cnt[(dx, dy)] += 1
        
        outs.append(ans)

    print('\n'.join(map(str, outs)))