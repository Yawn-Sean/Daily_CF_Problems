_ = II()
a = LII()
print('YES')
if math.gcd(*a) > 1:
    print(0)
else:
    ans = 0
    cnt = 0  # 连续奇数个数
    for x in a:
        if x % 2:
            cnt += 1
        else:
            ans += cnt // 2 + cnt % 2 * 2
            cnt = 0
    ans += cnt // 2 + cnt % 2 * 2  # 最后一段奇数（如果有的话）
    print(ans)
