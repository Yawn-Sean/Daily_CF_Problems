def main():
    m = int(input())
    s = input()
    s = [ord(i)  - ord('a')  for i in s]
    n = len(s)
    for i in range(26):
        idx = -1
        for j in range(n):
            if s[j] <= i:
                idx = j
            elif j - idx >= m:
                break
        else:
            cnt = [0] * 26
            idx = -1
            pos = -1
            for j in range(n):
                if s[j] < i:
                    idx = j
                    cnt[s[j]] += 1
                elif s[j] == i:
                    pos = j
                if j - idx == m:
                    cnt[s[pos]] += 1
                    idx = pos
            print(''.join(chr(i + 97) * cnt[i] for i in range(26)))
            return
main()