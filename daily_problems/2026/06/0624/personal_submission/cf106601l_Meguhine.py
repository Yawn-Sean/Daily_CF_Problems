X = int(input())

if X <= 3:
    exit(print(0 if X <= 2 else 1))

ans, B = 1, 2
while True:
    if X % B == 0:
        ans += 1
    s, x = 0, X
    while x:
        s ^= (x % B)
        x //= B
    if s == 0:
        ans += 1
    B += 1
    if B * B >= X:
        break

print(ans)


"""
显然根号分治
当 B < sqrt(X) 时, 暴力枚举即可
当 B >= sqrt(X) 时, 只剩下两位
- 判断形如 YY 的数是否存在 B 使得其值 == X
- Y*(B+1) == X, 所以寻找 X 的因子即可

为什么到 B*B == X 就要停呢?
因为此时, 真正的 base 是 B-1, B > B-1, 矛盾, 所以需要停止
"""
