# Proof

For the given statement, $P(n)$ is

$$
1+6+11+16+\dots 5n-4 = \frac{n(5n-3)}{2}
$$

&nbsp;
&nbsp;
&nbsp;

## [Show that $P(1)$ is true]

$$ 
\begin{align}
1 \dots + 5n-4 = 1

\\ \frac{1(5(1) - 3)}{2} = 1
\end{align}
$$

Thus, $P(1)$ is true.

&nbsp;
&nbsp;
&nbsp;

## [Show that $P(k)$ is true]

Let $k$ be any integer, $k \ge 1$. Suppose $P(k)$ is true. That is, suppose

$$
1+6+11+16+\dots 5k-4 = \frac{k(5k-3)}{2}
$$

&nbsp;
&nbsp;
&nbsp;

## [Show that $P(k+1)$ is true]

We must show that P(k+1) is true. That is,
$$
\begin{align}
1+6+11+16+\dots 5(k+1)-4 &= \frac{(k+1)(5(k+1)-3)}{2}
\\&= \frac{5k^2+7k+2}{2}
\end{align}
$$


The left hand side of $P(k+1)$ is
$$
1+6+11+16+\dots 5(k+1)-4 = 1+6+11+16+\dots 5k - 4 + 5(k+1)-4
$$

By substituting the inductive hypothesis, $P(k+1)$ is equivalent to
$$
\begin{align}
1+6+11+16+\dots 5(k+1)-4 &= 1+6+11+16+\dots \frac{k(5k-3)}{2} + 5(k+1)-4
\\ &= \frac{5k^2+7k+2}{2}
\end{align}
$$
