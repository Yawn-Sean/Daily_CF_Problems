"""
a[i] > a[i + 1]，则杀死 a[i + 1]
第一个元素一定保留下来
对于 a[2...n]，如果 a[i] < a[i + 1]，则 a[i + 1] 留下来
相当于把整个序列分成若干个单调递减的段，每段只保留第一个元素
序列单调递增时结束
每个数都是要干掉右边所有比自己小的数才行

事实上就是看每个人到底杀了多少个人，因为杀人开始之后是不间断的
考虑单调栈，从右往左遍历
如果当前元素大于栈顶元素，就得杀掉栈顶元素，计数自己杀了多少个，还得计数当初的栈顶元素杀了多少人
"""

n = int(input())
a = list(map(int, input().split()))

dp = [0 for _ in range(n)]
stk = []
res = 0
for i in range(n - 1, -1, -1):
    cnt = 0
    while len(stk) > 0 and a[stk[-1]] < a[i]:
        cnt = max(cnt + 1, dp[stk[-1]])
        stk.pop()
    stk.append(i)
    dp[i] = cnt
for i in range(n):
    res = max(res, dp[i])
print(res)
