'''
464A
2024/8/15 Y1
1700
string / DFS
'''
if __name__ == '__main__':
    n, p = map(int, input().split())
    s = input()
    a = [ord(c) - 97 for c in s]

    def dfs(i):
        global a, p, s
        if i == len(a):
            t = ''.join(chr(x + 97) for x in a)
            if t != s:
                return t
            else:
                return ''
        for x in range(a[i], p):
            a[i] = x
            if i > 0 and x == a[i - 1]:
                continue
            if i > 1 and x == a[i - 2]:
                continue
            t = dfs(i + 1)
            if t:
                return t
        a[i] = 0
        return ''
    ans = dfs(0)
    if not ans:
        ans = 'NO'
    print(ans)
    
    
