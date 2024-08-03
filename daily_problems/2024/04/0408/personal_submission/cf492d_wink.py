n, x, y = map(int, input().split())

outs = []
for i in range(n):
    v = int(input())


    def check(s):
        return s // x + s // y >= v


    l = 1
    r = 10 ** 18
    while l < r:
        mid = l + r >> 1
        if check(mid):
            r = mid
        else:
            l = mid + 1

    if r % x == 0 and r % y == 0:
        outs.append("Both")
    elif r % x == 0:
        outs.append("Vova")
    else:
        outs.append("Vanya")

print('\n'.join(outs))
