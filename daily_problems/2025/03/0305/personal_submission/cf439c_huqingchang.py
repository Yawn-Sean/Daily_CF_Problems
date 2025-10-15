def main():
    n, k, p = MII()
    res = LII()
    even, odd = [], []
    for x in res:
        if x & 1:
            odd.append(x)
        else:
            even.append(x)
    if len(odd) < k - p or len(even) + (len(odd) - (k - p)) // 2 < p or (len(odd) - (k - p)) & 1:
        exit(print('NO'))
    print('YES')
    ans = []
    for _ in range(k - p):
        ans.append([odd.pop()])
    for _ in range(p):
        if even:
            ans.append([even.pop()])
        else:
            ans.append([odd.pop(), odd.pop()])
    ans[-1].extend(odd + even)
    for r in ans:
        print(len(r), *r)


T = 1
for ii in range(T):
    # print(main())
    # print(ii)
    main()
