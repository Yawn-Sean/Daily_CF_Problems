# Submission link: https://codeforces.com/contest/1615/submission/265697651
def main():
    t = II()
    outs = []

    for _ in range(t):
        n = II()
        s1 = I()
        s2 = I()

        ans = n + 5
        c1 = s1.count('1')
        c2 = s2.count('1')
        if c1 == c2:
            cnt = 0
            for i in range(n):
                if s1[i] != s2[i]:
                    cnt += 1
            ans = cnt
        if n - c1 + 1 == c2:
            cnt = 0
            f = False
            for i in range(n):
                if s1[i] == s2[i]:
                    cnt += 1
                    if s2[i] == '1':
                        f = True
            ans = min(ans, cnt + 2 - f * 2)
                        
        outs.append(ans if ans < n + 5 else -1)

    print('\n'.join(map(str, outs)))