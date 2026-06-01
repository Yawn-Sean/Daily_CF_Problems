考虑 $E(i)$ 表示当前走到第 $i$ 个下标 (即 $1\sim i-1$ 全部不停车), 然后期望的最终答案

那显然有:

$$
E(i)=\begin{cases}
p_i\cdot\min\left\{i+d_i,E(i+1)\right\}+(1-p_i)E(i+1) & i\ne n-1 \\ 
p_i\cdot\min\left\{i+d_i,E(0)+n\right\}+(1-p_i)\left(E(0)+n\right) & i=n-1\\ 
\end{cases}
$$

其中 $i=n-1$ 的部分表示走完了一圈

现在我们来分析他的性质: 令  $c_i=i+d_i$, $V_i=E(i+1)$ 或  $V_i=E(0)+n$, 那么就有:

$$
E(i)=p_i\cdot\min\left\{c_i,V_i\right\}+(1-p_i)V_i
$$

- $V_i\le c_i$, 此时有 $E(i)=V_i$, 也就是经过一次映射之后, $E(i)$ 变成了下一个位置的值
- $V_i>c_i$, 此时有 $E(i)=p_ic_i+(1-p_i)V_i=V_i-p_i\left(V_i-c_i\right)<V_i$, 也就是经过一次映射之后, $E(i)$ 小于下一个位置的值

所以综上所述, 总有 $E(i)\le V_i$, 也就是随着人不断走向下一个位置, 期望会越来越大:

$$
E(0)\le E(1)\le E(2)\le \cdots \le E(n-1)\le E(0)+n 
$$

但是我们又有 $E(0)=E(0)$, 所以可以据此来进行二分, 寻找不动点.

我们把上述的走一圈的**逆过程**看成一个函数 $F(x)$ (因为逆过程比正过程容易计算)

由于计算 $F(x)$ 的每一步过程中, 都会减小值, 那么当 $x\to\infty$ 时, 一定会有 $F(x)<x$

- 因为每一步至少减少 $\max\left\{0,p_i(V_i-c_i)\right\}$, 随着 $x\to\infty$, $V_i$ 会变得巨大

由于 $F$ 有单调性, 因此一定会有一个位置 $x_0$, 使得:

$$
\begin{cases}
F(x)>x & x<x_0 \\
F(x)=x & x=x_0 \\
F(x)<x & x>x_0 \\
\end{cases}
$$

到了这一步, 大家一定都知道怎么进行二分答案了 !!!
