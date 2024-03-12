def main():
    n = int(input())
    pos = list(map(int, input().split()))
    speed = list(map(int, input().split()))

    l, r = 1e-9, 1e9
    for _ in range(100):
        mid = (l * r) ** 0.5
        lp, rp = 1, 1e9
        for p, v in zip(pos, speed):
            lp = max(lp, p - v * mid)
            rp = min(rp, p + v * mid)

        if lp <= rp:
            r = mid
        else:
            l = mid
    return (l * r) ** 0.5


print(main())

