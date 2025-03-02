def main():
    h, n = MII()
    res = LII()
    move_out = set(res)
    ans = 0
    dq = deque(res)
    while len(dq) > 1:
        a = dq.popleft()
        b = dq.popleft()
        if b - 1 == 0:
            break
        if b - 1 in move_out:
            continue
        ans += 1
        dq.appendleft(b - 1)
    return ans


T = II()
for ii in range(T):
    print(main())
