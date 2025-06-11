"""
思路：先统计一下质数。 再创建一个字典存储下标和值的映射。

遍历数组， 如果当前下标和值不相等， 就找质数距离的在其前边的数组值交换。



"""
#python代码：
n = int(input())
a = list(map(int, input().split()))
prime = [True] * (n + 1)

prime[1] = False
for i in range(2, isqrt(n) + 1):
    if prime[i]:
        for j in range(i * i, n + 1, i):
            prime[j] = False

swap = []
pos = {a[i]: i + 1 for i in range(n)}

for i in range(1, n + 1):
    now = pos[i]
    while now > i:
        tmp = i
        while not prime[now - tmp + 1]:
            tmp += 1  # 找到与其排序位最接近的奇数长度的点
        swap.append((tmp, now))
        pos[a[tmp - 1]] = now  # 更换被交换数的pos
        a[tmp - 1], a[now - 1] = a[now - 1], a[tmp - 1]  # 交换两个数
        now = tmp  # 当前数字继续向前交换
print(len(swap))
for x, y in swap:
    print(x, y)


