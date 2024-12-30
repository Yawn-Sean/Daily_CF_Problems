"""
思路：由于斜率是相同的， 从前三个点枚举三个可能的斜率。

对每个斜率， 遍历所有数，依次计算当前斜率对应的截距是不是只有两个。

是就满足条件， 如果三个都不满足，输出no

"""
#python代码：
n = int(input())
y = list(map(int, input().split()))

t = 2 * (y[1] - y[0]), 2 * (y[2] - y[1]), y[2] - y[0]
for k in t:
    b = set()
    for i in range(n):
        b.add(y[i] * 2 - i * k)
        if len(b) > 2:
            break
    if len(b) == 2:
        print("Yes")
        exit()
print("No")
