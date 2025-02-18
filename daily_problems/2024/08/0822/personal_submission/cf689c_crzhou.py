m = II()
def count(x: int) -> int:
    cur = 2
    res = 0
    while cur ** 3 <= x:
        res += x // cur ** 3
        cur += 1
    return res

tmp = bisect_left(range(2 ** 3, 10 ** 16), m, key=count)
if count(tmp + 8) == m:
    print(tmp + 8)
else:
    print(-1)
