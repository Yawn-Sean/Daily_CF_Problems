def main():
    s = input()
    l = 0
    while l < len(s) and s[l] == 'F':
        l += 1
    ans = 0
    cnt = 0
    while l < len(s) :
        if s[l] == 'M':
            cnt += 1
        else:
            ans = max(ans + 1, cnt)
        l += 1
    print(ans)


main()