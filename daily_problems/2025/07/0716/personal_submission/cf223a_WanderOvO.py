"""
直接维护一个栈
每次遇到 ) 或者 ] 时，匹配栈里的左括号 ( 或者 [
每次完成一次匹配，就把目前连续的几个匹配上的串拼起来，算做一个候选串
最后检查所有候选串，找 [ 最多的即可
"""

s = input()
stk = []
n = len(s)
candidates = []
for i in range(n):
    if s[i] == '(' or s[i] == '[':
        stk.append(i)
    else:
        if len(stk) > 0:
            if (s[i] == ')' and s[stk[-1]] == '(') or (s[i] == ']' and s[stk[-1]] == '['):
                stk.pop()
                left, right = 0, i
                if len(stk) > 0:
                    left = stk[-1] + 1
                candidates.append((left, right))
            else:
                stk.append(i)
        else:
            stk.append(i)

pre_sum = [0 for _ in range(n + 1)]
for i in range(n):
    if s[i] == '[':
        pre_sum[i + 1] = pre_sum[i] + 1
    else:
        pre_sum[i + 1] = pre_sum[i]

if len(candidates) == 0:
    print(0)
    print()
else:
    res_l, res_r = -1, -1
    max_cnt = -1
    for l, r in candidates:
        if pre_sum[r + 1] - pre_sum[l] > max_cnt:
            max_cnt = pre_sum[r + 1] - pre_sum[l]
            res_l = l
            res_r = r
    print(max_cnt)
    for i in range(res_l, res_r + 1):
        print(s[i], end='')
