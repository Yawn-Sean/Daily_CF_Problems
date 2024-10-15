# Submission link: https://codeforces.com/contest/464/submission/276461061
def main():
    n, p = MII()
    s = [ord(c) - ord('a') for c in I()]

    for i in range(n - 1, -1, -1):
        for c in range(s[i] + 1, p):
            flg = True
            for j in range(1, 3):
                if i - j >= 0 and s[i - j] == c:
                    flg = False
            if flg:
                s[i] = c
                for idx in range(i + 1, n):
                    for c in range(p):
                        flg = True
                        for j in range(1, 3):
                            if idx - j >= 0 and s[idx - j] == c:
                                flg = False
                        if flg:
                            s[idx] = c
                            break
                print(''.join(chr(x + ord('a')) for x in s))
                exit()

    print('NO')