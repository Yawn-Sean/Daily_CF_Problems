# link: https://codeforces.com/contest/190/submission/306617709
package main

import (
    "bufio"
    . "fmt"
    "io"
    "math"
    "os"
)

const inf int = 0x3f3f3f3f
const mod int = 1e9 + 7

func slove(_r io.Reader, _w io.Writer) {
    in := bufio.NewReader(_r)
    out := bufio.NewWriter(_w)
    defer out.Flush()
    var x1, y1, r1, x2, y2, r2 int
    Fscan(in, &x1, &y1, &r1, &x2, &y2, &r2)
    x22 := abs(x1 - x2)
    x22 *= x22
    y22 := abs(y1 - y2)
    y22 *= y22
    r22 := math.Sqrt(float64(x22 + y22))
    dis := float64(r2 + r1)
    if r22 >= dis {
        r22 -= dis
        Fprintln(out, r22/2)
        return
    } else {
        mr := float64(max(r1, r2))
        mir := float64(min(r1, r2))
        if r22 >= mr || mr-r22 <= mir {
            Fprintln(out, 0)
        } else {
            Fprintln(out, (mr-r22-mir)/2)
        }
    }
}

func main() { slove(os.Stdin, os.Stdout) }
