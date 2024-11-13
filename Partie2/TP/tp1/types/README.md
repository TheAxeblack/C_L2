## Types

Écrire les instructions suivantes dans un programme, puis exécutez-le.

```c
int i = 2;
float x;
x = 5 / i;
printf("Valeur de x: %f\n", x);
```

Que se passe-t-il maintenant si on remplace la ligne `x = 5 / i;` par :
+ `x = 5.0 / i;`
+ `x = 5. / i;`
+ `x = 5 / (float) i;`
+ `x = (float)5 / i;`

Que se passe-t-il si on remplace le dernier `printf` par : `printf("Valeur de x: %d\n", x);`. Si nous sommes sûrs de nous, comment éviter un warning à la compilation ?