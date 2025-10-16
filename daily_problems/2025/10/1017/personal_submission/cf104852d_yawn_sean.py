# Submission link: https://codeforces.com/gym/104852/submission/343954556
def main(): 
    vis = set()
    vis.add(0)
    
    bound = 10 ** 9
    def search(i, j, val):
        if val > bound: return
        
        vis.add(val)
        search(i, j, val * 10 + i)
        search(i, j, val * 10 + j)
    
    for i in range(1, 10):
        for j in range(10):
            search(i, j, i)
    
    n = II()
    ans = 0
    
    for x in vis:
        if n - x in vis:
            ans += 1
    
    print((ans + 1) // 2)