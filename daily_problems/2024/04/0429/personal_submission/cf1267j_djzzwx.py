
def solve() -> None:
    int(input())
    cnt = collections.Counter(ints())
    up = math.inf
    for c in cnt.values():
        up = min(up, c)
    ans = 0
    # print(cnt, up)
    for i in range(up+1, 0, -1):
        m = 0
        for c in cnt.values():
            cur = (c - 1) // i + 1
            m += cur
            if (i - 1) * cur > c:
                m = math.inf
                break
        else:
            ans = m
            break
    print(ans)


for _ in range(int(input())):
    solve()
