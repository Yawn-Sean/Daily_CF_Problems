package main

import (
    "bufio"
    "fmt"
    "os"
)

func main() {
    in := bufio.NewReader(os.Stdin)
    out := bufio.NewWriter(os.Stdout)
    var n int
    fmt.Fscan(in, &n)

    nums := make([][]int, 2)
    for i := range nums {
        nums[i] = make([]int, n)
    }

    for i := 0; i < n; i++ {
        var a, b int
        fmt.Fscan(in, &a, &b)
        nums[0][i] = a
        nums[1][i] = b
    }

    check := func(val int) {
        for j := 1; j < n; j++ {
            for idx := 0; idx < 2; idx++ {
                if nums[idx][j]%val == 0 {
                    break
                }
                if idx == 1 {
                    return
                }
            }
        }
        fmt.Fprintln(out, val)
        out.Flush()
        os.Exit(0)
    }

    for i := 0; i < 2; i++ {
        v := nums[i][0]
        x := 2
        for x*x <= v {
            if v%x == 0 {
                for v%x == 0 {
                    v /= x
                }
                check(x)
            }
            x++
        }
        if v > 1 {
            check(v)
        }
    }
    fmt.Fprintln(out, -1)
    out.Flush()
}