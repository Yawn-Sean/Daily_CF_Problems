# https://codeforces.com/contest/374/submission/307898663

package main

import (
    "bufio"
    "container/heap"
    . "fmt"
    "io"
    "math"
    "os"
)

const inf = math.MaxInt / 2

func slove(_r io.Reader, _w io.Writer) {
    in := bufio.NewReader(_r)
    out := bufio.NewWriter(_w)
    defer out.Flush()
    var n, m, i, j, a, b int
    Fscan(in, &n, &m, &i, &j, &a, &b)
    type pair struct{ i, j int }
    target := func(p pair) bool {
        return (p.i == 1 && p.j == 1) || (p.i == 1 && p.j == m) || (p.i == n && p.j == 1) || (p.i == n && p.j == m)
    }
    if target(pair{i, j}) {
        Fprintln(out, 0)
        return
    }
    if n <= a || m <= b {
        Fprintln(out, "Poor Inna and pony!")
        return
    }
    ans := inf
    calc := func(x, y int) {
        tmpx := abs(x - i)
        tmpy := abs(y - j)
        if tmpx%a != 0 || tmpy%b != 0 {
            return
        }
        tmpx /= a
        tmpy /= b
        if tmpx&1 != tmpy&1 {
            return
        }
        ans = min(ans, max(tmpx, tmpy))
    }
    calc(1, 1)
    calc(1, m)
    calc(n, 1)
    calc(n, m)
    if ans == inf {
        Fprintln(out, "Poor Inna and pony!")
        return
    }
    Fprint(out, ans)
}

func main() { slove(os.Stdin, os.Stdout) }

func abs(x int) int {
    if x < 0 {
        return -x
    }
    return x
}
