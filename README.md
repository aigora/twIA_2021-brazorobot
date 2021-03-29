# Brazo Robotico controlado por guante

Nuestra idea de proyecto es crear un brazo robótico capaz de ser controlado por un guante, dicho guante será diseñado y programado por nosotros. Su mecanismo, consistirá en la lectura de nuestra mano, a partir de la cual el brazo se moverá de una forma u otra en función de la posición de nuestros dedos. Para ello, utilizaremos y programaremos en distintos programas informáticos como C++ y Arduino.

## Integrantes del equipo

1. David Pinto Llorente-davidpintollorente 

2. Javier Lerin Alonso-JavierLerinAlonso

3. Tobias Francisco kosanich-tobiaskos

4. Alvaro Lopez Villarroel-AlvaroLVillarroel

5. Euchan kang-dinner123

## Objetivos del trabajo

1. Diseño y desarrollo de un guante electrónico, capaz de dirigir las funciones de un brazo robótico.
2. Desarrollar y programar un programa funcional (en C) que permita utilizar dicho guante como un controlador del brazo.
3. Aplicar el uso de sensores y hardwares que faciliten al mecanismo y funcionamiento del guante, a través de programas como Arduino.   

## Objetivos

El brazo robótico controlado por un guante, se inspira en los brazos automatizados utilizados en las industrias. Nuestro objetivo con este proyecto es crear un brazo que sea capaz de responder a los movimientos de nuestra mano. Para ello, diseñaremos nosotros mismos un guante que se adapte a nuestra mano. Este guante estará construido por distintos hardwares, como cables, sensores... El software que vamos a utilizar es C++ y Arduino. El guante estará conectado al brazo robótico via bluetooth, lo que será más fácil para el usuario. El brazo se moverá de forma que al realizar un movimiento vertical, horizontal... con nuestros dedos, las articulaciones del brazo también se muevan respecto al movimiento realizado por el usuario. Para finalizar someteremos a nuestro brazo robótico a una prueba. Esta prueba consistirá en saber si nuestro brazo es capaz o no, de mover y coger objetos de forma eficiente.

## Movimiento del brazo
1. Pinzas:
La pinza es controlada con los botones localizados en el dedo medio y meñique. La pinza se cierra apretando el índice con el dedo medio. Para abrir la pinza apretamos el dedo medio con el meñique.
2. Muñeca:
La muñeca es controlada con una resistencia flexible en el dedo índice. Doblar este dedo hasta la mitad provocará que la muñeca del robot baje, doblarlo del todo hará que este  suba.
3. Codo:
El codo es controlado con un acelerómetro. Girar la palma hacia arriba o hacia abajo mueve el codo del robot en la dirección respectiva.
4. Hombro:
Controlado por un acelerómetro girar la palma hacia la derecha o hacia la izquierda mueve el hombro en la dicección respectiva. 
5. Base:
También controlado por un acelerómetro muy parecido al hombro o el codo. Girar la palma hacia la derecha o izquierda mientras la palma se mantiene en hacia arriba mueva la base del robot hacia la derecha o hacia la izquierda. 

Cada una de estas partes serán controladas con el uso de un guante que controlaremos manualmente con nuestra mano.
Dependiendo de la extremidad que movamos de la mano, se interactuará con las distintas partes de nuestro brazo robótico.

## Identificador de sensores y actuadores

ACTUADORES

El actuador del que vamos a hacer uso para que el brazo robot se mueva es el servomotor. El servo es un accionador muy común que permite el desplazamiento en un rango de movimiento de 180 grados. La ventaja del servo reside en esta característica pues se le indica directamente el ángulo deseado. Internamente el servo suele contar con un mecanismo reductor que proporciona un alto par y una gran precisión. Sin embargo; la velocidad de actuación o de giro son pequeñas. Los servos admiten una tensión de entre 4,8 y 7,2 voltios, aunque lo ideal son 6 voltios. Con ellos podremos controlar la posición.

SENSORES

Por otro lado, usaremos acelerómetros, dispositivos que miden la aceleración (la variación de la velocidad respecto del tiempo). Los acelerómetros cuentan con una masa suspendida en su interior mediante muelles. De esta forma, al aplicar un movimiento, la masa se mueve y provoca la elongación y la contracción de los muelles. El desplazamiento de la masa interna permite determinar la aceleración. Los acelerómetros son capaces de medir en los tres ejes (x, y, z).

Emplearemos botones o pulsadores, sensores de lo más simple pues solo tienen dos estados. Estos detectan si están siendo pulsados (se ejerce presión sobre ellos) o si no lo están, de manera que el programa pueda actuar en consecuencia. 

Por último, una resistencia flexible. Este sensor, aumenta su resistencia al ser flexionado. Cuando se dobla el sustrato del sensor produce una salida de resistencia en relación con el radio de curvatura. El sensor flex, con una flexión de 0° dará la resistencia de 10K y con una flexión de 90° dará entre 30 a 40 K ohmios.
