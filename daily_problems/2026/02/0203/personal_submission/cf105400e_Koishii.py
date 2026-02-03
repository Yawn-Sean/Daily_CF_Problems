def soviet():
    n = int(input())
    a = list(map(int, input().split()))
    cnt = [0] * 11
    mx = max(a)
    mn = min(a)

    for x in a: cnt[x] += 1

    if mx == mn: print(10 ** n)
    else: print((11 - mx) ** cnt[mx] * mn ** cnt[mn])


for _ in range(int(input())): soviet()
