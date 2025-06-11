n, a = MII()
nums = LII()

cnta = 0
pre = defaultdict(int)

for x in nums:
    if x == a:
        cnta += 1
        for k in list(pre.keys()):
            if pre[k] < cnta:
                del pre[k]
    elif pre[x] >= cnta:
        pre[x] += 1

    if not pre:
        print(-1)
        exit()
else:
    print(next(iter(pre.keys())))
