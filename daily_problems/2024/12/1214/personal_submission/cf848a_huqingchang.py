def main():
    n = II()
    if n == 0:
        return 'a'

    f = [0]
    for i in count(1):
        tmp = math.comb(i, 2)
        if tmp > n:
            break
        f.append(tmp)

    ans = []
    i = len(f) - 1
    while n:
        if n >= f[-1]:
            ans.append(i)
            n -= f[-1]
        else:
            f.pop()
            i -= 1
    j = 0

    ret = ''
    for x in ans:
        ret += ascii_lowercase[j] * x
        j += 1
    return ret


tt = 1
for ii in range(tt):
    print(main())
