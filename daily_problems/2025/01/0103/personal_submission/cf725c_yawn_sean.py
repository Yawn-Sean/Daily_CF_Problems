# Submission link: https://codeforces.com/contest/725/submission/299414687
def main():
    s = I()
    vis = [-1] * 26

    for i in range(27):
        c = ord(s[i]) - ord('A')
        if vis[c] == -1: vis[c] = i
        else:
            if vis[c] == i - 1: print('Impossible')
            else:
                x = i - vis[c] - 1
                ans = [[''] * 13 for _ in range(2)]
                for j in range(x - x // 2):
                    ans[0][j] = s[i - (x - x // 2 - j)]
                for j in range(x // 2):
                    ans[1][j] = s[vis[c] + x // 2 - j]
                ans[1][x // 2] = s[i]
                
                sx, sy = 1, x // 2
                for j in range(vis[c] - 1, -1, -1):
                    sy += 1 if sx == 1 else -1
                    if sy >= 13:
                        sx = 0
                        sy = 12
                    ans[sx][sy] = s[j]
                
                sx, sy = 0, x - x // 2 - 1
                for j in range(i + 1, 27):
                    sy += -1 if sx == 1 else 1
                    if sy >= 13:
                        sx = 1
                        sy = 12
                    ans[sx][sy] = s[j]
                
                print(''.join(ans[0]))
                print(''.join(ans[1]))
            exit()