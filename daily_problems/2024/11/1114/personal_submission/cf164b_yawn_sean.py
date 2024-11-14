# Submission link: https://codeforces.com/contest/164/submission/291379162
def main():
    la, lb = MII()
    numsa = LII()
    numsb = LII()

    pos = [-1] * (10 ** 6 + 1)
    for i in range(lb):
        pos[numsb[i]] = i

    ans = 0

    cur = 0
    r = 0
    for i in range(la):
        if r < i:
            r = i
            cur = 0
        elif i > 0:
            ncur = pos[numsa[i]] - pos[numsa[i - 1]]
            if ncur < 0:
                ncur += lb
            cur -= ncur
        
        if pos[numsa[i]] == -1:
            continue
        
        while r < i + la - 1:
            if pos[numsa[(r + 1) % la]] == -1: break
            ncur = pos[numsa[(r + 1) % la]] - pos[numsa[r % la]]
            if ncur < 0: ncur += lb
            if cur + ncur >= lb: break
            r += 1
            cur += ncur
        
        ans = fmax(r - i + 1, ans)

    print(ans)