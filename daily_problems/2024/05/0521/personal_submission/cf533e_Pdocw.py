def main():
    n = II()
    s = I()
    t = I()
    l, r = -1, -1
    for i in range(n):
        if s[i] != t[i]:
            if l == -1:
                l = i
            r = i
    print((s[l:r] == t[l + 1 : r + 1]) + (s[l + 1 : r + 1] == t[l:r]))
    return


t = 1
for _ in range(t):
    main()
