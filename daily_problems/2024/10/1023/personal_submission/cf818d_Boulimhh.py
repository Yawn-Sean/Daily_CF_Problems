"""
思路： 原本想一个数组统计次数， 一个数组判断 t 或 f。 最后发现有点不可行。 吃了好几发 wa 。

最后看了看题解， 原来一个数组就可以解决， 设计的确实米奇妙妙屋到家了。
"""
#python代码：
n, a = map(int, input().split())
c = list(map(int, input().split()))
ma = max(max(c), a)

f = [0] * (ma + 1)
for x in c:
    if f[x] < f[a]: f[x] = -1
    f[x] += 1
k = f[a]
f[0] = f[a] = -1
s = max(f)
print(f.index(s) if s >= k else -1)
