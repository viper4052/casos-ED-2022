# casos-ED-2022
README explicativo de cada caso.

### EXPLICACION CASO 2

Se realizó una solución basada en listas enlazadas. Los enums creados son los únicos que permiten identificar
cada dispositivo que puede registrarse en la aplicación.

- Structs:
Parametro: permite almacenar info basada en nombre (llave) y su valor (valor).
Accion: permite nombrar una accion por string y que pueda almacenar parámetros. Máximo 3.
AccionesPorTipo: tipo que es de las opciones del enum TipoDisp y con lista que almacene acciones y arrastre la información de los structs previos.

- Principales:
TDispositivo: define qué debe ser un dispositivo y qué debe contener. Se comporta como puntero para realizar un enlace de Dispositivos y crear una lista enlazada.
Tarea: mismo principio de TDispositivo, solo que orientado a la idea de Tareas.

- General: 
Al definir un dispositivo, se llama a un método que permite asignar los datos propios y sus acciones y parámetros, dependiendo del tipo de dispositivo.
Luego se agrega dispositivos en forma de lista utilizando el puntero definido a partir de su struct, diciendo que el siguiente dispositivo queda en NULL para que siempre se pueda ir añadiendo más sin correr el riesgo de pasarse de índice como con los arrays.
Para las tareas es parecido, se define tareas con nombre y la lista de los elementos a agregar con sus respectivas acciones y parámetros. Se agregan de igual forma una detrás de otra con los punteros NEXT.
Para personalizar cada dispositivo (y además para definir tareas) se creó el método de editaDispositivo con el que se puede redefinir a lo que apuntan los punteros dadas la Llave y el Valor. ambos como parámetro.
Esta última está construida con la idea que se pueda buscar en lista global y reasigne los parámetros de cualquier accion dada, por lo que como dije antes, sirve para las tareas.

El método main está comentado explicando qué es lo que sucede.
