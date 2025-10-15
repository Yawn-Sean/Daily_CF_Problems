def main():
    n = II()
    d = dict(zip('RGBYW', list(range(5))))
    cards = set(LI())
    ncards = []
    for card in cards:
        ncards.append([d[card[0]], int(card[1]) - 1])
    if len(cards) == 1:
        return 0
    chs, nums = set(), set()
    for ch, num in ncards:
        chs.add(ch)
        nums.add(num)
    chs = sorted(chs)
    nums = sorted(nums)
    lns, lnn = len(chs), len(nums)
    cards = [[chs.index(card[0]), nums.index(card[1])] for card in ncards]
    ans = 10

    def check(bit_i, bit_j):
        tmp = (bit_i << lnn) + bit_j
        cnt = Counter()
        for a, b in cards:
            cnt[tmp & (((1 << a) << lnn) + (1 << b))] += 1
            if cnt[tmp & (((1 << a) << lnn) + (1 << b))] > 1:
                return False
        return True

    # print(check(21, 6))


    for i in range(1 << lns):
        if i.bit_count() == lns:
            continue
        for j in range(1 << lnn):
            if j.bit_count() == lnn:
                continue
            if check(i, j):
                ans = fmin(ans, i.bit_count() + j.bit_count())
                # if i.bit_count() + j.bit_count() == 5:
                #     print(bin(i), bin(j))
    return ans


T = 1
for ii in range(T):
    print(main())
