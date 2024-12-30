"""
思路： 又是看🐏神题解的一天。 捋下思路。

当目标距离和步数的奇偶性不同， 或者目标距离大于现有距离，怎么走都走不到的情况， 打印 -1。

操作之后， 如果到达了目标点，输出 0

剩下就是可以到达的情况。 用双指针遍历数组， 找到中间某段 r - l + 1， 其长度小于去掉这段操作之后， 到达目标距离所需要的步数, 即 abs(x - sx) + abs(y - sy)。

那么这段就是需要更新的段， 答案为 r - （l - 1） + 1 = r - l + 2。

"""
#python代码：
n = int(input())
a = input()
x, y = map(int, input().split())
if abs(x) + abs(y) > n or (x + y + n) % 2:
    print(-1)
else:
    dx, dy = [0] * n, [0] * n
    for i in range(n):
        if a[i] == 'R':
            dx[i] = 1
        elif a[i] == 'L':
            dx[i] = -1
        elif a[i] == 'U':
            dy[i] = 1
        else:
            dy[i] = -1
    sx, sy = sum(dx), sum(dy)
    if sx == x and sy == y:
        print(0)
    else:
        l = 0
        res = n
        for r in range(n):# 减去右边的步数
            sx -= dx[r]
            sy -= dy[r]
            while r - l + 1 >= abs(x - sx) + abs(y - sy):
                sx += dx[l]
                sy += dy[l]
                l += 1
            if l > 0:
                res = min(res, r - l + 1)
        print(res)
