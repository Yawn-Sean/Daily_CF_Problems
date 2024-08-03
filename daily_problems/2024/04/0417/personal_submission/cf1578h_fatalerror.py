"""
双栈计算表达式。'()'表示0，'a->b'表示max(a+1, b)且从右向左计算，'(...)'表示优先计算括号内的表达式。
"""

import sys
input = lambda: sys.stdin.readline().rstrip()

s = '(' + input() + ')'
i, n = 0, len(s)
opstk = []
numstk = []

while i < n:
    if s[i] == '(':
        if s[i+1] == ')':
            numstk.append(0)
            i += 2
        else:
            opstk.append('(')
            i += 1
    elif s[i] == ')':
        num = numstk.pop()
        while opstk[-1] == '-':
            opstk.pop()
            num = max(num, numstk.pop()+1)
        opstk.pop()
        numstk.append(num)
        i += 1
    else:
        opstk.append('-')
        i += 2

print(numstk[-1])

