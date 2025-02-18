def main():
    n = II()
    res = [0] + LII()
    two, one = deque(), deque()
    rest = 0
    for i in range(1, n + 1):
        if res[i] == 1:
            one.append(i)
        else:
            two.append(i)
            rest += res[i]
    rest -= 2 * (len(two) - 1)
    if rest < len(one):
        exit(print('NO'))
    print('YES', end=' ')
    print(len(two) + min(2, len(one)) - 1)
    print(n - 1)
    for a, b in pairwise(two):
        print(a, b)
        res[a] -= 1
        res[b] -= 1
    if two and one:
        print(two[-1], one[-1])
        res[two[-1]] -= 1
        one.pop()
    for o in one:
        while two and res[two[0]] == 0:
            two.popleft()
        tmp = two[0]
        res[two[0]] -= 1
        print(o, tmp)


T = 1
for ii in range(T):
    # print(main())
    main()
