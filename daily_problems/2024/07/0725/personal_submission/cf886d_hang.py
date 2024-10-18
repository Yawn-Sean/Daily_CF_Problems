# 好难 不会 题解：https://github.com/Yawn-Sean/Daily_CF_Problems/blob/main/daily_problems/2024/07/0725/solution/cf886d.md
def main():
    g =  [-1] * 26
    used = [-1] * 26
    n = int(input())
    for i in range(n):
        s = input()
        pos = -1
        for c in s:
            c = ord(c) - ord('a')
            if used[c] == i:
                print("NO")
                return
            used[c] = i
            if pos != -1:
                if g[pos] != -1 and g[pos] != c:
                    print("NO")
                    return
                g[pos] = c
            pos = c
    deg = [0] * 26
    for i in range(26):
        if g[i] != -1:
            deg[g[i]] += 1
    if max(deg) > 1:
        print("NO")
        return
    ans = []
    for i in range(26):
        if deg[i] == 0 and used[i] >= 0:
            used[i] = -1
            ans.append(chr(ord('a') + i))
            while g[i] != -1:
                i = g[i]
                used[i] = -1
                ans.append(chr(ord('a') + i))
    for i in range(26):
        if used[i] != -1:
            print("NO")
            return
    print(''.join(ans))
main()
