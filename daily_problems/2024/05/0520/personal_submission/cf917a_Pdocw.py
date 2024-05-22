def main():
    s = I()
    n = len(s)
    ans = 0
    for i in range(n):
        cnt = 0
        flag = 0
        for j in range(i, n):
            if s[j] == "(":
                cnt += 1
            elif s[j] == ")":
                cnt -= 1
            else:
                cnt -= 1
                flag += 1
            if cnt < 0:
                if not flag:
                    break
                flag -= 1
                cnt += 2
            if cnt == 0:
                ans += 1
    print(ans)
    return
