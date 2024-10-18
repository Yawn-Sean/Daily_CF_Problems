"""
思路：这里只想到了检查相邻或者间隔的两个。遍历从最后一个开始

对于怎么处理字符串还没想出来。

看了羊神题解，明天得去补一下相关得基础知识。

这里用else语句，来替代羊神的flag判断，
"""

#python 代码：
n, p = map(int, input().split())
s = [ord(c) - ord('a') for c in input()]

for i in range(n - 1, -1, -1):
    for c in range(s[i] + 1, p):
        for j in range(1, 3):
            if i - j >= 0 and s[i - j] == c:
                break
        else:
            s[i] = c
            for idx in range(i + 1, n):
                for c in range(p):
                    for j in range(1, 3):
                        if idx - j >= 0 and s[idx - j] == c:
                            break
                    else:
                        s[idx] = c
                        break
            print(''.join(chr(x + ord('a')) for x in s))
            exit()
else:
    print('NO')
