n, q = MII()
one, two = 0, 1
for _ in range(q):
    tmp = LII()
    if tmp[0] == 1:
        mo = tmp[1]
        one = (one + mo) % n
        two = (two + mo) % n
    else:
        if one % 2 == 0:
            one += 1
            two -= 1
        else:
            one -= 1
            two += 1

ans = [0] * n
for i in range(n // 2):
    ans[one] = i * 2 + 1
    ans[two] = i * 2 + 2
    one = (one + 2) % n
    two = (two + 2) % n
print(*ans)
