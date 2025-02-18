"""
思路：用 bfs 遍历，不建图， 一个 bool 数组判断一次查询内是否访问过

结果 wa 了， 但是看不了 wa 的样例是什么。

看了题解，把行列数组再进行处理一次， 秒啊！

学了羊神读入的技巧，直接在读入的时候减一 ：  map(lambda x: int(x) - 1, input().split())
"""

#python代码：
n, q = map(int, input().split())
r = list(map(int, input().split()))
c = list(map(int, input().split()))

r1 = list(i for i in range(n))
c1 = list(i for i in range(n))
for i in range(1,n):
    if r[i - 1] % 2 == r[i] % 2:
        r1[i] = r1[i - 1]
    if c[i - 1] % 2 == c[i] % 2:
        c1[i] = c1[i - 1]

for _ in range(q):
    ra, ca, rb, cb =  map(lambda x: int(x) - 1, input().split())
    if r1[ra] == r1[rb] and c1[ca] == c1[cb]:
        print('YES')
    else:
        print("NO")
