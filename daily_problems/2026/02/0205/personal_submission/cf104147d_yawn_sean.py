# Submission link: https://codeforces.com/gym/104147/submission/361426542
def main(): 
    fin = open('dotak.in', 'r')
    input = lambda: fin.readline().strip()
    
    t = II()
    outs = []
    
    for _ in range(t):
        n, k = MII()
        v = n * k % (k + 1)
        outs.append('Omda' if v % 2 or v == k else 'Teemo')
    
    print('\n'.join(outs))