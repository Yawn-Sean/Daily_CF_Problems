# Submission link: https://codeforces.com/gym/104013/submission/362774557
def main(): 
    def swap(i, j):
        print(i, j, flush=True)
        if I()[0] == 'W': exit()
    
    n = II()
    
    for _ in range(n):
        for i in range(1, n):
            swap(i, i + 1)
        
        for i in range(n, 2, -1):
            swap(i - 1, i)