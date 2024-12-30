# -*- coding: utf-8 -*-
import sys

input = lambda: sys.stdin.readline().rstrip()
# sys.stdin = open('../input.txt', 'r')
I = lambda: int(input())


def get_ret(s: str, x: int) -> int:
    if '?' not in s:
        if int(s) > x:
            return int(s)
        else:
            return -1

    if len(s) < len(str(x)):
        return -1
    elif len(s) > len(str(x)):
        if s[0] == '?':
            s = '1' + s[1:]
        s = s.replace('?', '0')
        return int(s)
    else:
        m = len(s)
        s = list(s)
        t = list(str(x))
        find = False
        stk = []
        for i in range(m):
            if s[i] == '?':
                stk.append(i)
            else:
                if s[i] > t[i]:
                    find = True
                    break
                elif s[i] == t[i]:
                    continue
                elif s[i] < t[i]:
                    find = False
                    break
        if find:
            for i in stk:
                s[i] = t[i]
            s = ''.join(s).replace('?', '0')
            return int(s)
        else:
            if stk:
                while stk:
                    i = stk.pop()
                    if t[i] == '9':
                        continue
                    else:
                        s[i] = str(int(t[i]) + 1)
                        break
                for i in stk:
                    s[i] = t[i]
                s = ''.join(s).replace('?', '0')
                if int(s) > x:
                    return int(s)
                else:
                    return -1
            else:
                return -1


tcn = 3
for _tcn_ in range(tcn):
    n = I()
    ss = [input() for _ in range(n)]
    nums = [0]
    for i in range(n):
        ret = get_ret(ss[i], nums[-1])
        if ret > 0:
            nums.append(ret)
        else:
            break
    if len(nums) == n+1:
        print('YES')
        for i in range(1, n+1):
            print(nums[i])
    else:
        print('NO')
