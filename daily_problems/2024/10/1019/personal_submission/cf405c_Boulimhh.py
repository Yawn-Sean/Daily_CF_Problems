"""
思路： 一开始想算每个的乘积， 存一个数组，最后发现行不通。

看了🐏的题解，发现元素可以抵消，只剩下对角线元素， 那么每次改变只会 多出来一个 1。

太妙了

"""
#python代码：
n = int(input())
ans = 0
for i in range(n):
    ans ^= list(map(int, input().split()))[i]
for _ in range(int(input())):
    s = input()
    if s[0] == '3':
        print(ans, end = '')
    else:
        ans ^= 1
