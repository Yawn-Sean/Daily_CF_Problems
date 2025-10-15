"""
显然不管怎么删边，至少有一边的最大值是 n，另一边的不好说
删掉和叶子结点相连的边，则某一块就只有一个叶子结点，最大值也就是这个叶子结点的值
非 n 的某个数 i 出现 cnt 次，说明其往“上”走 cnt 步才会遇到一个比自己大的点，且自己的“下”面没有比自己大的
出现 0 次的怎么办？说明下边就有比自己大的
不妨把 n 当成树根
所有出现 1 次的，强制直接连到 n 上
出现 2 次的，需要找一个没出现过且比自己小的点，放到自己上面，然后再连到 n
出现 3 次的，则需要找两个没出现过且比自己小的点，再连到 n
有没有可能，出现 1 次的某个，不直接连到 n，而是连到另一个更大的数上面了？
是有可能的，但是直接连 n 一定是可以的，不直接连也不会省出现 0 次的点
如果最后还剩下为 0 的点，怎么办？不够了又怎么办？无解
"""

n = int(input())
cnt = [0 for _ in range(n + 1)]
for i in range(n - 1):
    u, v = map(int, input().split())
    if v != n:
        print('NO')
        exit(0)

    cnt[u] += 1

zero_nodes = []
for i in range(1, n + 1):
    if cnt[i] == 0:
        zero_nodes.append(i)

res = []
pt = len(zero_nodes) - 1
for i in range(n - 1, -1, -1):
    if cnt[i] != 0:
        chain = [i]
        c = cnt[i] - 1
        while c > 0 and pt >= 0:
            if zero_nodes[pt] < i:
                chain.append(zero_nodes[pt])
                c -= 1
            pt -= 1
        if c > 0:
            print('NO')
            exit(0)

        chain.append(n)
        for j in range(len(chain) - 1):
            res.append((chain[j], chain[j + 1]))

if pt > 0:
    print('NO')
else:
    print('YES')
    assert len(res) == n - 1
    for i in range(len(res)):
        print(res[i][0], res[i][1])
