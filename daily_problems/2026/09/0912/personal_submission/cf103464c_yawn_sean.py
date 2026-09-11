# Submission link: https://codeforces.com/gym/103464/submission/390321946
def main():
    n = II()
    s = [ord(c) - ord('a') for c in I()]
    
    manacher = [0] * (n - 1)
    
    ans = 0
    chosen_idx = 0
    
    for i in range(n - 1):
        if chosen_idx + manacher[chosen_idx] >= i and 2 * chosen_idx >= i:
            manacher[i] = fmin(manacher[2 * chosen_idx - i], chosen_idx + manacher[chosen_idx] - i)
        
        l = i - manacher[i] + 1
        r = i + manacher[i]
        
        while l > 0 and r + 1 < n and s[l - 1] != s[r + 1]:
            l -= 1
            r += 1
            manacher[i] += 1
        
        if i + manacher[i] > chosen_idx + manacher[chosen_idx]:
            chosen_idx = i
    
    print(max(manacher) * 2)
