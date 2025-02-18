"""
一开始的错误思路：
先按照1，分成不同的0串。在每个0串，找长度为整除 b 的个数的船只的最后一个位置。
在输入字符串的末尾加上 1 

错误点：不能正确处理 b 为 1 的情况
"""
#错误代码段：
s =  input() + '1'
for i,c in enumerate(s):
    if c == '1':
        t = cnt // b
        if t:
            ans.append(i - cnt + b * t)
        cnt = 0
    else:
        cnt += 1

"""
羊神思路种，一个好神奇的点，从百分百命中所有船只的最小值出发。减去 a - 1 个船只，剩下的是最少命中 1 个船的最小值。
妙！
"""
#打卡代码：
n, a, b, k = map(int, input().split())
s =  input()
ans = []
cnt = 0
for i,c in enumerate(s):
    if c == '0':
        cnt += 1
        if cnt == b:
            ans.append(i + 1)
            cnt = 0
    else:
        cnt = 0
t = len(ans) - a + 1
print(t)
print(*ans[:t])
