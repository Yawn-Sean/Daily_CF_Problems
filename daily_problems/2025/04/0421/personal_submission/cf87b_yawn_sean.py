# Submission link: https://codeforces.com/contest/87/submission/316443704
def main():
    n = II()
    cnt = Counter()

    cnt['void'] = 0
    cnt['errtype'] = -100000
    outs = []

    for _ in range(n):
        op = LI()
        if op[0] == 'typedef':
            v1 = op[1]
            v2 = op[2]
            
            l = 0
            r = len(v1) - 1
            cur = 0
            
            while v1[l] == '&':
                l += 1
                cur -= 1
            
            while v1[r] == '*':
                r -= 1
                cur += 1
            
            orig = v1[l:r + 1]
            
            if orig not in cnt:
                cnt[orig] = -100000
            
            nval = cnt[orig] + cur
            cnt[v2] = nval if nval >= 0 else -100000
        else:
            v = op[1]
            
            l = 0
            r = len(v) - 1
            cur = 0
            
            while v[l] == '&':
                l += 1
                cur -= 1
            
            while v[r] == '*':
                r -= 1
                cur += 1
            
            orig = v[l:r + 1]
            
            outs.append('errtype' if orig not in cnt or cnt[orig] + cur < 0 else "void" + '*' * (cnt[orig] + cur))

    print('\n'.join(outs))