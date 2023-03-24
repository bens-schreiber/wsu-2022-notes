# WA 7

## 5.2

### 11)

$1^3 + 2^3 + \dots + n^3 = (\frac{n(n+1)}{2})^2$,
for every nteger $n \ge 1$

We can prove this statement using mathematical induction.

[Define $P(n)$] \
Let $P(n)$ be equal to the above equation. That is,
$$
P(n) = 1^3 + 2^3 + \dots + n^3 = (\frac{n(n+1)}{2})^2
$$

[Base case] \
Let $n = 1$. Then, the $LHS$ of $P(1)$ is equal to

$$
1^3 = 1
$$

The $RHS$ of $P(1)$ is equal to
$$
(\frac{(1)((1)+1)}{2})^2 = 1
$$

Therefore, the base case of $P(1)$ is proven to be true.

[Inductive step] \
Allow $k$ to be an integer that satisfies $P(k)$. That is,
$$
P(k) = 1^3 + 2^3 + \dots + k^3 = (\frac{k(k+1)}{2})^2
$$

[Define $P(k+1)$ on $LHS$] \
Now, we must prove that $P(k+1)$ is true.
The $LHS$ of $P(k+1)$ is
$$
1^3 + 2^3 + \dots + k^3 + (k+1)^3
$$
By injecting the inductive hypothesis $P(k)$ into the above equation, we get
$$
(\frac{k(k+1)}{2})^2 + (k+1)^3
$$

[Define $P(k+1)$ on $RHS$] \
The $RHS$ of $P(k+1)$ is equal to
$$
(\frac{(k+1)(k+2)}{2})^2
$$

[Find equivalence]\
We must determine that the $LHS$ and $RHS$ are equivalent, meaning
$$
(\frac{k(k+1)}{2})^2 + (k+1)^3 = (\frac{(k+1)(k+2)}{2})^2
$$
By using algebra on the above equation, we find that
$$
6k^3 + 13k^2 = 6k^3+13k^2
$$

Thus, $1^3 + 2^3 + \dots + n^3 = (\frac{n(n+1)}{2})^2$

## 5.3

### 12)

For any integer $n\ge0$, $7^n - 2^n$ is divisible by 5

We will prove the statement using mathematical induction.

[Base case]\
Let $n=0$, then $7^n-2^n=7^0-2^0=1-1=0$, which is divisible by 5.

[Inductive step]\
Assume that the statement holds for some positive integer $k$, that is, $7^k-2^k$ is divisible by 5. We will show that this implies the statement also holds for $k+1$, that is, $7^{k+1}-2^{k+1}$ is divisible by 5.

We have:

$$
\begin{align*}
7^{k+1}-2^{k+1} &= 7\cdot 7^k - 2\cdot 2^k \
&= 7\cdot 7^k - 2\cdot 2^k + 35\cdot 2^k - 35\cdot 2^k \
&= 7\cdot 7^k - 10\cdot 2^k + 35\cdot 2^k - 35\cdot 2^k \
&= 7\cdot 7^k - 10\cdot 2^k + 5\cdot 7^k - 5\cdot 2^k \
&= (7\cdot 7^k - 2\cdot 2^k) + (5\cdot 7^k - 5\cdot 2^k) \
&= (7^k - 2^k) \cdot 7 + 5\cdot (7^k - 2^k).
\end{align*}
$$

By the inductive hypothesis, $7^k - 2^k$ is divisible by 5. Therefore, $5\cdot(7^k - 2^k)$ is also divisible by 5. Additionally, since 7 and 5 are prime, we know that $7^k - 2^k$ is not only divisible by 5, but is also prime to 7. Therefore, $7\cdot(7^k - 2^k)$ is also divisible by 5.

So we have shown that both terms on the right-hand side of the equation are divisible by 5, and hence, $7^{k+1}-2^{k+1}$ is divisible by 5.

### 20)

$2^n < (n+2)!$ for each integer $n \ge 2$

We can prove this using mathematical induction.

[Base case]\
Let $n=2$ 
$$
\begin{align*}
2^{(2)} &< ((2) + 2)!
\\4 &< 24
\end{align*}
$$
We can see that the base case holds true.

[Inductive Step]\
Assume the statement holds for a positive integer $k$, meaning $2^k < (k+2)!$. We need to show that this statement also holds for $k+1$, meaning $2^{k+1} < ((k+1)+2)!$

Starting from $2^{k+1}$, we can write:

$$2^{k+1} = 2 \cdot 2^k$$

By the inductive hypothesis, we know that $2^k < (k+2)!$. Therefore, multiplying both sides of the inequality by 2, we get:

$$2 \cdot 2^k < 2 \cdot (k+2)!$$

Simplifying the right-hand side, we get:

$$2 \cdot (k+2)! = 2 \cdot (k+2) \cdot (k+1)!$$

Expanding the factor of $k+2$, we get:

$$2 \cdot (k+2) \cdot (k+1)! = (k+3) \cdot (k+2)!$$

Substituting this back into our inequality, we get:

$$2^{k+1} = 2 \cdot 2^k < (k+3) \cdot (k+2)!$$

Therefore, we have shown that $2^{k+1} < (k+3)!$, which completes the inductive step.


## 5.4

### 8)
Suppose that $h_0, h_1, h_2, \dots$ is a sequence defined as
$h_0 = 1, h_1 = 2, h_2 = 3$ and $h_k = h_{k-1} + h_{k-2} + h_{k-3}$ for each integer $k \ge 3$

Prove that $h_n \ge 3^n$ for every integer $n \ge 0$

We can prove this using induction.

[Base case] \
When $n = 0$
$$
h_0=1\ge3^0
$$

which is true.

[Inductive Hypothesis]
Assume that $h_k\ge 3^k$ for some non-negative integer $k$.

[Inductive Step]
We need to show that 
$h_{k+1} \ge 3^{k+1}$.

$$
\begin{align*}
h_{k+1} &= h_k + h_{k-1} + h_{k-2}\\
&\ge 3^k + 3^{k-1} + 3^{k-2}\qquad\text{by the inductive hypothesis}\\
&= 3^{k-2}(3^2+3+1)\\
&= 3^{k-2}(13)\\
&\ge 3^{k-2}(9) \qquad \text{since } 13>9\\
&= 3^{k} \cdot 3\\
&= 3^{k+1}
\end{align*}
$$

Therefore, $h_{k+1} \ge 3^{k+1}$, which completes the inductive step.