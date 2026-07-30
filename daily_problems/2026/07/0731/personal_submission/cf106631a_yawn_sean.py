# Submission link: https://codeforces.com/gym/106631/submission/384840547
def main():
    t = II()
    
    for _ in range(t):
        print('MUL', 1, flush=True)
        lcm_val = II()
        print('MUL', lcm_val, flush=True)
        lcm_val_a = II()
        a = lcm_val_a // lcm_val
        print('DIV', lcm_val_a, flush=True)
        b = II()
        print('ANS', a, b, flush=True)