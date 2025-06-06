down, up = [0] * 7, [0] * 7
for i in range(1, 7):
    down[i] = 10 ** (i - 1)
    up[i] = 10 ** i - 1

def main():
    a, b, c, k = MII()
    tot = 0
    for i in range(fmax(down[c] - up[b], down[a]), up[a] + 1):
        if i + down[b] > up[c]:
            break
        l, r = fmax(down[b], down[c] - i), fmin(up[c] - i, up[b])
        cnt = r - l + 1
        if tot + cnt < k:
            tot += cnt
            continue
        j = l + k - tot - 1
        print(f'{i} + {j} = {i + j}')
        return
    print(-1)


T = II()
for ii in range(T):
    # print(ii)
    # print(main())
    main()
