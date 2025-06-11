'''
https://codeforces.com/contest/432/submission/278279331
432C
2024/8/26 Y1
1800
primes, 分类讨论（第一次见到哥德巴赫猜想得到实际应用）
'''

import sys
input = lambda: sys.stdin.readline().strip()

pa = []
ft = list(range(100002))
gb = [0] * 100002

def initPrimes():
    global pa, ft, gb
    for p in range(2, 100002):
        if ft[p] == p:
            for x in range(p * p, 100002, p):
                ft[x] = p
            pa.append(p)
        if p < 4:
            gb[p] = p
        elif p & 1:
            r = p - 2
            if ft[r] == r:
                gb[p] = 2
            else:
                gb[p] = 3
        else:
            for t in pa:
                r = p - t
                if ft[r] == r:
                    gb[p] = t
                    break

def init():
    initPrimes()
    n = int(input())
    a = list(map(int, input().split()))
    return n, a

def solve(n: int, a: list[int]):
    global ft, gb
    ia = [0] * (n + 1)
    for i, x in enumerate(a):
        ia[x] = i
    ans = []
    for i in range(n):
        t = i + 1
        while a[i] != t:
            j = ia[t]
            d = j - i + 1
            if ft[d] == d: # d is prime, just swap
                ans.append(f"{i + 1} {j + 1}")
                ia[a[i]], ia[t] = j, i
                a[i], a[j] = a[j], a[i]
            else: # swap t to position k first
                k = j - gb[d + 1] + 1
                ans.append(f"{k + 1} {j + 1}")
                ia[a[k]], ia[t] = j, k
                a[k], a[j] = a[j], a[k]
    return ans

if __name__ == '__main__':
    args = init()
    # args = (100000, list(range(100000, -1, -1))) # test case #9
    ans = solve(*args)
    print(len(ans))
    print('\n'.join(ans))
