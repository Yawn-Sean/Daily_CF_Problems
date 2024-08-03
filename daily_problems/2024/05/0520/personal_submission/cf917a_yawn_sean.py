# Submission link: https://codeforces.com/contest/917/submission/261711236
def main():
    s = I()
    n = len(s)

    def f(x, y):
        return x * n + y

    ans = [0] * (n * n) 

    for i in range(n):
        for j in range(i):
            if (j - i) & 1:
                ans[f(j, i)] = 1

    for i in range(n):
        cur = 0
        flg = True
        for j in range(i, n):
            if s[j] == ')': cur -= 1
            else: cur += 1
            if cur < 0: flg = False
            if not flg: ans[f(i, j)] = 0

    for i in range(n):
        cur = 0
        flg = True
        for j in range(i, -1, -1):
            if s[j] == '(': cur -=1 
            else: cur += 1
            if cur < 0: flg = False
            if not flg: ans[f(j, i)] = 0

    print(sum(ans))