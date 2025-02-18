"""
思路：这题真当呆子坐牢了， 一开始想从大往小算。 

这种不仅要考虑计算之后的数和m哪个比较大， 还需要比较剩下的数和计算出来的谁更小

还是看了🐏从小到大比较好，这两个烦恼都没有了
"""
#python代码：
n, m = map(int, input().split())
a, b = m, m
cnt = 0
while a < n:
    a, b = a + b - 1, a
    cnt += 1
print(cnt + 2)
