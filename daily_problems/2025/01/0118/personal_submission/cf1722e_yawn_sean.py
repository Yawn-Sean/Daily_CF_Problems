# Submission link: https://codeforces.com/contest/1722/submission/301498407
def main():
    t = II()
    pref = [[0] * 1001 for _ in range(1001)]

    outs = []
    for _ in range(t):
        n, q = MII()
        for _ in range(n):
            x, y = MII()
            pref[x][y] += x * y
        
        for i in range(1000):
            for j in range(1001):
                pref[i + 1][j] += pref[i][j]
        
        for i in range(1001):
            for j in range(1000):
                pref[i][j + 1] += pref[i][j]
        
        for _ in range(q):
            hs, ws, hb, wb = MII()
            outs.append(pref[hb - 1][wb - 1] - pref[hs][wb - 1] - pref[hb - 1][ws] + pref[hs][ws])
        
        for i in range(1001):
            for j in range(1001):
                pref[i][j] = 0

    print('\n'.join(map(str, outs)))