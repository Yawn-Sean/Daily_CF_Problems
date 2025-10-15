'''
https://codeforces.com/problemset/submission/725/299422930
725C
2025/01/03 Y1
1600
string construction
'''
#ref 
import sys
input = lambda: sys.stdin.readline().strip()

def init():
    s = input()
    return s

def solve(s: str):
    vis = [-1] * 26
    for i in range(27):
        c = ord(s[i]) - 65
        if vis[c] == -1: 
            vis[c] = i
        else:
            if vis[c] == i - 1: 
                return []
            else:
                x = i - vis[c] - 1
                ans = [[''] * 13 for _ in range(2)]
                for j in range(x + 1 >> 1):
                    ans[0][j] = s[i - ((x + 1 >> 1) - j)]
                for j in range(x >> 1):
                    ans[1][j] = s[vis[c] + (x >> 1) - j]
                ans[1][x >> 1] = s[i]
                
                sx, sy = 1, x >> 1
                for j in range(vis[c] - 1, -1, -1):
                    sy += 1 if sx == 1 else -1
                    if sy >= 13:
                        sx = 0
                        sy = 12
                    ans[sx][sy] = s[j]
                
                sx, sy = 0, (x + 1 >> 1) - 1
                for j in range(i + 1, 27):
                    sy += -1 if sx == 1 else 1
                    if sy >= 13:
                        sx = 1
                        sy = 12
                    ans[sx][sy] = s[j]
                return ans
                

if __name__ == '__main__':
    s = init()
    ans = solve(s)
    if ans:
        print(''.join(ans[0]))
        print(''.join(ans[1]))
    else:
        print("Impossible")
