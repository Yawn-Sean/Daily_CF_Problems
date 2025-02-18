# Submission link: https://codeforces.com/contest/850/submission/278574876
def main():
    n = II()
    if n >= 34:
        print(0)
    else:
        pts = [[] for _ in range(5)]
        for _ in range(n):
            pos = LII()
            for i in range(5):
                pts[i].append(pos[i])
        
        outs = []
        for i in range(n):
            flg = True
            for j in range(n):
                for k in range(j):
                    cur = 0
                    for d in range(5):
                        cur += (pts[d][k] - pts[d][i]) * (pts[d][j] - pts[d][i])
                    if cur > 0:
                        flg = False
            if flg: outs.append(str(i + 1))
        print(len(outs))
        print(' '.join(outs))