def main():
    n,k = map(int,input().split())
    s = input()
    t = input()
    c = 1
    res = 0
    for i in range(n):
        c = c * 2
        c = c - int(s[i] == 'b') - int(t[i] == 'a')
        res += min(c, k)
        c = min(c, k + 1)
    print(res)
if __name__ == '__main__':
    main()