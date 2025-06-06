# Submission link: https://codeforces.com/problemset/submission/631/318051835
def main():
    n, m = MII()

    s1 = LI()
    s2 = LI()

    c1 = []
    v1 = []

    for x in s1:
        v, c = x.split('-')
        v = int(v)
        c = ord(c)
        
        if c1 and c1[-1] == c:
            v1[-1] += v
        else:
            c1.append(c)
            v1.append(v)

    c2 = []
    v2 = []

    for x in s2:
        v, c = x.split('-')
        v = int(v)
        c = ord(c)
        
        if c2 and c2[-1] == c:
            v2[-1] += v
        else:
            c2.append(c)
            v2.append(v)

    ans = 0
    if len(c2) == 1:
        for i in range(len(c1)):
            if c1[i] == c2[0]:
                ans += fmax(0, v1[i] - v2[0] + 1)

    elif len(c2) == 2:
        for i in range(len(c1) - 1):
            if c1[i] == c2[0] and c1[i + 1] == c2[1] and v1[i] >= v2[0] and v1[i + 1] >= v2[1]:
                ans += 1

    else:
        tmp = []
        
        for i in range(1, len(c2) - 1):
            tmp.append(v2[i] * 26 + c2[i] % 26)
        tmp.append(-1)
        for i in range(len(c1)):
            tmp.append(v1[i] * 26 + c1[i] % 26)
        
        kmp = prep(tmp)
        
        for i in range(len(c1)):
            if kmp[i + len(c2) - 1] == len(c2) - 2:
                i1 = i - len(c2) + 2
                i2 = i + 1
                if i1 >= 0 and c1[i1] == c2[0] and v1[i1] >= v2[0] and i2 < len(c1) and c1[i2] == c2[-1] and v1[i2] >= v2[-1]:
                    ans += 1
        
    print(ans)