def main():
    n,m = map(int,input().split())
    s = input()
    s = 'a' + s + 'a'
    s = [1 if i == '.' else 0 for i in s]
    res,tot = 0,0 
    for x in s:
        if x == 1:
            tot += 1
        else:
            if tot:
                res += tot - 1
            tot = 0
    ans = []
    for _ in range(m):
        idx, ch = input().split()
        idx = int(idx)
        x = 1 if ch == '.' else 0
        if s[idx] != x:
            if x:
                res += 1
                res += s[idx + 1] and s[idx - 1]
                res -= s[idx - 1] == 0 and s[idx + 1]  == 0
            else:
                res -= 1
                res -= s[idx + 1] and s[idx - 1]
                res += s[idx - 1] == 0 and s[idx + 1]  == 0
        s[idx] = x
        ans.append(res)
    print(*ans,sep='\n')
main()