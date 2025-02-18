def main():
    n,p = map(int,input().split()) 
    s = input()
    s = [ord(i) - ord('a') for i in s]
    for i in range(n - 1, -1, -1):
        for c in range(s[i] + 1, p):
            for j in range(1, 3):
                if i - j >= 0 and s[i-j] == c:
                    break
            else:
                s[i] = c
                for d in range(i + 1, n):
                    for c in range(p):
                        for j in range(1, 3):
                            if d - j >= 0 and s[d - j] == c:
                                break
                        else:
                            s[d] = c
                            break
                print(''.join([chr(i + ord('a')) for i in s]))
                return
    print('NO')

main()