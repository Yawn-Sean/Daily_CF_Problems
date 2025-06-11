def main():
    s, t = I(), I()
    n = len(s)
    ans = [''] * n
    extra = 1
    for i in range(n - 1, -1, -1):
        tmp = ord(s[i]) - ord('a') + extra
        if tmp >= 26:
            extra = 1
            tmp -= 26
        else:
            extra = 0
        ans[i] = ascii_lowercase[tmp]
    ret = ''.join(ans)
    if ret == t:
        return 'No such string'
    return ret


T = 1
for ii in range(T):
    print(main())
