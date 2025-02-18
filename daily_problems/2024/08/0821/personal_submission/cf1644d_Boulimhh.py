"""
思路：判断一个矩阵中除了白色， 可以有多少种涂色方案， 统计方案的数量。

如果存在两个相同的操作， 那么后者的颜色会被存留。 需要从后边的操作开始考虑。 

如果碰到相同的操作， 或者已经染色完所有行，或者所有列。 则跳过接下来的操作。

不是上述两种情况，就把新颜色 + 1， 把行和列的操作加入集合中。

每个操作的颜色都可以从 k 中挑选， 统计最后留存的 cnt 个操作， 答案是 k ^ cnt % mod 。 

"""
#python代码：
MOD = 998244353
for _ in range(int(input())):
    n, m, k, q = map(int, input().split())
    op = []
    for _ in range(q):
        op.append(list(map(int,input().split())))
    row = set() 
    col = set()  
    cnt = 0
    for x, y in op[::-1]:
        if x in row and y in col:
            continue
        if len(row) == n or len(col) == m:
            continue
        cnt += 1
        row.add(x)
        col.add(y)
    print(pow(k, cnt, MOD))
