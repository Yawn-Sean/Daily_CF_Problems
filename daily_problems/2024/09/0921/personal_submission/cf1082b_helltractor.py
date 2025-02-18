def CF1082B():
    n = II()
    s = I()
    cnt = s.count('G')
    ans = i = pre = cntS = 0
    while i < n:
        if s[i] == 'S':
            cntS += 1
            i += 1
        else:
            st = i
            while i < n and s[i] == 'G':
                i += 1
            cur = i - st
            if cntS > 1:
                if cur + 1 <= cnt:
                    ans = fmax(ans, cur + 1)
                else:
                    ans = fmax(ans, cur)
            else:
                if cur + pre == cnt:
                    ans = fmax(ans, cur + pre)
                    break
                if cur + pre + 1 <= cnt:
                    ans = fmax(ans, cur + pre + 1)
            pre = cur
            cntS = 0
    print(ans)
