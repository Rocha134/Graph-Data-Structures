hacer una aplicación que:

    Abra el archivo de entrada llamado "bitacora2.txt" y que almacene los datos en en un grafo dirigido que tiene un nodo raíz, a partir del cual se puede llegar a cada red encontrada en el archivo de bitácoras. A partir de cada nodo de red se puede llegar a cada nodo host encontrado en el archivo de bitácoras. A pártir de cada nodo host se puede llegar a los nodos correspondientes (puerto, mensaje de error, fechay hora) en el registro en el archivo.
    Recordemos que una dirección IP se compone de 4 números separados por puntos.
    Los primeros dos números representan la red, y los últimos dos representan el host dentro de esa red.
    Determina el grado de salida de cada nodo
    Escribe cuál (o cuales en caso de empate) es la red con mayor hosts registrados en el archivo de bitácoras.
    Escribe cuál o cuáles son los hosts (IPs completas sin tomar en cuenta el puerto) con mayor incidencia (más entradas en el archivo de bitácora)

    ejemplo de salida:

    23.45
    54.196

    123.45.92.178
    54.96.214.86
    87.65.23.12



    primero vienen las redes con más grados de salida
    luego una línea en blanco
    luego las IPs completas con más entradas en el archivo
