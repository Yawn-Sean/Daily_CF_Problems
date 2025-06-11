'''
https://codeforces.com/contest/886/submission/272574442
CF886D
2024/7/25 Y2
2000
constructive, string
'''
from itertools import pairwise

if __name__ == '__main__':
    n = int(input())
    nt, pd = {}, {}
    singlechar = set() # WA: forgot the case of single character
    ok = True
    for _ in range(n):
        if not ok:
            break
        s = input()
        if len(s) == 1:
            singlechar.add(s)
            continue
        for a, b in pairwise(s):
            if a == b:
                ok = False
                break
            if a in nt:
                if nt[a] != b:
                    ok = False
                    break
            elif b in pd: # WA: forgot case: ac bc -> acbc is wrong
                ok = False
                break
            else:
                nt[a] = b
                pd[b] = a
                c = b
                while c != a and c in nt:
                    c = nt[c]
                if c == a:
                    ok = False
                    break
    if ok:
        ans = ""
        for x in "abcdefghijklmnopqrstuvwxyz":
            if x in nt or x in pd:
                if x in nt and not x in pd:
                    y = x
                    ans += y
                    while y in nt:
                        y = nt[y]
                        ans += y
            elif x in singlechar:
                ans += x
        print(ans)
    else:
        print("NO")


