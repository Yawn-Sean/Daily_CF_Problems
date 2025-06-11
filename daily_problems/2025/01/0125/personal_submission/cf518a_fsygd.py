def main():
    s = input()
    t = input()
    for i in range(len(s) - 1, -1, -1):
        if s[i] != 'z':
            ans = s[:i] + chr(ord(s[i]) + 1) + 'a' * len(s[i + 1:])
            break
    if s < ans and ans < t:
        print(ans)
    else:
        print('No such string')

if __name__ == '__main__':
    main()