una aplicación en C++ llamada "main.cpp" que cargue (lea) un grafo en forma de matriz de adyacencias, lo guarde como matriz de adyacencias y como lista de adyacencias. Las etiquetas de los nodos son: A B C D E F G H I J K L M N O P Q R S T U V W X Y Z AA AB AC AD ...
El programa debe desplegar la matriz de adyacencias, y luego la lista de adyacencias
Después el programa debe mostrar el recorrido en BFS y en DFS a partir del primer nodo del grafo.
Se deben implementar las siguientes dos funciones :

Entrada:
Un numero entero N que indica el numero de nodos que contiene el grafo, seguido de N lineas con N valores booleanos cada línea.

Salida:
La matriz de adyacencias
La lista de adyacencias
BFS iniciando en el primer nodo (secuencia de valores, el primer nodo es el A, luego el B, y así, separados por un espacio en blanco, al final va un espacio)
DFS iniciando en el primer nodo (secuencia de valores, el primer nodo es el A, luego el B, y así,, separados por un espacio en blanco, al final va un espacio)

Ejemplo de entrada:

10
0 1 0 0 1 0 0 1 0 0
1 0 1 0 1 0 0 0 0 0
0 1 0 1 1 1 0 0 0 0
0 0 1 0 0 0 0 0 0 0
1 1 1 0 0 0 1 1 0 0
0 0 1 0 0 0 0 0 0 1
0 0 0 0 1 0 0 0 0 1
1 0 0 0 1 0 0 0 1 1
0 0 0 0 0 0 0 1 0 0
0 0 0 0 0 1 1 1 0 0

Ejemplo de salida:

0 1 0 0 1 0 0 1 0 0
1 0 1 0 1 0 0 0 0 0
0 1 0 1 1 1 0 0 0 0
0 0 1 0 0 0 0 0 0 0
1 1 1 0 0 0 1 1 0 0
0 0 1 0 0 0 0 0 0 1
0 0 0 0 1 0 0 0 0 1
1 0 0 0 1 0 0 0 1 1
0 0 0 0 0 0 0 1 0 0
0 0 0 0 0 1 1 1 0 0

A - B - E - H
B - A - C - E
C - B - D - E - F
D - C
E - A - B - C - G - H
F - C - J
G - E - J
H - A - E - I - J
I - H
J - F - G - H

A B E H C G I J D F

A B C D E G J F H I

(Entre cada parte de la salida hay una línea en blanco)
