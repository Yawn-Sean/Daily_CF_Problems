package main

import (
    "bufio"
    "fmt"
    "os"
    "sort"
)

func main() {
    in := bufio.NewReader(os.Stdin)
    out := bufio.NewWriter(os.Stdout)
    defer out.Flush()

    var n int
    fmt.Fscan(in, &n)
    nums := make([]int, n)
    for i := 0; i < n; i++ {
        fmt.Fscan(in, &nums[i])
    }

    idx := make([]int, n)
    for i := range idx {
        idx[i] = i
    }

    sort.Slice(idx, func(i, j int) bool {
        return nums[idx[i]] < nums[idx[j]]
    })

    func() {
        pre, ans, x := nums[idx[0]], idx[0], nums[idx[1]]-nums[idx[0]]
        for i := 1; i < n; i++ {
            if nums[idx[i]]-pre != x {
                if ans != idx[0] {
                    ans = -1
                    break
                }
                ans = idx[i]
            } else {
                pre = nums[idx[i]]
            }
        }
        if ans != -1 {
            fmt.Fprintln(out, ans+1)
            return
        }

        pre, ans, x = nums[idx[n-1]], idx[n-1], nums[idx[n-2]]-nums[idx[n-1]]
        for i := n - 1; i >= 0; i-- {
            if nums[idx[i]]-pre != x {
                if ans != idx[n-1] {
                    ans = -1
                    break
                }
                ans = idx[i]
            } else {
                pre = nums[idx[i]]
            }
        }

        if ans != -1 {
            fmt.Fprintln(out, ans+1)
        } else {
            fmt.Fprintln(out, ans)
        }
    }()
}