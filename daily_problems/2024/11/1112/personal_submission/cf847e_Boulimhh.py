"""
思路： 思路写错了，一开始考虑二分长度，枚举每个p人可以吃到的范围星星。 结果讨论了好几次，蛙了很多样例。
wa的思路：从工人找⭐。判 p 在⭐中间还是旁边，如果是在中间，那么长度是距离边界最短的长度是 1 + x - 短边。在边缘，长度是x + 1 
以长度为分界点判断，看p的位置， 判断p是不是在区间内相邻，是就跳过， 边缘是点也跳过。

看了题解，原来可以枚举 p ，判断⭐是否在这个过程中被遍历完。

小意外： 上界没定成2 * 10 ** 5， 结果wa了一个样例，下次二分还是从临界值开始吧。
        这里的求有边界很有想法，是我想不出来的
"""
#python代码：
n = int(input())
a = list(input())
p = [i for i in range(n) if a[i] == 'P']
s = [i for i in range(n) if a[i] == '*']
m = len(s)
def check(x):
    j = 0
    for pm in p:
        if abs(s[j] - pm) > x:
            continue
        left = max(0, pm - s[j])
        right = pm + max(x - left * 2, (x - left) // 2)
        while j < m and s[j] <= right:
            j += 1 
        if j == m:
            return True
    return j == m
l, r = 0, 2 * 10 ** 5 
while l < r:
    mid = l + r >> 1
    if check(mid):
        r = mid
    else:
        l  = mid + 1
print(l)
