"""
思路：最好的情况是退出节点分配的数比较均匀， 构成一个星状图。

均匀的情况下，每个退出节点到星状图中心点的距离都相等， 设为 d， d 可以直接由 n，k 两个数得出。

从 1 开始向外扎，每圈扎 k 个， 直到扎完，输出每次扎的情况。

"""
# python代码：
n, k = map(int, input().split())
p, q = divmod(n - 1, k)
d = p * 2 + min(2, q)
print(d)
for i in range(2, n + 1):
	print(i, max(i - k, 1))
