# Submission link: https://codeforces.com/problemset/submission/1277/316444183
def main():
    t = II()
    outs = []

    for _ in range(t):
        n = II()
        strs = [I() for _ in range(n)]

        vis = set(strs)

        w00 = []
        w01 = []
        w10 = []
        w11 = []

        for i in range(n):
            if strs[i][0] == '0':
                if strs[i][-1] == '0': w00.append(i)
                else: w01.append(i)
            else:
                if strs[i][-1] == '0': w10.append(i)
                else: w11.append(i)

        if w00 and w11 and len(w01) == 0 and len(w10) == 0:
            outs.append('-1')
        else:
            c = len(w01) - len(w10)
            ans = []

            while c > 1:
                idx = w01.pop()
                s = strs[idx]
                if s[::-1] not in vis:
                    ans.append(idx)
                    c -= 2

            while c < -1:
                idx = w10.pop()
                s = strs[idx]
                if s[::-1] not in vis:
                    ans.append(idx)
                    c += 2

            outs.append(str(len(ans)))
            outs.append(' '.join(str(i + 1) for i in ans))

    print('\n'.join(outs))