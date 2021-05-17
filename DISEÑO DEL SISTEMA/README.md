# DISEÑO DEL SISTEMA
## 1.GUANTE
  El brazo robot KSR10 tiene 6 elementos que pueden ser controlados: 
 
 1.	 Una **base**.
 2.	 Un **codo**, que une el brazo robot a la base.
 3.	 Un **hombro**, que es la parte del brazo conectada a la muñeca.
 4.	 Una **muñeca**.
 5.	 Unas **pinzas**.
 6.	 Un **led blanco** , que está en medio de las pinzas.
  
  El guante está diseñado para controlar el led y los motores del brazo robot (en total 5 motores). 
  Cada una de estas partes tienen unos sensores específicos los cuales son:

  *	 Una resistencia flexible localizada en el dedo corazón. Esta se encarga de controlar la muñeca. Si doblamos hasta la mitad, 
         la muñeca del robot bajará. Cuando se dobla por completo el dedo la muñeca sube.
  *	 Otra resistencia flexible localizada en el dedo índice. 
         Si se dobla el dedo hasta la mitad las pinzas de brazo robot se van cerrando pero si se dobla del todo hará que las pinzas se abran.
  *	 Un módulo Acelerómetro+Giroscopio que controla 3 partes:
     1. **La Base**: Girando el dorso de la mano hacia la derecha o izquierda mientras la palma se mantiene hacia arriba hace que se mueva la base del robot hacia la derecha o hacia la izquierda.
     2. **El Codo**: Si giramos el dorso de la mano hacia arriba o hacia abajo mueve el codo del robot en la dirección respectiva.
     3. **El Hombro**: Al girar el dorso de la mano hacia la derecha o hacia la izquierda mueve el hombro en esas direcciones.
     
  *	 Un botón que hará que el led blanco de las pinzas se encienda o se apague.
  
  Al guante estarían unidos los sensores (el botón, el módulo y las resistencias flexibles) y sus correspondientes cables a una parte llamada como “Caja de conexión”
  Esta caja de conexión serviría como nexo entre el guante y la muñequera mediante un cable. Estaría compuesta por:
  * Unos leds de colores que uno indicaría si este encendido y otro se encendería si se está transmitiendo los datos a la caja de control.
  * Una pequeña placa baquelita.
  * 3 resistencias y un conector.

## 2.MUÑEQUERA
  En la muñequera se encuentra la caja de transmisión encargada enviar y de transcribir las órdenes del guante
  ,ejecutadas mediante movimientos, a la caja de control y al brazo robot.
  Esta caja de transmisión esta compuesta principalmente por:
  
  *	 Un Elegoo Nano, que cumple la función de un Arduino Nano. 
  *	 Un módulo inalámbrico nRF24 que une la caja de control del brazo robot con la muñequera y el guante.
  *	 Un cable plano de 10 que conecta la caja de transmisión con el guante.
  *	 Una serie de resistencias.
  *	 Un condensador de 47 uF y 50v.
  *	 Una caja para una de pila de 9v con interruptor.
  *	 Una  pila de 9v. 
 
  Todo este hardware se encuentra conectado a una protoboard. 
  Cabe destacar que el módulo inalámbrico nRF24 está por encima del Nano.
  La electrónica está sobre la caja de la pila y todo está unido a una muñequera.     
                                                                                                                                                            
 
## 3.CAJA DE CONTROL

  La caja de control es uno de los dispositivos más complejos del sistema, pues se encarga de recibir la información de los gestos del guante a través de un módulo nRF24L01.
  Su interior consta principalmente de una placa MEGA, donde se conectarán todas las conexiones pin del robor KSR10. La placa se encontrará conectada a una bateria que 
  suministrará una tensión de 9V. Para hacer posible el movimiento de los motores (5 motores), utilizaremos unos chips controladores (L293D). Dado que cada controlador acepta 
  dos motores, con 3 será suficiente. Para simplificar el diseño del sistema utilizaremos un conector flexible de 14 pins que contenga las distintas conexiones pin de KSR10.
  
|| CONTROLADOR L293D ||

  El controlador L293D es un circuito integrado constituido por 4 partes de puente-H. Esto permite controlar 4 motores-dc de forma unidireccional o 2 motores-dc en ambas
  direcciones, como es nuestro caso. El controlador consta de un total de 16 pines, 8 por cada columna, numerados de arriba a abajo. Dado que cada L293D puede controlar
  dos motores, estos se conectarán en el pin 3 y 6 (Motor 1) y el pin 11 y 14 (Motor 2). Uno de los pricipales puntos a favor de este controlador es que permite una alimentación
  independiente para los motores, se pueden controlar desde los 4.5 Vdc hasta 36 Vdc.
  
|| CONEXION ENTRE LOS MODULOS DE CONEXION INALAMBRICA(nRF24L01) - Conexión por radiofrecuencia ||

  El módulo nRF24L01 es un dispositivo que funciona a 3.3V, su principal función es enviar señales (desde la placa NANO) de 2 bytes de datos, 10 veces por segundo, señales que
  serán recibidas por un segundo dispositivo de conexión. Dicho dispositivo se encargará de analizar los datos de la señal y procesar la información a la placa (Placa MEGA).
  Para hacer posible el movimiento de los motores necesitaremos un total de 10 bits (2 por cada motor de KSR10). Para hacer posible este movimiento utilizaremos como códigos
  de dirección: 
  
  01 (Para que el motor gire a la derecha) y 10 (Para que el motor gire a la izquierda)
  
  Tambien asociaremos cada motor a una dirección como: 
  
  M1 (motor de "la base") M2 (motor del "hombro")... 


## 4.APLICACION PC
 La aplicación que se ejecuta en el PC tiene dos funciones: 
 1. Ser el nexo de union entre la muñequera (que recibe las ordenes del guante) y la caja de control (que se encarga de que el brazo ejecute las ordenes) permitiendo  asi  la comunicación . 
 2. Monitorizar las acciones que se están llevando a cabo y que el usuario pueda ver en pantalla los movimientos del brazo robótico. 
 
 Al inicializar el sistema, la aplicación pedirá al usuario que se coloque el guante y que compruebe que el resto de sistemas están encendidos y preparados para su uso. 
 Tras hacerlo , el usuario deberá pulsar la tecla espaciadora para que la muñequera comience a enviar los datos recogidos por los sensores del guante (resistencias flexibles, 
 módulo acelerómetro-giroscopio y botón) al PC mediante el módulo de conexión inalambrica nRF24L01. 
 Esta acción no será posible hasta que todos los sistemas estén operativos, por lo que el ordenador continuará pidiendo al usuario que compruebe que los sistemas están listos y que presione la tecla espaciadora. Al mismo tiempo, mostrará un mensaje advirtiendo al usuario de que alguno de los sistemas no está listo.
 
 En el momento que el ordenador comience a recibir las ordenes del guante, este las analizará y enviará por medio del otro módulo nRF24L01 situado en la caja de
 control, los movimientos que debe ejecutar el brazo robótico. 
 A su vez, el usuario situado frente a la pantalla y con el guante podrá observar como van apareciendo las acciones llevadas a cabo por el brazo (cerrar o abrir la pinza, subir o bajar la muñeca, ...). 
 Ya que en ocasiones,  el usuario no estara en cerca del brazo y no podra controlar visualmente los movimientos, por lo que dicha funcionalidad le permitirá hacerlo sin problemas. 
 
 De esta forma, por ejemplo, si el usuario dobla completamente su dedo índice, flexionará una **resistencia flexible**, **la caja de conexión del guante** lo detectará y enviara la informacion a **la muñequera** por medio de cableado. 
 La **muñequera** con el módulo nRF24L01 transmitirá estos datos al ordenador . El ordenador interpreta los datos mediante y manda una orden a la **caja de control** por medio del otro módulo nRF24L01. 
 La **caja de control** comanda la orden al brazo mediante cableado y se abrirá por completo la pinza.  Mientras tanto en la pantalla se mostrará: "Se ha abierto la pinza".
