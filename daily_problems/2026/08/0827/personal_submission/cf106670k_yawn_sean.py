# Submission link: https://codeforces.com/gym/106670/submission/388420928
def main():
    t = II()
    outs = []
    
    for _ in range(t):
        n = II()
        v1 = LII()
        v2 = LII()
        
        outs.append(min(
            v1[0] + v2[n - 1],
            v2[0] + v1[n - 1],
            sum(v1),
            sum(v2),
            v1[0] + v1[n - 1] + min(v2),
            v2[0] + v2[n - 1] + min(v1)
        ))
    
    print('\n'.join(map(str, outs)))