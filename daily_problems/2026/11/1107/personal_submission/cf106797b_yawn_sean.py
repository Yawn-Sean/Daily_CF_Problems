# Submission link: https://codeforces.com/gym/106797/submission/397536056
def main(): 
    n, k = MII()
    parent = [-1] + LGMI()
    
    chosen = [0] * n
    dis = [0] * n
    
    for i in range(n - 1, 0, -1):
        if dis[i] == k - 1:
            chosen[i] = 1
        else:
            dis[parent[i]] = fmax(dis[parent[i]], dis[i] + 1)
    
    chosen[0] = 1
    
    print(sum(chosen))
    print(' '.join(f'{i + 1}' for i in range(n) if chosen[i]))