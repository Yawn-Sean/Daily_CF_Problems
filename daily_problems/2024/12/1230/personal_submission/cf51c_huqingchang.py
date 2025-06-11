def main():
    n = II()
    res = LII()

    pos = sorted(set(res))
    ori = pos[::]
    pos = [2 * x for x in pos]  # 全体坐标*2
    mi, mx = 0, (pos[-1] - pos[0] + 5) // 6
    ans = mx

    def check(d):
        if d << 2 >= pos[-1] - pos[0]:
            return True
        l_idx = bisect.bisect_right(pos, pos[0] + 2 * d)
        r_idx = bisect.bisect_left(pos, pos[-1] - 2 * d) - 1
        if pos[r_idx] - pos[l_idx] <= 2 * d:
            return True
        return False

    while mi <= mx:
        mid = (mi + mx) >> 1
        if check(mid):
            ans = mid
            mx = mid - 1
        else:
            mi = mid + 1

    ans /= 2
    print("{:.6f}".format(ans))
    # print(ans)
    loc = [ori[0] + ans, ori[-1] - ans]
    lIDx = bisect.bisect_right(ori, ori[0] + 2 * ans)
    if lIDx >= len(pos):
        loc.append(ori[lIDx - 1] + ans)
    else:
        loc.append(ori[lIDx] + ans)
    loc.sort()
    for lo in loc:
        print("{:.6f}".format(lo), end=' ')


T = 1
for ii in range(T):
    # print(main())
    main()
