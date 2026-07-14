'''
https://codeforces.com/gym/106619/submission/382498227
primes, factors
'''

MAXN = 2 * 10 ** 6 + 4
mpf = list(range(MAXN + 1))
limit = int((MAXN) ** 0.5) + 1
for i in range(2, limit):
    if mpf[i] == i:
        for j in range(i * i, MAXN + 1, i):
            if mpf[j] == j:
                mpf[j] = i

mfc = [1] * MAXN 
sc = [0] * MAXN 
ps = [0] * MAXN 
for n in range(2, MAXN):
    f = mpf[n]
    if f == n:
        sc[n] = 3
    else:
        r = n // f
        if mpf[r] == f:
            mfc[n] = mfc[r] + 1
            sc[n] = sc[r] // (mfc[r] * 2 + 1) * (mfc[n] * 2 + 1)
        else:
            sc[n] = sc[r] * 3
    ps[n] = sc[n] - 1 >> 1
    ps[n] += ps[n - 1]

if __name__ == '__main__':
    for _ in range(int(input())):
        n = int(input())
        print(ps[n])
