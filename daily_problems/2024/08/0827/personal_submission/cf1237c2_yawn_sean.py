# Submission link: https://codeforces.com/contest/1237/submission/278322553
def main():
    n = II()
    xs = []
    ys = []
    zs = []

    for _ in range(n):
        x, y, z = MII()
        xs.append(x)
        ys.append(y)
        zs.append(z)

    outs = []

    def solve1(lst): 
        lst.sort(key=lambda x: zs[x])
        while len(lst) >= 2:
            x, y = lst.pop(), lst.pop()
            outs.append(f'{x + 1} {y + 1}')
        return lst
        
    def solve2(lst):
        lst.sort(key=lambda x: ys[x])
        resid = []
        tmp = []
        for i in lst:
            if len(tmp) == 0 or ys[i] == ys[tmp[0]]:
                tmp.append(i)
            else:
                resid.extend(solve1(tmp))
                tmp = [i]
        resid.extend(solve1(tmp))
        while len(resid) >= 2:
            x, y = resid.pop(), resid.pop()
            outs.append(f'{x + 1} {y + 1}')
        return resid

    def solve3(lst):
        lst.sort(key=lambda x: xs[x])
        resid = []
        tmp = []
        for i in lst:
            if len(tmp) == 0 or xs[i] == xs[tmp[0]]:
                tmp.append(i)
            else:
                resid.extend(solve2(tmp))
                tmp = [i]
        resid.extend(solve2(tmp))
        while len(resid) >= 2:
            x, y = resid.pop(), resid.pop()
            outs.append(f'{x + 1} {y + 1}')

    solve3(list(range(n)))
    print('\n'.join(outs))