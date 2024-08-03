# 参考: https://github.com/Yawn-Sean/Daily_CF_Problems/blob/main/daily_problems/2024/04/0403/personal_submission/cf457a_yawn_sean.py
s = input()
t = input()
n = max(len(s), len(t))
s = '0' * (n - len(s)) + s
t = '0' * (n - len(t)) + t

def get():
    a, b = 0, 0
    for p, q in zip(s, t):
        a, b = a + b, a + int(p) - int(q)
        if a > 1:
            return '>'
        elif a < -1:
            return '<'
    if (a, b) == (0, 0):
        return '='
    while abs(a) < 1:
        a, b = a + b, a
    return '>' if a > 0 else '<'

print(get())
