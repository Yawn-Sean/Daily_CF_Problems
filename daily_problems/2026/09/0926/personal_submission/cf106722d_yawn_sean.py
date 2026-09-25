# Submission link: https://codeforces.com/gym/106722/submission/391957838
def main():
    def query(i, step):
        print('?', i, step, flush=True)
        return I() == 'Yes'
    
    n = II()
    
    cycle_size = n
    
    for i in range(1, n + 1):
        while cycle_size > 1 and query(i, cycle_size - 1):
            cycle_size -= 1
    
    ans = []
    
    for i in range(1, n + 1):
        if query(i, cycle_size):
            ans.append(i)
    
    print('!', len(ans), ' '.join(map(str, ans)))