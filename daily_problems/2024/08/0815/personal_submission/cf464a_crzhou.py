def solve():
    n, m = map(int, input().split())
    s = input()
    s = ' ' + s
    i = n
    s = list(s)
    s[i] = chr(ord(s[i]) + 1)

    while 1 <= i <= n:
        if s[i] >= chr(m + ord('a')):
            s[i] = 'a'
            i -= 1
            s[i] = chr(ord(s[i]) + 1)
        elif (i > 1 and s[i] == s[i - 1]) or (i > 2 and s[i] == s[i - 2]):
            s[i] = chr(ord(s[i]) + 1)
        else:
            i += 1

    if i == 0:
        print("NO")
    else:
        s = ''.join(s[1:])
        print(s)

if __name__ == "__main__":
    solve()
