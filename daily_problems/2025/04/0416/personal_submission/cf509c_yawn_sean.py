# Submission link: https://codeforces.com/contest/509/submission/315775707
def main():
    cur = [0] * 400

    t = II()
    outs = []

    for _ in range(t):
        n = II()
        ncur = [0] * 400
        
        flg = False
        for i in range(400):
            if n >= cur[i]:
                n -= cur[i]
                ncur[i] = cur[i]
            else:
                flg = True
                for j in range(i - 1, -1, -1):
                    if n and ncur[j] != 9:
                        ncur[j] += 1
                        n -= 1
                        break
                    else:
                        n += ncur[j]
                        ncur[j] = 0
                break
        
        if not flg:
            if n:
                ncur[399] += 1
                n -= 1
            else:
                for j in range(399, -1, -1):
                    if n and ncur[j] != 9:
                        ncur[j] += 1
                        n -= 1
                        break
                    else:
                        n += ncur[j]
                        ncur[j] = 0

        for j in range(399, -1, -1):
            v = fmin(n, 9 - ncur[j])
            ncur[j] += v
            n -= v
        
        cur = ncur
        for i in range(400):
            if ncur[i]:
                outs.append(''.join(map(str, (cur[j] for j in range(i, 400)))))
                break

    print('\n'.join(outs))