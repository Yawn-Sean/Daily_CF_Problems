def main():
    n = int(input())
    arr = list(map(int, input().split(' ')))
    ans, start = 0, 0
    while start < n:
        first = -1
        for i in range(start, len(arr)):
            if arr[i] != -1:
                first = i
                break
        if first == -1:
            ans += 1
            break
        
        second = -1
        for i in range(first + 1, len(arr)):
            if arr[i] != -1:
                second = i
                break
        if second == -1:
            ans += 1
            break
        
        if (arr[second] - arr[first]) % (second - first) == 0:
            step = (arr[second] - arr[first]) // (second - first)
            if arr[first] - (first - start) * step <= 0:
                ans += 1
                start = second
            else:
                while second + 1 < len(arr) and arr[second] + step > 0 and (arr[second + 1] == -1 or arr[second + 1] == arr[second] + step):
                    arr[second + 1] = arr[second] + step
                    second += 1
                ans += 1
                start = second + 1
        else:
            ans += 1
            start = second
    print(ans)

if __name__ == '__main__':
    main()