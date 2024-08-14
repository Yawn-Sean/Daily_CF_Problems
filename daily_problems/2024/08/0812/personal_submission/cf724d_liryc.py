'''
https://codeforces.com/contest/724/submission/275957689
724D
2024/8/12 Y2
1900
sliding window
'''

from collections import Counter

if __name__ == '__main__':
    m = int(input())
    s = input()
    cn = Counter(s)
    ans = [0] * 26
    for a in range(26):
        c = chr(a + 97)
        p, t, n = -1, -1, 0
        ok = True
        for i, x in enumerate(s):
            if x < c:
                p = i
            else:
                if x == c:
                    t = i
                if i - m >= p:
                    if t >= 0 and i - m < t:
                        p = t
                        t = -1
                        n += 1
                    else:
                        ok = False
                        ans[a] = cn[c]
                        break
        if ok:
            ans[a] = n
            break

    print(''.join(chr(a + 97) * ans[a] for a in range(26)))