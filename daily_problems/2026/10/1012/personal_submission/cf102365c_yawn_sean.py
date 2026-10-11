# Submission link: https://codeforces.com/gym/102365/submission/394094443
def main():
    n = II()
    leaf = 2
    
    for i in range(3, n + 1):
        print('?', 1, leaf, i, flush=True)
        if II(): leaf = i
    
    print('!', leaf)