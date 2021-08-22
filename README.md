# cqueue
cqueue est une bibliiothèque de fonction qui permet de créer et gérer une queue circulaire en C

# Compilation
```sh
make
```

# Usage
```c
gcc example.c cqueue.a -o example
```

# Documentation
Une queue circulaire ou ring buffer, fonctionne de la même facon qu'une liste chainée/queue FiFo (First in First out)
La seul différence réside dans le fait que la queue circulaire est d'une taille limité défini par l'utilisateur. 
![circular queue](https://www.researchgate.net/profile/Turhan-Karadeniz-2/publication/44785694/figure/fig9/AS:669463758266368@1536624006002/Circular-Queue-Based-Buffer-Implementation-3.ppm)
### Crééer une queue d'une taille donnée
**Arguments**
> size: `size_t`

**Retour**
> `cqueue_t *`
```c
cqueue_t *cqueue = cqueue_create(10);

```

### Supprimer la queue
**Arguments**
> queue: `cqueue_t *`
```c
cqueue_destroy(cqueue);
```

### Ajouter une valeur dans la queue
**! Ajout de l'adresse et non d'une copie de la valeur !**
Si la valeur de l'objet change, la valeur de l'objet dans la queue sera aussi changé 
**Arguments**
> queue: `cqueue_t *`

> data: `void *`

**Retour**
> `CQUEUE_OK` ou `CQUEUE_NULLPTR` ou `CQUEUE_FULL` ou `CQUEUE_EMPTY` 
```c
int var = 42;
int ret = cqueue_push(cqueue, &var);
```

### Récupérer la première valeur et la retirer de la queue
Change l'adrese de data par l'adresse de la valeur contenue dans la queue, et retire celle cette dernière.
**Arguments**
> cqueue: `cqueue_t *`

> data: `void **`

**Retour**
> `CQUEUE_OK` ou `CQUEUE_NULLPTR` ou `CQUEUE_FULL` ou `CQUEUE_EMPTY` 
``c
int *ptr_var = NULL;
int ret = cqueue_pop(cqueue, &var);
```

### Récupérer la première valeur sans la retirer de la queue
Change l'adrese de data par l'adresse de la valeur contenue dans la queue.
**Arguments**
> cqueue: `cqueue_t *`

> data: `void **`

**Retour**
> `CQUEUE_OK` ou `CQUEUE_NULLPTR` ou `CQUEUE_FULL` ou `CQUEUE_EMPTY` 
``c
int *ptr_var = NULL;
int ret = cqueue_get(cqueue, &var);
```

### Récupérer la taille utilisé de la queue
**Arguments**
> cqueue: `cqueue_t *`

**Retour**
> La taille utilisé de la queue `size_t`
```c
size_t size = CQUEUE_GET_SIZE(cqueue);
```

### Savoir si la queue est remplie
**Arguments**
> cqueue: `cqueue_t *`

**Retour**
> Retourne `1` si la queue est remplie ou ou `0` si elle est vide.
```c
if (CQUEUE_IS_FULL(cqueue)) {
    puts("La queue est pleine !\n");
}
```

### Savoir si la queue est vide
**Arguments**
> cqueue: `cqueue_t *`

**Retour**
> Retourne `1` si la queue est vide ou ou `0` si elle est pleine.
```c
if (CQUEUE_IS_EMPTY(cqueue)) {
    puts("La queue est vide.\n");
}
```
