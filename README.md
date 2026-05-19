## 🧪 Prueba Individual 1: Comunicación UART (Validación TRL 3)

### Descripción de la Prueba
En concordancia con los requerimientos del nivel **TRL 3 (Prueba experimental de concepto)**, se realizó la validación técnica e individual del módulo de comunicación serial. El objetivo de esta prueba es demostrar la factibilidad de la recepción de datos en el microcontrolador **PIC16F877A** emulando la llegada de comandos desde el módulo **ESP32** (actuando como puente Bluetooth).

Para esta simulación, se configuraron los registros internos del PIC (`TXSTA`, `RCSTA`, `SPBRG`) para operar a una tasa de **9600 baudios** utilizando un oscilador externo de **20 MHz**. Se utiliza una terminal virtual para inyectar caracteres específicos ('a' y 'b') que simulan las directivas enviadas desde la aplicación móvil.

<img width="748" height="509" alt="image" src="https://github.com/user-attachments/assets/c3077827-8d0b-47bb-98c6-1cbfdd735acf" />
---

### 💻 Resultados de la Simulación

A continuación se presentan las capturas del entorno de simulación donde se verifica el correcto comportamiento del firmware programado ante los estímulos de entrada:

#### 1. Recepción del Comando 'a'
Al ingresar el carácter `'a'` a través de la interfaz UART, el microcontrolador procesa con éxito la interrupción por recepción (o lectura del registro `RCREG`), ejecutando la acción lógica correspondiente en los pines de control.

![Simulación tras recibir la letra 'a'](https://github.com/user-attachments/assets/2442a021-c1d9-4578-a3dd-24d3b743fa95)

#### 2. Recepción del Comando 'b'
Al ingresar el carácter `'b'`, se valida que el flujo del programa discrimina correctamente el cambio de instrucción en la trama de datos serial, conmutando el estado lógico del sistema.

![Simulación tras recibir la letra 'b'](https://github.com/user-attachments/assets/8f184a95-3856-45c5-9d96-5433a9a37408)

---

### 📌 Conclusiones de la Etapa
* **Factibilidad Técnica Demostrada:** El PIC16F877A procesa los datos seriales sin pérdida de sincronía ni desborde de registros (identificación correcta de caracteres ASCII).
* **Siguiente Paso (Hacia TRL 4):** Integrar este bloque de software con la secuencia de control de los 4 puentes H, el servomotor y las rutinas de las motobombas de absorción y expulsión dentro del mismo firmware.

