# Induction Proof

Assume $P(n)$ is equal to
$$ 
\sum_{i=1}^{n} i^3 = \frac{n^2(n+1)^2}{4}
$$
where $n \in \mathbb{Z}$

$P(n)$ can also be written as
$$
1+8+27\dots n^3 =  \frac{n^2(n+1)^2}{4}
$$

[Base Case]\
Let $n=1$, $P(1)$ is
$$
\begin{align*}
1 &=  \frac{(1)^2((1)+1)^2}{4}
\\ 1 &= 1
\end{align*}
$$

Thus, the base case is true.

[Define $P(k)$]\
Let $k$ satisfy $P(k)$
$$ 
1+8+27\dots k^3 =  \frac{k^2(k+1)^2}{4}
$$

[$k+1$ case]\
Let $n = k + 1$

[Prove the $RHS$ of $P(k+1)$]
$$
\begin{align*}
1+8+27\dots k^3 + {(k+1)}^3 &= \frac{k^2(k+1)^2}{4} + (k+1)^3
\\&=6k^3 + 13k^2
\end{align*}
$$
By substituting $P(k)$ into $1+8+27\dots k^3$, algebra shows $P(k+1)$ is $6k^3 + 13k^2$

[Prove the $LHS$ of $P(k+1)$]
$$
\begin{align*}
\frac{(k+1)^2(k+2)^2}{4} &= \frac{(k+1)^2(k+2)^2}{4}
\\&=6k^3 + 13k^3
\end{align*}
$$
By using algebra, we can conclude that $P(k+1)$ on the $RHS$ is equivalent to $P(k+1)$ on the $LHS$.

Thus,
$$ 
\sum_{i=1}^{n} i^3 = \frac{n^2(n+1)^2}{4}
$$
is true for all real numbers.

