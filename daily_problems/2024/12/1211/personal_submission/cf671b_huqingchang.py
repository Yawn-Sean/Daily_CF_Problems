def main():
    n, k = MII()
    res = LII()

    s = sum(res)
    a, b = 0, 0
    if s % n:
        a, b = s // n, s // n + 1
    else:
        a, b = s // n, s // n
    mi, mx = min(res), max(res)

    less, more = [], []
    for x in res:
        if x < a:
            less.append(x)
        elif x > b:
            more.append(x)

    down = mi
    low, high = mi, a

    def check(y):
        ret = 0
        for x in less:
            if x < y:
                ret += y - x
        return ret <= k

    while low <= high:
        mid = (low + high) >> 1
        if check(mid):
            down = mid
            low = mid + 1
        else:
            high = mid - 1

    up = mx
    low, high = b, mx

    def check1(y):
        ret = 0
        for x in more:
            if x > y:
                ret += x - y
        return ret <= k

    while low <= high:
        mid = (low + high) >> 1
        if check1(mid):
            up = mid
            high = mid - 1
        else:
            low = mid + 1

    return up - down


tt = 1
for ii in range(tt):
    print(main())
