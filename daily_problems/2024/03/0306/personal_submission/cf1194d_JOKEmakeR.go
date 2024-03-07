package main

import (
    "bufio"
    . "fmt"
    "os"
)

func main() {
    in := bufio.NewReader(os.Stdin)
    out := bufio.NewWriter(os.Stdout)
    var t int
    Fscan(in, &t)
    for t > 0 {
        t--
        var n, k int
        Fscan(in, &n, &k)
        if k % 3 != 0 {
            if n % 3 == 0 {
                Fprintln(out, "Bob")
            } else {
                Fprintln(out, "Alice")
            }
        } else {
            m := n % (k + 1)
            if m == k || m % 3 != 0 {
                Fprintln(out, "Alice")
            } else {
                Fprintln(out, "Bob")
            }
        }
    }
    out.Flush()
} 