"""
思路： 有点难读懂的题， 情况分的也有点多。所以这题只能看题解了。

满足题目要求的有三种情况：
1、 字符串长度为1
2、 字符串首尾字母不相同
3、 字符串有超过两个的不同字母

为了快速实现第三种的判断， 用前缀和来存储，实现快速查询是否有大于等于3个的字母

"""
#python代码：
s = input()
n = len(s)
prefix = [[0] * 26]

for i in range(n):
    prefix.append(prefix[-1][:])
    prefix[-1][ord(s[i]) - ord('a')] += 1

for i in range(int(input())):
    l, r = map(lambda x: int(x) - 1, input().split())
    flag = 0
    for c in range(26):
        flag += (prefix[r + 1][c] - prefix[l][c] > 0)
    if l == r or s[l] != s[r] or flag >= 3:
        print("Yes")
    else:
        print("No")
