'''
https://codeforces.com/contest/353/submission/279941153
353D 2024/9/5 Y2
2000
math
'''

s = input()
mc, fc, ans = 0, 0, 0
for i, x in enumerate(s):
    if x == 'M':
        mc += 1
    else:
        if mc > 0:
            fc = max(fc + 1, mc)
            ans = max(ans, fc)
print(ans)
