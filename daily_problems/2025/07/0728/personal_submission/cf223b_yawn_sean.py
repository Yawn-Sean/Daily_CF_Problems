# Submission link: https://codeforces.com/contest/223/submission/331305123
def main():
    s1 = [ord(c) - ord('a') for c in I()]
    n1 = len(s1)

    s2 = [ord(c) - ord('a') for c in I()]
    n2 = len(s2)

    suff = [n2] * (n1 + 1)

    for i in range(n1 - 1, -1, -1):
        suff[i] = suff[i + 1]
        if suff[i] > 0 and s1[i] == s2[suff[i] - 1]:
            suff[i] -= 1

    pt = 0
    last_c = [-2] * 26

    for i in range(n1):
        if pt < n2 and s1[i] == s2[pt]:
            last_c[s1[i]] = pt
            pt += 1
        
        if suff[i + 1] > last_c[s1[i]] + 1:
            exit(print('No'))

    print('Yes')