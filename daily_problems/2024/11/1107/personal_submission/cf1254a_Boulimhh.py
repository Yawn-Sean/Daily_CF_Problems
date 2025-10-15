"""
思路：确定每个🐥吃多少米很容易，数学O（1）解决。

接下来是分配的问题， 一开始分配没思路，看了下羊神题解，决定奇数行顺序， 偶数行倒序进行。

在循环里只需判断是不是吃到了目标的米， 并记录。
"""
#python代码：
s = [chr(ord("a")+i) for i in range(26)] + [chr(ord("A")+i) for i in range(26)] + [chr(ord("0")+i) for i in range(10)]

for _ in range(int(input())):
    r, c, k = map(int, input().split())
    g = [[1 if c == 'R' else 0 for c in input()] for _ in range(r)]
    count1 = sum(s.count(1) for s in g)
    d, m = divmod(count1, k)
    nums = [d] * (k - m) + [d + 1] * m

    ans = [[0] * c for _ in range(r)]
    idx, cur = 0, 0
    
    for i in range(r):
        q = range(c) if i % 2 == 0 else reversed(range(c))
        for j in q:
            ans[i][j] = s[min(idx, k - 1)]
            if g[i][j]:
                cur += 1
                if cur == nums[idx]:
                    idx += 1
                    cur = 0   
    for x in ans:
        print("".join(x))
