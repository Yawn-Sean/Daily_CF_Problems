"""
思路： 看到题里的一句话： 如果一组学生中没有人认为自己比组里的其他人强，那么这组学生就可以心平气和地合作。

仔细解读一下，这就是解题方法。 知道算法最多的人， 不少于两个。 其他人的算法水平要比前者的少。 这样可以在心平气和的合作情况下， 技能水平总和尽可能的大。

将每个人的算法水平计数， 得到一个算法水平表， 每个算法水平位置对应人数， 那么这个表最多有 60 项。

遍历这个表， 如果相同算法能力的人数大于 1 ， 那么就将算法水平比他低及和他相等的人的技能水平加和。 

为了避免重复统计， 可以用bool数组来标记哪些已经统计过。
"""
#python代码：
n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
cnt = Counter(a)
st = [False] * n

ans = 0
for x in cnt:
    if cnt[x] > 1:
        for i in range(n):
            if not st[i] and a[i] & x == a[i]:
                st[i] = True
                ans += b[i]
print(ans)
