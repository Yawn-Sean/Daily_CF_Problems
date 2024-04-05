# Submission link: https://codeforces.com/contest/444/submission/255038682
def main():
    n = II()
    next_pos = LGMI()
    for i in range(n):
        if next_pos[i] == -2:
            next_pos[i] = i + 1
    
    pos = [[] for _ in range(n + 1)]
    for i in range(n):
        pos[next_pos[i]].append(i)
    
    ans = [0] * n
    cur = 1
    for i in range(n + 1):
        for j in reversed(pos[i]):
            ans[j] = cur
            cur += 1
    
    stack = [n]
    for i in range(n - 1, -1, -1):
        while stack[-1] != n and ans[i] > ans[stack[-1]]:
            stack.pop()
        if next_pos[i] != stack[-1]:
            return [-1]
        stack.append(i)
    return ans
