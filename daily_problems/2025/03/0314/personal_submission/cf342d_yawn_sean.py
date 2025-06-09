# Submission link: https://codeforces.com/contest/342/submission/310495611
def main():
    n = II()
    note = [[0] * n for _ in range(3)]

    x, y = -1, -1
    for i in range(3):
        s = I()
        for j in range(n):
            if s[j] == 'X': note[i][j] = 1
            elif s[j] == 'O':
                note[i][j] = 2
                x, y = i, j

    dirs = [(-1, 0), (0, 1), (1, 0), (0, -1)]
    chosen = []

    for dx, dy in dirs:
        flg = True
        for i in range(1, 3):
            vx, vy = x + dx * i, y + dy * i
            if not (0 <= vx < 3 and 0 <= vy < n and note[vx][vy] == 0):
                flg = False
        if flg:
            chosen.append((dx, dy))

    k = len(chosen)
    ans = 0
    mod = 10 ** 9 + 7

    for msk in range(1, 1 << k):
        c = -1
        for i in range(k):
            if msk >> i & 1:
                c = -c
                dx, dy = chosen[i]
                for j in range(1, 3):
                    note[x + dx * j][y + dy * j] = 1

        dp = [0] * 8
        dp[0] = 1
        
        ndp = [0] * 8
        
        for i in range(n):
            must = 0
            for j in range(3):
                if note[j][i]:
                    must |= 1 << j
            
            for v0 in range(8):
                for v1 in range(8):
                    if v1 & must == 0 and v0 & v1 == 0 and v0 & must == 0 and (7 - v1 - must - v0) % 3 == 0:
                        ndp[v1] += dp[v0]
                        if ndp[v1] >= mod:
                            ndp[v1] -= mod

            for j in range(8):
                dp[j] = ndp[j]
                ndp[j] = 0
        
        ans += c * dp[0]
        
        for i in range(k):
            if msk >> i & 1:
                dx, dy = chosen[i]
                for j in range(1, 3):
                    note[x + dx * j][y + dy * j] = 0

    print(ans % mod)