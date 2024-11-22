# Submission link: https://codeforces.com/contest/1280/submission/284981743
def main():
    t = II()
    outs = []
    mod = 10 ** 9 + 7

    for _ in range(t):
        x = II()
        s = I()
        
        k = len(s)
        npt = min(k, x)
        
        tmp = [0] * x
        for i in range(npt):
            tmp[i] = int(s[i])
        
        cur_len = k
        
        for pt in range(x):
            if tmp[pt] == 0: break
            
            cur_len += (cur_len - pt - 1) * (tmp[pt] - 1) % mod
            cur_len %= mod
            
            p = pt + 1
            e = npt
            c = 1
            while c < tmp[pt] and npt < x:
                tmp[npt] = tmp[p]
                p += 1
                npt += 1
                if p == e:
                    p = pt + 1
                    c += 1
        
        outs.append(cur_len)

    print('\n'.join(map(str, outs)))