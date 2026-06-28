# Submission link: https://codeforces.com/gym/106020/submission/380423934
def main():
    n = II()
    path = [[] for _ in range(n)]
    
    for _ in range(n - 1):
        u, v = GMI()
        path[u].append(v)
        path[v].append(u)
    
    possible = [[1] * n for _ in range(3)]
    ans = [-1] * n
    
    for i in range(n):
        if ans[i] == -1:
            chosen = 0
            for j in range(3):
                if possible[j][i] == 1:
                    chosen = j
                    break
            
            for j in range(3):
                if j != chosen:
                    possible[j][i] = 0
            
            ans[i] = chosen
            que = [i]
            
            for u in que:
                for v in path[u]:
                    if ans[v] == -1:
                        possible[ans[u]][v] = 0
                        
                        c = 0
                        for j in range(3):
                            c += possible[j][v]
                        
                        if c == 1:
                            for j in range(3):
                                if possible[j][v]:
                                    ans[v] = j
                            que.append(v)
    
    print(''.join(chr(ord('a') + x) for x in ans))