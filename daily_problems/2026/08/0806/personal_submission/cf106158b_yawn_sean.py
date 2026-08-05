# Submission link: https://codeforces.com/gym/106158/submission/385710487
def main():
    n, q = MII()
    updates = [[] for _ in range(n + 1)]
    
    for _ in range(q):
        f, s, c = MII()
        s = math.gcd(s, n)
        if len(updates[s]) == 0:
            updates[s] = [0] * s
        updates[s][(f - 1) % s] += c
    
    ans = [0] * n
    
    for i in range(n + 1):
        if updates[i]:
            for j in range(i):
                for k in range(j, n, i):
                    ans[k] += updates[i][j]
    
    print(ans.index(max(ans)) + 1)