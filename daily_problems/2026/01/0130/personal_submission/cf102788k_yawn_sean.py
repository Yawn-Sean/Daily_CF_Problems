# Submission link: https://codeforces.com/gym/102788/submission/360466277
def main(): 
    n, m = MII()
    bin_2s = []
    
    for i in range(m):
        s = I()
        source, tmp, target = 'A', 'C', 'B'
        
        bin_2 = []
        
        for c in reversed(s):
            if c == target:
                bin_2.append(1)
                source, tmp = tmp, source
            else:
                bin_2.append(0)
                tmp, target = target, tmp
        
        bin_2s.append(bin_2)
    
    print(bin_2s.index(max(bin_2s)) + 1)