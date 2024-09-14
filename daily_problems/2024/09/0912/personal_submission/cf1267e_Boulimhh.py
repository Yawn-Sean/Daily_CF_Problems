"""
思路：依次枚举每一轮， 最后一个人和其中某个人的票数差， 将差值排序。 

对票数差求和， 当票数差仍然是最后一个人领先时， 去掉差值的最大值， 并将差值最大值出现的轮次记录下来。

找到去掉轮次出现的最小值即可。

"""
#python代码：
n, m = map(int, input().split())
g = [list(map(int, input().split())) for _ in range(m)]
res = [i + 1 for i in range(m)]
# 枚举第i个人和最后一个人的票数和之差
for i in range(n - 1):
    # 对差值进行排序，依次去掉大的差值。
    diff = sorted([(x[-1] - x[i], j) for j, x in enumerate(g)])
    s = sum([x[0] for x in diff])
    ans = []
    while s > 0:
        s -= diff[-1][0]
        ans.append(diff[-1][1]+1)
        diff.pop()
    if len(ans) < len(res):
        res = ans
print(len(res))
print(*res)
