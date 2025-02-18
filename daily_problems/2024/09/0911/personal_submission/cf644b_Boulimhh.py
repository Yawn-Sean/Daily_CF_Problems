"""
思路：很明显要用队列来模拟， 按照题意翻译。

这里要考虑结束时间， 是处理完上一个任务的时间，和当前任务开始的时间取最大值， 再加上当前任务的时间。

如果不被处理， 输出 -1 .

"""
#python代码：
n, b = map(int, input().split())
q = deque()
res = 0
for _ in range(n):
    t, d = map(int, input().split())
    while q and t >= q[0]:
        q.popleft()
    if len(q) <= b:
        res = max(t, res) + d
        q.append(res)
        print(res, end = ' ')
    else:
        print(-1, end = ' ')
