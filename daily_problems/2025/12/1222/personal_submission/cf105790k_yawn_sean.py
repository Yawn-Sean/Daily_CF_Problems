# Submission link: https://codeforces.com/gym/105790/submission/354443708
def main():  
    n = II()
    mod = 998244353
    print(pow(2, matrix_pow([[1, 1], [1, 0]], n, mod - 1)[0][1], 998244353))