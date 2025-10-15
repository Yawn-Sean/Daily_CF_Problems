def main():
    s, c = LI()
    sorted_s = ''.join(sorted(s))
    n = len(s)
    ans = list(s)
    flag = False
    for i in range(n):
        if s[i] == sorted_s[i]:
            continue
        else:
            for j in range(n - 1, -1, -1):
                if ans[j] == sorted_s[i]:
                    ans[i], ans[j] = ans[j], ans[i]
                    flag = True
                    break
        if flag:
            break
    ret = ''.join(ans)
    if ret < c:
        return ret
    return '---'


T = II()
for ii in range(T):
    print(main())
