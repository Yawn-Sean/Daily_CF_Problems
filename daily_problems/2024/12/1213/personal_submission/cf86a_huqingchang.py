def main():
    l, r = MII()
    ln = len(str(r))
    mx = int('9' * ln)
    ln_l = len(str(l))
    if r * 2 <= mx + 1:
        return r * (mx - r)
    if l <= mx // 2 + 1:
        half = mx // 2
        return half * (mx - half)
    return l * (mx - l)


tt = 1
for ii in range(tt):
    print(main())
