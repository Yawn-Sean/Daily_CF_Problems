"""
浅浅打个表分析一下： 

x  2x  2x+1
1  2   3
2  4   5
3  6   7
4  8   9
5  10  11
6  12  13
规律很明显了， 只有 n 是奇数并且 大于 2 才能操作

可以看到 13 只出现了一次， 考虑倒序遍历 

因为 12 也只出现了 1 次， 并且 12 和 13 是连着的， 可以一次消去两个， 而且要消去两个的最大值， 并和 0 取最大， 

最后统计答案就行
"""
# python代码：
n = int(input())
a = [0] + list(map(int, input().split()))
if n == 1 or n & 1 == 0:
    print(-1)
    exit()
res = 0
for i in range(n, 0, -2):
    mx = max(a[i], a[i - 1], 0)
    a[i - 1] -= mx
    a[i - 1 >> 1] -= mx
    res += mx
print(res)
