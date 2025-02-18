"""
大模拟：
# step 1: 反转分子分母
# step 2: 分母减去分子乘以右边的数。
# p / q = a1 + 1 / (a2 + 1 / x)

# q / (p - q * a1) = a2 + 1 / x

# (p - q * a1) / (q - a2 * (p - q * a1)) = x

"""
#python代码：
p, q = map(int, input().split())
n = int(input())
a = list(map(int, input().split()))

for i in range(n - 1):
    p, q = q, p - q * a[i]
if p == q * (a[-1]):
    print("YES")
else:
    print("NO")
