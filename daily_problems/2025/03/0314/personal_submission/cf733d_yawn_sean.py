# Submission link: https://codeforces.com/contest/733/submission/310496719
def main():
    n = II()

    d = {}

    ans = 0
    chosen = [-1]

    for i in range(1, n + 1):
        a, b, c = sorted(MII())
        
        if a >= ans:
            ans = a
            chosen = [i]
        
        if (a, b) in d:
            nc, ni = d[(a, b)]
            res = min(a, b, nc + c)
            if res > ans:
                ans = res
                chosen = [ni, i]
        
        if (a, c) in d:
            nb, ni = d[(a, c)]
            res = min(a, b + nb, c)
            if res > ans:
                ans = res
                chosen = [ni, i]
        
        if (b, c) in d:
            na, ni = d[(b, c)]
            res = min(na + a, b, c)
            if res > ans:
                ans = res
                chosen = [ni, i]
        
        if (a, b) not in d or d[(a, b)] < (c, i):
            d[(a, b)] = (c, i)
        
        if (a, c) not in d or d[(a, c)] < (b, i):
            d[(a, c)] = (b, i)
        
        if (b, c) not in d or d[(b, c)] < (a, i):
            d[(b, c)] = (a, i)

    print(len(chosen))
    print(*chosen)