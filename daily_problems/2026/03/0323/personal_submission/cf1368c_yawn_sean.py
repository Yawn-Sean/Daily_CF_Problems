# Submission link: https://codeforces.com/contest/1368/submission/367776683
def main(): 
    n = II()
    print(3 * n + 4)
    
    for i in range(-1, n):
        print(i, i)
        print(i, i + 1)
        print(i + 1, i)
    
    print(n, n)