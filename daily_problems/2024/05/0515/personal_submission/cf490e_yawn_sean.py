# Submission link: https://codeforces.com/contest/490/submission/260991434
def main():
    n = II()
    last = ''
    ans = []

    for _ in range(n):
        s = list(I())
        if len(s) < len(last):
            print('NO')
            exit()
        elif len(s) > len(last):
            for i in range(len(s)):
                if s[i] == '?':
                    s[i] = '1' if i == 0 else '0'
        else:
            for i in range(len(s)):
                if s[i] != '?':
                    if s[i] > last[i]:
                        for j in range(i):
                            if s[j] == '?':
                                s[j] = last[j]
                        for j in range(i + 1, len(s)):
                            if s[j] == '?':
                                s[j] = '0'
                        break
                    elif s[i] < last[i]:
                        for j in range(i + 1, len(s)):
                            if s[j] == '?':
                                s[j] = '0'
                        f = False
                        for j in range(i - 1, -1, -1):
                            if s[j] == '?':
                                if f: s[j] = last[j]
                                else:
                                    if last[j] == '9':
                                        s[j] = '0'
                                    else:
                                        s[j] = chr(ord(last[j]) + 1)
                                        f = True
                        if not f:
                            print('NO')
                            exit()
                        break
            else:
                f = False
                for j in range(len(s) - 1, -1, -1):
                    if s[j] == '?':
                        if f: s[j] = last[j]
                        else:
                            if last[j] == '9':
                                s[j] = '0'
                            else:
                                s[j] = chr(ord(last[j]) + 1)
                                f = True
                if not f:
                    print('NO')
                    exit()
        
        last = ''.join(s)
        ans.append(last)

    print('YES')
    print('\n'.join(ans))