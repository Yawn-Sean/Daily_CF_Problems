# Submission link: https://codeforces.com/contest/386/submission/258952014
def main():
    s = I()
    n = len(s)

    last_pos = [-1] * 27
    sorted_last_pos = [-1] * 27

    ans = [0] * 26

    for i in range(n):
        c = ord(s[i]) - ord('a')
        sorted_last_pos.remove(last_pos[c])
        last_pos[c] = i
        sorted_last_pos.append(i)
        
        for j in range(26):
            ans[25 - j] += sorted_last_pos[j+1] - sorted_last_pos[j]

    while ans[-1] == 0:
        ans.pop()

    print(len(ans))
    print(*ans, sep='\n')