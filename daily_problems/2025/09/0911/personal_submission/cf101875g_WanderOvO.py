"""
被减慢可以认为是车合并了
最终剩余的车，一定满足从左到右速度单调不减
最右边的车不会被减慢
需要先按照初始位置排个序
如果 i 车被 j 车减慢了, i < j, 且 j 车被 k 车减慢了, j < k, 则 i 车一定也会被 k 减慢
只不过有可能先 j 被 k 减慢，然后 i 又被 k 减慢，这没有关系
二分时间，然后检查最终的序列是否从左到右单调不减
从倒数第二辆车开始，从右往左枚举车，看其经过这些时间走到了哪里，是否遇上了右边没被减慢的某辆车
遇上了，则本车可以删除掉，没遇上，则保留下来，最后从左到右把保留下来的车的速度比较一下
"""

import sys

input = lambda: sys.stdin.readline().strip()

cars = []

n = int(input())
for i in range(n):
    ss, vv = map(int, input().split())
    cars.append((ss, vv))

cars.sort()

l, r = 0, 1e18
rd = 100

def check(ans):
    merged_cars = [n - 1]
    next = n - 1
    for i in range(n - 2, -1, -1):
        pos_i = cars[i][0] + ans * cars[i][1]
        pos_next = cars[next][0] + ans * cars[next][1]
        if pos_i < pos_next:
            merged_cars.append(i)
            next = i

    for i in range(len(merged_cars) - 1, -1, -1):
        if i - 1 >= 0:
            if cars[merged_cars[i]][1] > cars[merged_cars[i - 1]][1]:
                return False

    return True

for i in range(rd):
    mid = (l + r) / 2
    if check(mid):
        r = mid
    else:
        l = mid

print(l)
