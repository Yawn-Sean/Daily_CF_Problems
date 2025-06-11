# Submission link: https://codeforces.com/contest/1153/submission/265424766
def main():
    n = II()
    s = list(I())
    c1 = n // 2 - s.count('(')
    cur = 0
    for i in range(n):
        if s[i] == '(': cur += 1
        elif s[i] == ')': cur -= 1
        elif c1:
            s[i] = '('
            cur += 1
            c1 -= 1
        else:
            s[i] = ')'
            cur -= 1
        if cur <= 0 and i != n - 1:
            print(':(')
            break
    else:
        print(''.join(s) if cur == 0 else ':(')