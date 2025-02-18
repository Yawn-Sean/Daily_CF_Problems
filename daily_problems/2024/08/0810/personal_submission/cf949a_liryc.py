'''
https://codeforces.com/contest/949/submission/275504303
949A
2024/8/10 Y1
1600
constructive
'''

s = input()
a0, a1 = [], []
for i, c in enumerate(s):
    if c == '0':
        if a1:
            a = a1.pop()
            a.append(i + 1)
            a0.append(a)
        else:
            a = [i + 1]
            a0.append(a)
    else: # c == '1'
        if not a0:
            a0, a1 = [], []
            break
        a = a0.pop()
        a.append(i + 1)
        a1.append(a)
if a0 and not a1:
    print(len(a0))
    for a in a0:
        print(len(a), end = ' ')
        print(*a)
else:
    print(-1)
