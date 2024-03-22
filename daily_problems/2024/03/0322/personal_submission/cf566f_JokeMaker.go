package main 

import (
    "fmt"
    "os"
    "bufio"
    "sort"
)

func max(i, j int) int {if i < j {return j}; return i} 

func main() {
    in := bufio.NewReader(os.Stdin)
    out := bufio.NewWriter(os.Stdout)
    var n int
    fmt.Fscan(in, &n)
    a := make([]int, n)
    for i := 0; i < n; i++ {
        fmt.Fscan(in, &a[i])
    }
    sort.Ints(a)
    dp := make([]int, int(1e6 + 1))
    cnt := make([]int, int(1e6 + 1))
    for _, x := range a {
        cnt[x]++
    }
    for i := 0; i < int(1e6 + 1); i++ {
        dp[i] += cnt[i]
        for j := i; j < int(1e6 + 1); j += i {
            dp[j] = max(dp[j], dp[i])
        }
    }
    ans := 0
    for _, x := range dp {
        ans = max(ans, x)
    }
    fmt.Fprintln(out, ans)
    out.Flush()
}
