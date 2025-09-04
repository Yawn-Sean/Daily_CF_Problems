# Submission link: https://codeforces.com/contest/901/submission/336878156
def main():
    n = II()
    nums = LII()
    
    for h in range(n):
        if nums[h] > 1 and nums[h + 1] > 1:
            print('ambiguous')
            
            total = sum(nums)
            
            depth = [0] * total
            chosen_node = [0] * (n + 1)
            
            pt = 0
            
            for i in range(total):
                while nums[pt] == 0: pt += 1
                depth[i] = pt
                nums[pt] -= 1
                chosen_node[depth[i]] = i
            
            ans = [0] * total
    
            for i in range(1, total):
                ans[i] = chosen_node[depth[i] - 1] + 1
            
            print(' '.join(map(str, ans)))
            
            for i in range(1, total):
                if depth[i] == h + 1:
                    ans[i] = chosen_node[depth[i] - 1]
                    break
            
            print(' '.join(map(str, ans)))
            
            exit()
    
    print('perfect')