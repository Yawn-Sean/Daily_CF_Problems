"""
思路： 只考虑good点也就可以了，good点的要求其点与其他任意两点连成向量的夹角要大于等于90度。

2维坐标的情况，最多只能存在4个点，才能满足条件。 那么我们也可以猜想在5维状态下大于某个值之后就不存在good点

对不超过某个值的点遍历判断

"""
#python代码：
def judge(x, y, z, point):
    ans = 0
    for i in range(5):
        a = point[y][i] - point[x][i]
        b = point[z][i] - point[x][i]
        ans += a * b
    return ans <= 0


n = int(input())
point = [list(map(int, input().split())) for _ in range(n)]

if n >= 34:
    print(0)
    exit()

ans = []
for i in range(n):
    f = True
    for j in range(n):
        for k in range(n):
            if k == j or k == i:
                continue
            if not judge(i, j, k, point):
                f = False
    if f:
        ans.append(i + 1)

print(len(ans))
print(' '.join(map(str, ans)))
