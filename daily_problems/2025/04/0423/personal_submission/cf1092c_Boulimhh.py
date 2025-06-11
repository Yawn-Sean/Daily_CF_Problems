"""
题目有说长度相同的串一定是一个前缀一个后缀， 分别记录下标， 对长度进行排序。

最长的两个一定是一个是前缀一个是后缀， 分别判断两种情况。

判断过程中首先遍历一次， 得到每个串可以是：前缀、后缀、都可

对于都可的情况， 如果相同长度下两个串都是都可， 把相同长度的下标取出来， 对其分别赋值为 s 和 p

如果相同长度下只有一个都可， 看另一个长度， 将都可对应的赋值为 s 或 p 
"""
# python 代码
n = int(input())
s, res, e = [], [''] * (2 * n - 2), []
for i in range(2 * n - 2):
    t = input()
    e.append((t, i))
e.sort(key = lambda x: len(x[0]))

def f(s):
    for t, l in e:
        if s.startswith(t) and s.endswith(t):
            res[l] = "*"
        elif s.startswith(t):
            res[l] = "P"
        elif s.endswith(t): res[l] = "S"
        else: return False
    a, b = res.count("P"), res.count("S")
    if a > n - 1 or b > n - 1: return False
    for i in range(n - 1):
        p, q = e[i * 2][1], e[i * 2 + 1][1]
        if res[p] == '*' and res[q] == '*':
            res[p] = "P"
            res[q] = "S"
            a, b = a + 1, b + 1
        elif res[p] == '*':
            res[p] = "S" if res[q] == "P" else "P"
        elif res[q] == '*':
            res[q] = "S" if res[p] == "P" else "P"
    return True
    
if f(e[-1][0] + e[-2][0][-1]):
    print("".join(res))
elif f(e[-2][0] + e[-1][0][-1]):
    print("".join(res))
