"""
思路： 换一种思考， 算 n mod i, n = 1, 2, 3 .. , n . 再根据式子推导

定义 fi = 1 ^ 2 ^ 3 ^ ... ^ i , 那么有 qi = pi ^ fi-1 ^ fi-1 ^ ... ^ fi-1 ^ fnmodi .

如果 n // i  为奇数， 那么最后剩下一个 fi-1, 不然就没有这一项。

注意到 fnmodi 和 fi-1, 都在 fi 之前算出来了， 所以只需一次循环即可。
""""
#python代码：
n = int(input())
p = list(map(int, input().split()))

a = list(range(n + 1))
res = 0
for i in range(1, n + 1):
    a[i] ^= a[i - 1]
    res ^= p[i - 1] ^ a[n % i] ^ (a[i - 1] if n // i % 2 else 0)
print(res)
