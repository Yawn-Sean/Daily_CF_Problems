```text
u v l c
设时间为 t, 则 cost = c*l/t
u v S:=c*l
```

问题变为，给定 $S_0,S_1,\cdots,S_m$ 和 $T$，最小化 $\sum \dfrac{S_i}{t_i}$，需要满足 $\sum t_i=T$

我们考虑两个数：
$$
\min\left(\dfrac{x}{t}+\dfrac{y}{T-t}\right) \\ 
\dfrac{-x}{t^2}+\dfrac{y}{(T-t)^2}=0 \\
\dfrac{T-t}{t}=\dfrac{T}{t}-1=\sqrt{\dfrac{y}{x}} \\
t=\dfrac{T}{1+\sqrt{\dfrac{y}{x}}} \\
\begin{eqnarray}
&&\dfrac{x}{t}+\dfrac{y}{T-t}\\
&=&\dfrac{x(1+\sqrt{\dfrac{y}{x}})}{T}+\dfrac{y}{T\left(1-\dfrac{1}{1+\sqrt{\dfrac{y}{x}}}\right)}\\
&=&\dfrac{x(1+\sqrt{\dfrac{y}{x}})}{T}+\dfrac{y}{T\dfrac{\sqrt{\dfrac{y}{x}}}{1+\sqrt{\dfrac{y}{x}}}}\\
&=&\dfrac{x(1+\sqrt{\dfrac{y}{x}})}{T}+\dfrac{y(1+\sqrt{\dfrac{y}{x}})}{T\sqrt{\dfrac{y}{x}}}\\
&=&\dfrac{x(1+\sqrt{\dfrac{y}{x}})+y(1+\sqrt{\dfrac{x}{y}})}{T}\\
&=&\dfrac{x+y+2\sqrt{xy}}{T}\\
\end{eqnarray}
$$

所以，每次遇到两个数 $x,\ y$，合并成 $x+y+2\sqrt{xy}$ 即可

更一般的，为了避免精度爆炸，求出 $SS=\sum \sqrt{S_i}$，求 $\dfrac{SS}{T}$ 即可
