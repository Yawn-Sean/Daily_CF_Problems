"""
被题面的样例误导了，以至于以为样例三的答案就是oio， (╯▔皿▔)╯

1、如果是 Oleg 所能用到的字母值都比 Igor 所能用到的字母值小， 那么结果是 O 在开始换一个， I 在 O 后边换一个。

2、如果不是上边这种情况， 那么 O 应该将大的字母都扔到最后， 而 I 应该将小字母也扔到最后

那么可以用两个数组分别存第一种情况和第二种情况， 最后拼起来就是答案

"""
# python代码：
import sys
input = lambda:sys.stdin.readline().strip()

s, t = list(input()), list(input())
s.sort()
t.sort(reverse=True)
n = len(s)

l1, l2, r1, r2 = 0, 0, (n + 1) // 2 - 1 , n // 2 - 1
left, right = [], []
flag = False

for i in range(n):
    if i & 1 == 0:
        if l2 < r2 and s[l1] >= t[l2]:
            flag = True
        if flag:
            right.append(s[r1])
            r1 -= 1
        else:
            left.append(s[l1])
            l1 += 1
    else:  
        if l1 < r1 and s[l1] >= t[l2]:
            flag = True
        if flag:
            right.append(t[r2])
            r2 -= 1
        else:
            left.append(t[l2])
            l2 += 1
right.reverse()
print(''.join(left + right))
