## OBSERVACIONES:

Vectores
------------------------------------------------

1. MEDIOIDS : Contiene los indices de los centroides (vector de enteros)
2. POINTS : Contiene los puntos y el indice de su centroide mas cercano (vector de pares)
3. DISTANCES : Matriz que contiene las distancias en tre todos los puntos (vector de vectores de doubles)
4. SIGMA : Contiene la suma de las distancias de cada punto dentro de su grupo y su indice (vector de pres)


* Complejidad de las distancias n² - (n²+n)/2
* El priera incercion esta asignando al vector de puntos el tag 0 :)