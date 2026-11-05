# Submission link: https://codeforces.com/gym/106797/submission/397291809
def main(): 
    t = II()
    
    for _ in range(t):
        print('? 1 0', flush=True)
        d1 = float(I())
        print('? 1 1', flush=True)
        d2 = float(I())
        
        d = math.sqrt(d1 * d1 + d2 * d2 - d1 * d2 * math.sqrt(2))
        h = d1 * d2 * math.sqrt(2) / 2 / d
        print(f'! {round(4 * h * h)}', flush=True)