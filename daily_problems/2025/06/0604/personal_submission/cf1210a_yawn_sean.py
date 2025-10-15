# Submission link: https://codeforces.com/contest/1210/submission/322784207
def main():
    n, m = MII()
    pairs = []

    for _ in range(m):
        u, v = GMI()
        pairs.append((u, v))

    if n <= 6: print(m)
    else:
        ans = 0
        for i in range(n):
            for j in range(i):
                vis = set()
                for u, v in pairs:
                    if u == i: u = j
                    if v == i: v = j
                    if u > v: u, v = v, u
                    vis.add((u, v))
                ans = fmax(ans, len(vis))
        
        print(ans)