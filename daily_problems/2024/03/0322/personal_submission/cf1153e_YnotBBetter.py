import sys
input = lambda: sys.stdin.readline().strip()

# 假设查询矩形得到的结果为 x
#   如果 x 为奇数说明头尾一个在矩形内，一个在矩形外
#   如果 x 为偶数说明头尾要么都在矩形内，要么都在矩形外
# 想象使用尺寸为 1 * n 的矩形从上至下扫描，即查询为 (x, 1), (x, n)
# 假设头尾的横坐标分别为 x1, x2，其中 x1 < x2
# 则当且仅当 x == x1 或 x == x2 时，x 为奇数，否则查询结果为偶数，同样地，也可以从左到右扫描找到 y1 和 y2
# 此时，头尾的位置有两种可能的选择：(x1, y1), (x2, y2) or (x1, y2), (x2, y1)
# 我们可以随意查询某个点，如果结果为奇数，说明该点是头尾
# 上述的过程有一个 x1 < x2 的前提，如果 x1 == x2，那么在扫描的过程中，所有的结果都会是偶数
# 此时我们知道 y1 和 y2，通过查询 (1, 1), (x, y1) 来二分得到具体的 x，当 x 小于真实值时结果为偶数，否则为奇数
# 同样的，如果 y1 == y2，我们知道 x1 和 x2，可以通过查询 (1, 1), (x1, y) 来二分

n = int(input())

x = []
for i in range(1, n + 1):
    print("? " + " ".join(map(str, [i, 1, i, n])), flush=True)
    if int(input()) & 1:
        x.append(i)

y = []
for i in range(1, n + 1):
    print("? " + " ".join(map(str, [1, i, n, i])), flush=True)
    if int(input()) & 1:
        y.append(i)

if x and y:
    print("? " + " ".join(map(str, [x[0], y[0], x[0], y[0]])), flush=True)
    if int(input()) & 1:
        print("! " + " ".join(map(str, [x[0], y[0], x[1], y[1]])))
    else:
        print("! " + " ".join(map(str, [x[0], y[1], x[1], y[0]])))
elif x:
    l, r = 1, n
    while l < r:
        mid = l + (r - l) // 2
        print("? " + " ".join(map(str, [1, 1, x[0], mid])), flush=True)
        if int(input()) & 1:
            r = mid
        else:
            l = mid + 1
    print("! " + " ".join(map(str, [x[0], l, x[1], l])))
elif y:
    l, r = 1, n
    while l < r:
        mid = l + (r - l) // 2
        print("? " + " ".join(map(str, [1, 1, mid, y[0]])), flush=True)
        if int(input()) & 1:
            r = mid
        else:
            l = mid + 1
    print("! " + " ".join(map(str, [l, y[0], l, y[1]])))
