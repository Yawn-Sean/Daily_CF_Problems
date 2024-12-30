# Submission link: https://codeforces.com/contest/1132/submission/262070483
def main():
    n, q = MII()

    cur = [0] * n

    ls = []
    rs = []
    for _ in range(q):
        l, r = GMI()
        ls.append(l)
        rs.append(r)
        
        for i in range(l, r + 1):
            cur[i] += 1

    acc = [0] * (n + 1)
    ans = 0

    for i in range(q):
        l, r = ls[i], rs[i]
        for j in range(l, r + 1):
            cur[j] -= 1
        
        cnt = 0
        for j in range(n):
            acc[j+1] = acc[j]
            if cur[j] >= 1: cnt += 1
            if cur[j] == 1: acc[j+1] += 1
        
        for j in range(i):
            ans = max(ans, cnt - (acc[rs[j]+1] - acc[ls[j]]))
        
        for j in range(l, r + 1):
            cur[j] += 1

    print(ans)