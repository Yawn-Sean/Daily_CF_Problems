# Submission link: https://codeforces.com/gym/106247/submission/363603529
def main(): 
    n = II()
    if n == 1:
        print(1)
        print(1)
    elif n == 2:
        print(-1)
    else:
        print(3 << n - 2)
        print(1, 2, *(3 << i for i in range(n - 2)))