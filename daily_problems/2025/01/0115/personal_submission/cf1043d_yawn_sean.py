# Submission link: https://codeforces.com/contest/1043/submission/301036401
def main():
    n, m = MII()

    ars = [LII() for _ in range(m)]
    pos = [[0] * (n + 1) for _ in range(m)]

    for i in range(m):
        for j in range(n):
            pos[i][ars[i][j]] = j

    ans = 0
    l = 0
    while l < n:
        r = l
        while r + 1 < n:
            flg = True
            for i in range(1, m):
                if pos[i][ars[0][r + 1]] - pos[i][ars[0][r]] != 1:
                    flg = False
            if not flg: break
            r += 1
        ans += (r - l + 1) * (r - l + 2) // 2
        l = r + 1

    print(ans)