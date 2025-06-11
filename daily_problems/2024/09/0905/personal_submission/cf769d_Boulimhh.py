"""
学习的一题。

下意识地认为 2 的 14 次方很大，仔细算算发现是 16384，还挺小的。

对正好有 k 位不同， 异或就可以了。 所以要先统计二进制正好是 k 的数字。

再遍历两个数组， 求和即可。

"""
#python代码：
n, k = map(int, input().split())
a = list(map(int, input().split()))
cnt = [0] * (1 << 14)
for x in a:
    cnt[x] += 1

if k == 0:
    print(sum(x * (x - 1) // 2 for x in cnt))
else:
    b = [i for i in range(1 << 14) if i.bit_count() == k]
    res = 0
    for i in range(1 << 14):
        for y in b:
            res += cnt[i] * cnt[i ^ y]
    print(res // 2)
