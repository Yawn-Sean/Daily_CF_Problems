# Submission link: https://codeforces.com/gym/106511/submission/373414234
def main():
    def query(v1, v2):
        if len(v1) == 0 or len(v2) == 0: return (-2, -2)
        print('?', len(v1), *(x + 1 for x in v1), len(v2), *(x + 1 for x in v2), flush=True)
        return GMI()
    
    n = II()
    ans = [-2] * n
    
    block = 20
    
    for i in range(0, n, block):
        for j in range(0, n, block):
            while True:
                to_query1 = [x for x in range(i, i + block) if x < n and ans[x] == -2]
                to_query2 = [x for x in range(j, j + block) if x < n]
                u, v = query(to_query1, to_query2)
                if u >= 0: ans[u] = v
                else: break
    
    print('!', *(x + 1 for x in ans))