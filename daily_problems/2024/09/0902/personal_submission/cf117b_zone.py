# (x * 10 ^ 9 + y) % mod = 0 
# 判断最小的y是否小于b即可 
# 从小到大枚举x, 判断(-x * 10 ^ 9) % mod > b

a, b, mod = map(int, input().split()) 

ans = -1

for i in range(min(a, mod - 1) + 1):
    if (-i * 10 ** 9) % mod > b: 
        ans = i 
        break 
if ans != -1:
    print(1, str(ans).zfill(9))
else:
    print(2)
