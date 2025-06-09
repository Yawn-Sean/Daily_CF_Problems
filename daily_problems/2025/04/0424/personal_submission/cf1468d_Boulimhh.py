"""
计算小偷和警察之间的距离， 以及小偷可以走的步数

对炸弹进行排序， 如果可以在走的步数内引爆， 那就遍历下一个

如果当前情况下不能引爆， 将t变为可以引爆的时间。
"""
# python 代码
for _ in range(int(input())):
    n, m, x, y = list(map(int, input().split()))
    a = list(sorted(list(map(int, input().split()))))

    d = abs(y - x)
    l = x if y > x else n - x + 1
    t = 1
    i = 0
    while i < len(a) and t < d:
        if t + l - 1 >= a[i]:
            t += 1
            i += 1
        else:
            t += a[i] - (t + l - 1)
    print(i)
