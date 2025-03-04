if __name__ == '__main__':
    k = int(input())
    words = input().replace(" ", "-").split("-")
    lens = [len(word) + 1 for word in words]
    lens[-1] -= 1
    
    l, r = max(lens), sum(lens)
    while l < r:
        mid = (l + r) // 2
        lines, last_line = 1, lens[0]
        for word_len in lens[1:]:
            if last_line + word_len <= mid:
                last_line += word_len
            else:
                lines += 1
                last_line = word_len
        if lines <= k:
            r = mid
        else:
            l = mid + 1
    print(l)