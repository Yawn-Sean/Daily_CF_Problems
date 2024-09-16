"""
思路:分别判断奇数位置和偶数位置的移动情况

在第一种操作下, 奇数和偶数同时移动.

在第二种操作下, 奇数和偶数的移动次数分别加减, 如果奇数移动了奇数次, 那么奇数在偶数的位置, 要把奇数下调一位, 偶数上调一位. 另一种情况同理.

输出答案时. 遍历 1 ~ n, 如果是奇数, 把奇数移动的次数变成距离,赋值, 偶数同理.
"""
#python代码:
n, q = map(int, input().split())
odd, even = 0, 0

for _ in range(q):
    op = list(map(int, input().split()))
    if op[0] == 1:
        odd += op[1]
        even += op[1]
    else:
        if odd % 2:
            odd -= 1
            even += 1
        else:
            odd += 1
            even -= 1
even %= n
odd %= n
res = [0] * n
for i in range(1, n + 1):
    if i % 2:
        res[(odd + i - 1) % n] = i
    else:
        res[(even + i - 1) % n] = i
print(*res)
