# Submission Link: https://codeforces.com/contest/886/submission/272464425
def main():
    graph = [-1] * 26
    vis = [-1] * 26

    n = II()

    for i in range(n):
        s = I()
        last = -1
        for c in s:
            p = ord(c) - ord('a')
            if vis[p] == i:
                print('NO')
                exit()
            vis[p] = i
            if last != -1:
                if graph[last] != -1 and graph[last] != p:
                    print('NO')
                    exit()
                graph[last] = p
            last = p

    indegs = [0] * 26
    for i in range(26):
        if graph[i] >= 0:
            indegs[graph[i]] += 1

    if max(indegs) > 1:
        print('NO')
        exit()

    ans = []
    for i in range(26):
        if indegs[i] == 0 and vis[i] >= 0:
            vis[i] = -1
            ans.append(i)
            while graph[i] != -1:
                i = graph[i]
                vis[i] = -1
                ans.append(i)

    for i in range(26):
        if vis[i] != -1:
            print('NO')
            exit()

    print(''.join(chr(ord('a') + x) for x in ans))