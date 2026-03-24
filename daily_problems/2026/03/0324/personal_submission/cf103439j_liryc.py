'''
https://codeforces.com/gym/103439/submission/367963260
'''
def solve(n: int, s: str) -> list[str]: 
    ca = s.count('A')
    cb = s.count('B')
    cc = s.count('C')
    if ca == n and cb == n and cc == n: 
        return []
    else:
        l = 0
        r = 0
        while l < 3 * n:
            while max(ca, cb, cc) > n and r < 3 * n:
                if s[r] == 'A': ca -= 1
                elif s[r] == 'B': cb -= 1
                else: cc -= 1
                r += 1
            
            if max(ca, cb, cc) > n: 
                break
            
            if ca == n and cb == n:
                return [f"{l + 1} {r} C"]
            
            if ca == n and cc == n:
                return [f"{l + 1} {r} B"]
            
            if cb == n and cc == n:
                return [f"{l + 1} {r} A"]
            if s[l] == 'A': 
                ca += 1
            elif s[l] == 'B': 
                cb += 1
            else: 
                cc += 1
            l += 1
        
        ca = 0
        cb = 0
        cc = 0
        ans = []
        
        for i in range(3 * n):
            if s[i] == 'A': 
                ca += 1
            elif s[i] == 'B': 
                cb += 1
            else: 
                cc += 1
            
            if ca == n:
                ans.append(f"{i + 2} {3 * n} B")
                ans.append(f"{3 * n - (n - cc) + 1} {3 * n} C")
                break
            
            if cb == n:
                ans.append(f"{i + 2} {3 * n} A")
                ans.append(f"{3 * n - (n - cc) + 1} {3 * n} C")
                break
            
            if cc == n:
                ans.append(f"{i + 2} {3 * n} A")
                ans.append(f"{3 * n - (n - cb) + 1} {3 * n} B")
                break
        return ans
    