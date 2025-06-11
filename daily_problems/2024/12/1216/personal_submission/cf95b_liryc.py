'''
https://codeforces.com/problemset/submission/95/296788615
95B
20241216 Y1
1800
DP, greedy
'''
# ref
def solve(s: str) -> str:
    n = len(s)

    if n & 1:
        x = n + 1 >> 1
        return '4' * x + '7' * x
    else:
        x = n >> 1
        tmp = '7' * x + '4' * x
        if tmp < s: 
            return '4' * (x + 1) + '7' * (x + 1)
        else:
            ans = [''] * n
            c4 = x
            c7 = x
            ok = False
            for i in range(n):
                if ok:
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
                            ok = True
                            ans[i] = '7'
                            c7 -= 1
                    elif s[i] > '4' and s[i] <= '7' and c7:
                        if s[i] != '7':
                            ok = True
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
                        ok = True
                        if c4:
                            ans[i] = '4'
                            c4 -= 1
                        else:
                            ans[i] = '7'
                            c7 -= 1
            return ''.join(ans)

if __name__ == '__main__':
    s = input()
    ans = solve(s)
    print(ans)