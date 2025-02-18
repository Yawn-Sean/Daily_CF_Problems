# Submission link: https://codeforces.com/contest/95/submission/296779530
def main():
    s = I()
    n = len(s)

    if n % 2:
        x = (n + 1) // 2
        print('4' * x + '7' * x)

    else:
        x = n // 2
        tmp = '7' * x + '4' * x
        if tmp < s: print('4' * (x + 1) + '7' * (x + 1))
        else:
            ans = [''] * n
            c4 = x
            c7 = x
            flg = False
            for i in range(n):
                if flg:
                    if c4:
                        ans[i] = '4'
                        c4 -= 1
                    else:
                        ans[i] = '7'
                        c7 -= 1
                else:
                    if s[i] == '4':
                        if c4:
                            ans[i] = '4'
                            c4 -= 1
                        else:
                            flg = True
                            ans[i] = '7'
                            c7 -= 1
                    elif s[i] > '4' and s[i] <= '7' and c7:
                        if s[i] != '7':
                            flg = True
                        ans[i] = '7'
                        c7 -= 1
                    elif s[i] > '4':
                        for j in range(i - 1, -1, -1):
                            if ans[j] == '4':
                                if c7:
                                    c4 += 1
                                    ans[j] = '7'
                                    c7 -= 1
                                    for k in range(j + 1, n):
                                        if c4: 
                                            ans[k] = '4'
                                            c4 -= 1
                                        else:
                                            ans[k] = '7'
                                            c7 -= 1
                                    break
                                else:
                                    c4 += 1
                            else:
                                c7 += 1
                        break
                    else:
                        flg = True
                        if c4:
                            ans[i] = '4'
                            c4 -= 1
                        else:
                            ans[i] = '7'
                            c7 -= 1
            print(''.join(ans))