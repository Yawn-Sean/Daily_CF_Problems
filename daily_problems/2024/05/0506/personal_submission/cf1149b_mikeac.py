import sys

# region fastio
input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))
# endregion fastio

# MOD = 998_244_353
# MOD = 10 ** 9 + 7
# DIR4 = ((-1, 0), (0, 1), (1, 0), (0, -1)) #URDL
# DIR8 = ((-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1), (0, -1), (-1, -1))

def solve() -> None:
    n, q = mint()
    s = input()

    nxt = [[n] * 26 for _ in range(n + 2)]
    for i in range(n - 1, -1, -1):
        for j in range(26):
            nxt[i][j] = nxt[i + 1][j]
        nxt[i][ord(s[i]) - 97] = i

    m = 255

    dp = [n] * (m ** 3)
    dp[0] = -1

    cur = [0] * 3
    s = [[] for _ in range(3)]

    for _ in range(q):
        qry = input().split()
        idx = int(qry[1]) - 1
        if qry[0] == '-':
            s[idx].pop()
            cur[idx] -= 1
        else:
            c = ord(qry[2]) - 97

            mask = cur[:]
            mask[idx] += 1
            idx1, idx2 = (idx + 1) % 3, (idx + 2) % 3
            pmask = mask[:]
            for i in range(cur[idx1] + 1):
                for j in range(cur[idx2] + 1):
                    mask[idx1] = pmask[idx1] = i
                    mask[idx2] = pmask[idx2] = j
                    pmask[idx] = mask[idx] - 1
                    to = (mask[0] * m + mask[1]) * m + mask[2]
                    fr = (pmask[0] * m + pmask[1]) * m + pmask[2]
                    dp[to] = nxt[dp[fr] + 1][c]
                    if i:
                        pmask[idx1] = mask[idx1] - 1
                        pmask[idx2] = mask[idx2]
                        pmask[idx] = mask[idx]
                        fr = (pmask[0] * m + pmask[1]) * m + pmask[2]
                        if nxt[dp[fr] + 1][s[idx1][i - 1]] < dp[to]:
                            dp[to] = nxt[dp[fr] + 1][s[idx1][i - 1]]
                    if j:
                        pmask[idx1] = mask[idx1]
                        pmask[idx2] = mask[idx2] - 1
                        pmask[idx] = mask[idx]
                        fr = (pmask[0] * m + pmask[1]) * m + pmask[2]
                        if nxt[dp[fr] + 1][s[idx2][j - 1]] < dp[to]:
                            dp[to] = nxt[dp[fr] + 1][s[idx2][j - 1]]

            s[idx].append(c)
            cur[idx] += 1
        
        print('YES' if dp[(cur[0] * m + cur[1]) * m + cur[2]] < n else 'NO')

solve()
