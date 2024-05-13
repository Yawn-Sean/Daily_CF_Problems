# -*- coding: utf-8 -*-
# https://codeforces.com/contest/799/submission/260727839

tcn = 1
for _tcn_ in range(tcn):
    n, c, d = MI()
    fountains = []
    for i in range(n):
        beauty, cost, typ = input().split()
        beauty, cost = int(beauty), int(cost)
        fountains.append((beauty, cost, typ))
    coins = []
    diamonds = []

    for i in range(n):
        beauty, cost, typ = fountains[i]
        if typ == 'C':
            coins.append((beauty, cost, i))
        elif typ == 'D':
            diamonds.append((beauty, cost, i))

    coins.sort(key=lambda x: x[1])
    diamonds.sort(key=lambda x: x[1])
    n1, n2 = len(coins), len(diamonds)
    Lstc = LazySegmentTree(n1, max, 0, max, max, 0)
    Lstd = LazySegmentTree(n2, max, 0, max, max, 0)
    hst = dict()
    for i in range(n1):
        Lstc.set(i, coins[i][0])
        hst[coins[i][2]] = i
    for i in range(n2):
        Lstd.set(i, diamonds[i][0])
        hst[diamonds[i][2]] = i

    def get_max_beauty(nums, money, typ):
        L, R = 0, len(nums) - 1
        ret = -1
        while L <= R:
            mid = (L + R) // 2
            if nums[mid][1] <= money:
                ret = mid
                L = mid + 1
            else:
                R = mid - 1
        if ret >= 0:
            if typ == 'C':
                ret = Lstc.prod(0, ret + 1)
            elif typ == 'D':
                ret = Lstd.prod(0, ret + 1)
            return ret
        else:
            return 0


    ans = 0
    for i in range(n):
        c1, d1 = c, d
        beauty, cost, typ = fountains[i]
        tmp = 0
        if typ == 'C':
            if c1 >= cost:
                c1 = c - cost
                tmp = beauty
                Lstc.set(hst[i], 0)
        elif typ == 'D':
            if d1 >= cost:
                d1 = d - cost
                tmp = beauty
                Lstd.set(hst[i], 0)
        mx1 = get_max_beauty(coins, c1, 'C')
        mx2 = get_max_beauty(diamonds, d1, 'D')
        if typ == 'C':
            if c >= cost:
                Lstc.set(hst[i], beauty)
        elif typ == 'D':
            if d >= cost:
                Lstd.set(hst[i], beauty)

        if tmp == 0 or max(mx1, mx2) == 0:
            continue
        ans = max(ans, tmp + max(mx1, mx2))
    print(ans)