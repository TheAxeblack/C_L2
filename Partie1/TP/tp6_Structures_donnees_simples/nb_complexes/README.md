# Nombres complexes

Écrire un programme permettant de réaliser des calculs simples sur des nombres complexes et d'en afficher le résultat. Vous devez définir une structure de données permettant de manipuler les nombres complexes et implémenter les opérations suivantes :

+ le calcul du conjugué d'un nombre complexe : le conjugué de $a + ib$ est $a - ib$ ;
+ l'addition, la sous-traction, la multiplication et la division de deux nombres complexes. Soit $z_1 = a + ib$ et $z_2 = c + id$, deux nombres complexes, alors :
  + $z_1 + z_2 = a + c + i(b + d)$ ;
  + $z_1 - z_2 = a - c + i(b - d)$ ;
  + $z_1 \times z_2 = (ac - bd) + i(ad + bc)$ ;
  + $\frac{z_1}{z_2} = \frac{(ac + bd) + i(bc - ad)}{c^2 + d^2}$.
