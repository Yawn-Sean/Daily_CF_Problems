# Submission link: https://codeforces.com/gym/104772/submission/339042918
def main():
    d = II()
    saved = d
    
    while d % 2 == 0:
        d //= 2
    
    while d % 5 == 0:
        d //= 5
    
    cur = 0
    tot = 0
    
    for i in range(1, 10 ** 6):
        cur = (cur * 10 + 9) % d
        tot = (tot + 9) % saved
        
        if cur == 0 and tot == 0:
            print('9' * i + '0' * 13)
            break