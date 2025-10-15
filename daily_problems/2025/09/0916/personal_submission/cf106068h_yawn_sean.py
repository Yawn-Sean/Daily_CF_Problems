# Submission link: https://codeforces.com/gym/106068/submission/338709263
def main():
    n = II()
    nums = LII()
    
    q = II()
    outs = []
    
    cubes = [i ** 3 for i in range(n + 1)]
    
    for _ in range(q):
        query = LII()
        
        if query[0] == 1:
            nums[query[1] - 1] = query[2]
        else:
            idx = query[1]
            
            if n - idx >= 1000: outs.append(n)
            elif idx - 1 >= 1000: outs.append(1)
            else:
                idx -= 1
                for j in range(n):
                    if cubes[abs(idx - j)] >= nums[j]:
                        outs.append(j + 1)
                        break
                else:
                    outs.append(-1)
    
    print('\n'.join(map(str, outs)))