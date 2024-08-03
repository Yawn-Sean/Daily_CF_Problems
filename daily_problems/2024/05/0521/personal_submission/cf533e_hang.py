def main():
    c = [0] * 26
    n = int(input())
    s = input()
    t = input()
    l,r = 0,n-1
    while l < n:
        if s[l] != t[l]:
            break
        l += 1
    while r >= 0:
        if s[r] != t[r]:
            break
        r -= 1
    if l == r:
        print(2)
        return
    ans = 0
    for i in range(l,r):
        if s[i] == t[i + 1]:
            continue
        else:
            break
    else:
        ans += 1
    for i in range(l,r):
        if s[i+1] == t[i]:
            continue
        else:
            break
    else:
        ans += 1
    print(ans)

if __name__ == '__main__':
    main()