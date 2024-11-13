## 2 Fonction de Ackermann

La fonction de Ackermann est une fonction à deux arguments définie récursivement de la manière suivante :

$$
A(m, n) = \begin{cases} 
n + 1 & \text{si } m = 0 \\ 
A(m - 1, 1) & \text{si } m > 0 \text{ et } n = 0 \\ 
A(m - 1, A(m, n - 1)) & \text{si } m > 0 \text{ et } n > 0 
\end{cases}
$$

Programmez cette fonction récursive. Jusqu'à quelle valeur de $m$ et $n$ pouvez-vous aller ?
