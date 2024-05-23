def main(ac=FastIO()):
    """
    url: 
        question:   https://codeforces.com/problemset/problem/1025/C
        submission: https://codeforces.com/contest/1025/submission/261266732
    time: 156 ms
    """
    s = ac.read_str() 
    def get(ss):
        ans, i, n = 0, 0, len(ss)
        while i < n: 
            j = i + 1 
            while j < n and ss[j] != ss[j - 1]: j += 1 
            ans = max(ans, j - i)
            i = j
        return ans 
    print(max(get(s), min(len(s), get(s + s), get(s[-1::-1] + s[-1::-1]))))
