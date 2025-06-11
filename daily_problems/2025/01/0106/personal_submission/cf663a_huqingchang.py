def main():
    s = I()
    lis = list(s.split(' '))
    ans = lis[::]
    n = int(lis[-1])
    tot = lis.count('?')
    b = lis.count('-')
    a = tot - b
    if a - n * b <= n <= n * a - b:
        print('Possible')
        pos, neg = [n] * a, [1] * b
        extra = n * a - b - n
        for i in range(a):
            if extra > 0:
                jian = min(n - 1, extra)
                extra -= jian
                pos[i] -= jian
        for i in range(b):
            if extra > 0:
                jia = min(n - 1, extra)
                extra -= jia
                neg[i] += jia
        for i in range(len(ans)):
            if lis[i] == '?':
                if i == 0 or lis[i - 1] == '+':
                    ans[i] = str(pos.pop())
                else:
                    ans[i] = str(neg.pop())
        exit(print(' '.join(ans)))
    else:
        exit(print('Impossible'))


T = 1
for ii in range(T):
    # print(main())
    main()
