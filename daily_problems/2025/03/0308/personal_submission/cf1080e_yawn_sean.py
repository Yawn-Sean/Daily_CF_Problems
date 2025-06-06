# Submission link: https://codeforces.com/contest/1080/submission/309426046
def main():
    n, m = MII()
    grid = [[ord(c) - ord('a') for c in I()] for _ in range(n)]

    hsh = [1] * 26
    hsh[1] = random.randint(1000, 2000)
    mod = random.getrandbits(60)

    for i in range(2, 26):
        hsh[i] = hsh[i - 1] * hsh[1] % mod

    def f(cur):
        tmp = [-1]
        for v in cur:
            tmp.append(v)
            tmp.append(-1)
        
        res = 0
        k = len(tmp)
        wing = [0] * k
        
        chosen_idx = 0
        for i in range(k):
            if chosen_idx + wing[chosen_idx] >= i:
                wing[i] = fmin(chosen_idx + wing[chosen_idx] - i, wing[2 * chosen_idx - i])
            while i > wing[i] and i + 1 + wing[i] < k and tmp[i - wing[i] - 1] == tmp[i + wing[i] + 1]: wing[i] += 1
            res += (wing[i] + 1) // 2
            if i + wing[i] > chosen_idx + wing[chosen_idx]:
                chosen_idx = i

        return res

    ans = 0
    for j1 in range(m):
        msk = [0] * n
        tmp = [0] * n
        for j2 in range(j1, m):
            for i in range(n):
                msk[i] ^= 1 << grid[i][j2]
                tmp[i] += hsh[grid[i][j2]]
                if tmp[i] >= mod: tmp[i] -= mod
            
            cur = []
            for i in range(n):
                if msk[i] & -msk[i] == msk[i]:
                    cur.append(tmp[i])
                else:
                    ans += f(cur)
                    cur.clear()
            
            ans += f(cur)

    print(ans)