def main():
    L = II()
    A = I()
    ln_a = len(A)

    if ln_a % L:
        cnt = (ln_a + L - 1) // L
        return ('1' + '0' * (L - 1)) * cnt

    seg = A[:L]
    cnt = ln_a // L
    if seg * cnt > A:
        return seg * cnt
    aa = '0' + seg
    lis = ['0'] * (L + 1)
    extra = 1
    for i in range(L, -1, -1):
        tmp = int(aa[i]) + extra
        lis[i] = str(tmp % 10)
        if tmp > 9:
            extra = 1
        else:
            extra = 0
    ne = ''
    if lis[0] == '0':
        ne = ''.join(lis[1:])
    else:
        ne = ''.join(lis)
    if len(ne) == L:
        return str(ne) * cnt
    per = '1' + '0' * (L - 1)
    return per * (cnt + 1)


tt = 1
for ii in range(tt):
    print(main())
