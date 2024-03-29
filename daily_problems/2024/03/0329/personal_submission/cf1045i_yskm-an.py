# 只展示主函数
n = int(input())
find = defaultdict(int)
res = 0
for _ in range(n):
    num = 0
    s = input().strip()
    for x in s:
        num ^= (1 << ord(x) - ord('a'))
    res += find[num]
    for i in range(26):
        p = 1 << i
        nu = p ^ num
        res += find[nu]
    find[num] += 1
print(res)
