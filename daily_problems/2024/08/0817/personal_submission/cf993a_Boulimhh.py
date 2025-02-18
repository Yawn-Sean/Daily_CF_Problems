"""
思路：用中学的两图像相交的方法， 计算两图像中点的距离，与两图像的一半边长之和作比较。 结果 wa 第 14 个样例了

看来只能用点在图像里的方法 进行判断。 跟着羊神学新思路！！！！
"""
# python代码：
def check(p1, p2):
    #分别取出两个对角的值
    x1, y1 = p1[:2]
    x3, y3 = p1[4:6]
    left, right = min(x1, x3), max(x1, x3)
    down, top = min(y1, y3), max(y1, y3)
    for i in range(0, 8, 2):
        if left <= p2[i] <= right and down <= p2[i + 1] <= top:
            return True
    if left * 2 <= p2[0] + p2[4] <= right * 2 and down * 2 <= p2[1] + p2[5] <= top * 2:
        return True
    return False

def swap(x, y):
    return x + y, x - y

s1 = list(map(int, input().split()))
s2 = list(map(int, input().split()))
# 判断是否相交
if check(s1, s2):
    print("YES")
    exit()
for i in range(0, 8, 2):
    s2[i], s2[i + 1] = swap(s2[i], s2[i + 1])
    s1[i], s1[i + 1] = swap(s1[i], s1[i + 1])
if check(s2, s1):
    print("YES")
else:
    print("NO")
