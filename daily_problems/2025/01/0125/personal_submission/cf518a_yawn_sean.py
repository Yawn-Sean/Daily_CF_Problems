# Submission link: https://codeforces.com/contest/518/submission/302815390
def main():
    s1 = I()
    s2 = I()

    n = len(s1)

    for i in range(n):
        if s1[i] != s2[i]:
            flg = False
            for j in range(i + 1, n):
                if s1[j] != 'z':
                    flg = True
            if flg:
                print(s1[:i + 1] + 'z' * (n - i - 1))
            else:
                ans = s1[:i] + chr(ord(s1[i]) + 1) + 'a' * (n - i - 1)
                print(ans if ans < s2 else 'No such string')
            break