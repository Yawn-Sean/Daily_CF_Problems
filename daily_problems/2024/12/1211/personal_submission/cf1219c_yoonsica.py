# https://codeforces.com/contest/1219/submission/295961723
'''
求大于等于A的最小L周期整数
首先判断A的长度能否被L整除，如果不能，直接凑成能被L整除的100...100..
如果能被L整除，那么相当与求比A[:L]大的下一个数,注意999这种情况，+1长度变了
776554554
还要看后面的是不是比前面的小，如果小，可以直接用第一段
'''
L = RI()
a = RS()
n = len(a)


def add(t):
    ans = []
    adv = 1
    for x in t[::-1]:
        x = int(x) + adv
        ans.append(x % 10)
        adv = x // 10
    if adv:
        ans.append(1)
    return ''.join(map(str, ans[::-1]))


if n % L:
    cnt = n // L + 1
    s = '1' + (L - 1) * '0'
    print(s * cnt)
else:
    t = a[:L]
    cnt = n // L
    for i in range(L, n, L):
        if a[i:i + L] < t:
            print(t * cnt)
            break
    else:
        if t == '9' * L:
            cnt += 1
            s = '1' + (L - 1) * '0'
            print(s * cnt)
        else:
            cnt = n // L
            s = add(t)
            print(cnt * s)

