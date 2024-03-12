package main

import (
    "bufio"
    "fmt"
    "os"
    "math"
)

func max(x, y float64) float64 {
    if x > y {
        return x
    }
    return y
}

func min(x, y float64) float64 {
    if x < y {
        return x
    }
    return y
}

func main() {
    in := bufio.NewReader(os.Stdin)
    out := bufio.NewWriter(os.Stdout)
    var n int
    fmt.Fscan(in, &n)

    xs := make([]float64, n)
    vs := make([]float64, n)

    for i := range xs {
        fmt.Fscan(in, &xs[i])
    }

    for i := range vs {
        fmt.Fscan(in, &vs[i])
    }

    l, r := 1e-9, 1e9
    for i := 0; i < 40; i++ {
        m := math.Sqrt(l * r)

        max_l := 0.0
        min_r := 1e9

        for j := 0; j < n; j++ {
            max_l = max(max_l, xs[j]-vs[j]*m)
            min_r = min(min_r, xs[j]+vs[j]*m)
        }

        if min_r >= max_l {
            r = m
        } else {
            l = m
        }
    }
    fmt.Fprintln(out, math.Sqrt(l * r))
    out.Flush()
}