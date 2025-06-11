"""
question: https://codeforces.com/problemset/problem/33/B
submission: https://codeforces.com/contest/33/submission/266252436
"""

def main(ac=FastIO()):
    str1, str2 = ac.read_str(), ac.read_str() 
    n = ac.read_int()
    if len(str1) != len(str2):
        ac.st(-1)
        return  
    w = [[ac.inf32] * 26 for _ in range(26)]
    for _ in range(n):
        a, b, c = ac.read_str().split()
        a = ord(a) - ord('a')
        b = ord(b) - ord('a')
        c = int(c)
        w[a][b] = min(w[a][b], c)

    for i in range(26): w[i][i] = 0
    fin = 0
    outs = []

    for k in range(26):
        for i in range(26):
            for j in range(26):
                w[i][j] = min(w[i][j], w[i][k] + w[k][j])

    def upd(x: int, y: int) -> int:
        res = 10 ** 7
        ans = -1
        for tgt in range(26):
            if res > w[x][tgt] +w[y][tgt]:
                res = w[x][tgt] +w[y][tgt]
                ans = tgt  
        return res, ans

    for x, y in zip(str1, str2):
        if x == y: 
            outs.append(x)
        else: 
            res, ans = upd(ord(x) - ord('a'), ord(y) - ord('a'))
            if ans == -1:
                ac.st(-1)
                return 
            fin += res
            outs.append(chr(ans + ord('a')))

    ac.st(f"{fin}\n{''.join(outs)}")
