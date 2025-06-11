# Submission link: https://codeforces.com/contest/678/submission/266472438
def main():
    a, b, n, x = MII()
    mod = 10 ** 9 + 7
    
    grid = [[a, b],
            [0, 1]]
    
    print(matrix_mul(matrix_pow(grid, n), [[x], [1]], mod)[0][0])