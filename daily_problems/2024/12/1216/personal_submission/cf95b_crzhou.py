s = I()
n = len(s)

if n % 2:
    n = n // 2 + 1
    ans = '4' * n + '7' * n
else:
    ans = ""
    cnt4 = cnt7 = n // 2
    for i in range(n):
        cur = int(s[i])
        if cur < 4 and cnt4:
            ans += '4' * cnt4 + '7' * cnt7
            break
        elif 4 < cur < 7 and cnt7:
            ans += '7' + '4' * cnt4 + '7' * (cnt7 - 1)
            break
        elif cur == 4 and cnt4:
            ans += '4'
            cnt4 -= 1
        elif cur == 7 and cnt7:
            ans += '7'
            cnt7 -= 1
        else:
            flg = False
            for j in range(i - 1, -1, -1):
                if ans[j] == '4':
                    cnt4 += 1
                    if cnt7:
                        cnt7 -= 1
                        ans = ans[:j] + '7' + '4' * cnt4 + '7' * cnt7
                        flg = True
                        break
                else:
                    cnt7 += 1
            else:
                n = n // 2 + 1
                ans = '4' * n + '7' * n
                break
            if flg:
                break
print(ans)
