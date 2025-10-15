# Submission link: https://codeforces.com/contest/662/submission/318783555
def main():
    t = II()
    outs = []

    for _ in range(t):
        s = I()[4:]
        
        cur = 1988

        v10 = 1
        to_add = 1
        resid = 0

        for i in range(len(s) - 1, -1, -1):
            resid = resid + v10 * int(s[i])
            v10 *= 10
            
            cur += to_add
            while cur % v10 != resid:
                cur += to_add
            
            to_add *= 10
        
        outs.append(cur)

    print('\n'.join(map(str, outs)))