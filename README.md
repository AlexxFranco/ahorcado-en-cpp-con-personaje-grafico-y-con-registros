# Ahorcado 

Juego de ahorcado en consola desarrollado en C++ que selecciona palabras aleatorias desde un archivo de texto externo.

---

## Descripción

El programa lee un listado de palabras desde el archivo `palabras.txt` y elige una al azar para que el jugador adivine letra por letra. Cuenta con representación gráfica del ahorcado en ASCII que se actualiza con cada intento fallido.

---

## Funcionamiento

- Lee las palabras desde `palabras.txt` (una palabra por línea)
- Selecciona una palabra aleatoria al iniciar cada partida
- Muestra la palabra oculta con guiones bajos `_` por cada letra
- El jugador tiene **6 intentos** antes de perder
- El ahorcado se dibuja progresivamente con cada error
- Al terminar la partida indica si ganaste o perdiste, revelando la palabra

---

## Explicación

https://www.youtube.com/watch?v=d2T6ma8Py24

---

## Tecnologías

- C++
- Librerías estándar: `iostream`, `fstream`, `vector`, `string`, `ctime`---
