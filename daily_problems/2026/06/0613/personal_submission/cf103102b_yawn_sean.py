# Submission link: https://codeforces.com/gym/103102/submission/378267631
def main():
    s = [int(c) for c in I()]
    c1 = 0
    rev = 0
    
    for x in s:
        if x: c1 = (c1 + 1) % 3
        else: rev = (rev + c1) % 3
    
    print('Alice' if rev else 'Bob')