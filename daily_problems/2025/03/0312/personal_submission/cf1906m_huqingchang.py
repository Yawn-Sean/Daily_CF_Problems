def main():
    n = II()
    res = LII()
    mx = max(res)
    s = sum(res)
    if mx > (s - mx) * 2:
        return s - mx
    return s // 3


T = 1
for ii in range(T):
    print(main())
