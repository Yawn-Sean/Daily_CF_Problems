# 只想得到暴力O(n^3)的做法
# 枚举去掉哪两个，可是怎么O(1)记录它们的影响呢？

# 先枚举删除一个区间，然后再考虑删除另一个区间
# 考虑的时候：只需要看删去的1最少就行了
n, q = map(int, input().split())
ls, rs = [], []
cur = [0] * n

for _ in range(q):
    l, r = map(int, input().split())
    l, r = l - 1, r - 1
    ls.append(l)
    rs.append(r)

    for i in range(l, r + 1): # 直接记录总个数
        cur[i] += 1
    
ans = 0
for i in range(q): # 先枚举删一个
    for j in range(ls[i], rs[i] + 1):
        cur[j] -= 1
    
    s = [0] * (n + 1) # 记录1的前缀和个数
    cnt = 0 # 大于1的总个数
    for j in range(n):
        s[j + 1] = s[j] # 还可以这样写前缀和
        if cur[j] == 1:
            s[j + 1] += 1
        if cur[j] >= 1:
            cnt += 1
    
    # 枚举删去哪一个
    for j in range(i):
        ans = max(ans, cnt - (s[rs[j] + 1] - s[ls[j]]))
    
    # 补回来
    for j in range(ls[i], rs[i] + 1):
        cur[j] += 1
print(ans)