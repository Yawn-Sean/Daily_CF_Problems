'''
https://codeforces.com/gym/106601/submission/379990970
Math, factors
'''
def solve(n: int, q: int, a: list[int], qa: list[list[int]]):
    initPrimes()
    cnt = [0] * (10 ** 6 + 1)
    cf = [0] * (10 ** 6 + 1)
    for x in a:
        cnt[x] += 1
    for m in cnt:
        if m:
            for f in all_factors(m):
                cf[f] += 1
    for qr in qa:
        if qr[0] == 1:
            _, i, y = qr
            x = a[i - 1]
            for f in all_factors(cnt[x]):
                cf[f] -= 1
            cnt[x] -= 1
            if cnt[x]:
                for f in all_factors(cnt[x]):
                    cf[f] += 1
            a[i - 1] = y
            if cnt[y]:
                for f in all_factors(cnt[y]):
                    cf[f] -= 1
            cnt[y] += 1
            for f in all_factors(cnt[y]):
                cf[f] += 1
        else:
            _, x = qr
            yield cf[x]
