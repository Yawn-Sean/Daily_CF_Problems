# Submission link: https://codeforces.com/gym/106644/submission/387218607
def main():
    n = II()
    nums = LII()
    
    z = z_algorithm(nums)
    
    outs = []
    cur = -1
    
    for i in range(1, n):
        if z[i] != n - i:
            cur = i
        outs.append(cur)
    
    print(' '.join(map(str, outs)))