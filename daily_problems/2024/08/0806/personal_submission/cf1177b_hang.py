def main():
    k = int(input()) -  1
    p = 10
    t = 0
    d = 1
    while True:
        z = p - 1 - t
        z *= d
        if k > z:
            t = p - 1
            k -= z
            p *= 10
            d += 1
        else:
            a,b = divmod(k, d)
            print(str(p // 10 + a)[b])
            return


main()