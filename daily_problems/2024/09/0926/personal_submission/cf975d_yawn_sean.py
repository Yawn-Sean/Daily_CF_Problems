# Submission link: https://codeforces.com/contest/975/submission/282978189
def main():
    n, a, b = MII()

    vis1 = Counter()
    vis2 = Counter()

    ans = 0

    rnd = random.getrandbits(20)
    for _ in range(n):
        x, vx, vy = MII()
        
        ans += vis1[vy - a * vx + rnd]
        ans -= vis2[(vx, vy)]
        
        vis1[vy - a * vx + rnd] += 1
        vis2[(vx, vy)] += 1

    print(ans * 2)