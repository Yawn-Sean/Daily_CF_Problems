# Submission link: https://codeforces.com/gym/104805/submission/337700128
def main():
    n, l = MII()
    l += 1
    
    nums = LII()
    nums = list(set(nums))
    
    vis = {1}
    que = [1]
    
    for x in que:
        for v in nums:
            nx = x * (v + 1)
            if nx <= l and nx not in vis:
                vis.add(nx)
                que.append(nx)
    
    print(len(vis) - 1)