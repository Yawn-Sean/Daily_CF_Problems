"""
123 456
112233 + 142536 + 415263 + 445566
12 3 45
1122 + 123 + 1425 + 132 + 33 + 435 + 4152 + 453 + 4455
按十进制位考虑，每个数的每个十进制位，在每个 base 下贡献了多少次
需要统计位数为 cnt 的数有多少个
假如有两个数 val1 val2，长度分别为 cnt1 和 cnt2，对于所有的 f(val1, val2)： 
- cnt1 <= cnt2，则 val1 贡献 10 的奇数次方
- cnt1 > cnt2，则 val1 的低 cnt2 位贡献 10 的奇数次方，高 cnt1 - cnt2 位
  从 10^(2 * cnt2) 开始贡献
如果是求 f(val2, val1):
- cnt1 <= cnt2，则 val1 贡献 10 的偶数次方
- cnt1 > cnt2，则 val1 的低 cnt2 位贡献 10 的偶数次方，高 cnt1 - cnt2 位
  从 10 ^(2 * cnt2) 开始贡献
需要枚举看 < cnt1 位的数，看各有多少，然后贡献
"""

n = int(input())
a = list(map(int, input().split()))
cnt = [0 for i in range(22)]
for i in range(n):
    val = a[i]
    digit_cnt = 0
    while val > 0:
        val //= 10
        digit_cnt += 1
    cnt[digit_cnt] += 1
res = 0
mod = 998244353
for i in range(n):
    c = 0
    low_val = 0
    high_val = a[i]
    base = 10
    for j in range(1, 11):
        c += cnt[j] * (low_val + high_val * pow(10, 2 * j - 1))
        c %= mod
        low_val += (high_val % 10) * base
        high_val //= 10
        base *= 100
        base %= mod
        low_val %= mod
    res += c
    res %= mod
    c = 0
    low_val, high_val = a[i] % 10, a[i] // 10
    base = 100
    for j in range(1, 11):
        c += cnt[j] * (low_val + high_val * pow(10, 2 * j))
        c %= mod
        low_val += (high_val % 10) * base
        high_val //= 10
        base *= 100
        base %= mod
        low_val %= mod
    res += c
    res %= mod
print(res)