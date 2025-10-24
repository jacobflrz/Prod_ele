
# Práctica #2 - Multisim

---

**Nombre del proyecto:** Simulación de LEDs Secuenciales

**Equipo:** Sebastián Montaño y Juan Jacobo Flórez

**Asignatura:** Producción Electrónica

**Fecha:** 19/10/2025

---

### Resumen

Esta práctica consistió en realizar un proyecto básico en **NI Multisim**, un software especializado para diseñar, simular y analizar circuitos analógicos, digitales y de potencia.
El objetivo fue **familiarizarnos con la interfaz y las herramientas principales del programa** para poder desarrollar proyectos más complejos en el futuro.

El circuito diseñado permitió **encender LEDs de manera secuencial**, validando su comportamiento lógico y eléctrico antes de proceder a la fabricación física de la PCB.

---

### Entorno de Simulación y Herramientas

!!! note "Entorno de Simulación: NI Multisim"
    Multisim combina el diseño esquemático con instrumentos virtuales que imitan el funcionamiento de herramientas de laboratorio como multímetros, generadores de señal y osciloscopios.

El entorno está compuesto por el **área de trabajo (Schematic)**, donde se diseña el circuito; el **menú de componentes** (`Place > Component...`) que da acceso a la *Master Database*; la **barra de instrumentos virtuales**, situada a la derecha, con herramientas de medición y análisis; y los **controles de simulación** ubicados en la parte superior (▶️ *Run*, ⏸ *Pause*, ⏹ *Stop*).

<div class="grid cards" markdown>
- ![Interfaz Multisim](recursos/imgs/multisim_entorno.jpg)
</div>

---

### Proceso de Diseño y Simulación

El diseño inició con la **búsqueda y colocación de componentes** desde la *Master Database* usando la barra **Filter**, donde se pueden encontrar elementos mediante palabras clave como `"RES"` (resistencias), `"LED_RED"` (LED rojo) o `"LM7805"` (regulador de voltaje).
Tras seleccionarlos, se colocaron en el área de trabajo con clic en **OK**, pudiendo rotarlos con **Ctrl+R** o clic derecho, y editar sus propiedades (nombre, valor, símbolo) con doble clic.

Posteriormente se realizó el **cableado** entre los componentes haciendo clic y arrastrando desde los terminales. Es importante mantener un trazado limpio y usar ángulos rectos para facilitar la lectura del circuito.

!!! warning "Importancia del 'GND'"
    Toda simulación requiere un punto de referencia de **0V (tierra)**.
En Multisim se inserta desde:
`Place > Component... > Group: Sources > Family: POWER_SOURCES > GROUND`.
Si se omite, la simulación fallará con el error “*Simulation failed to converge*”.

Con los componentes conectados, se procedió a **iniciar la simulación** usando el botón **Run (▶️)**. Durante este modo no se puede modificar el circuito, aunque puede pausarse (**⏸**) o detenerse (**⏹**) para realizar ajustes.

El análisis se complementó con el uso del **multímetro virtual**, que permite medir:

* **Voltaje**, conectando el instrumento en **paralelo** al componente.
* **Corriente**, conectándolo en **serie** con la carga.

Doble clic sobre el ícono del multímetro abre su panel frontal, donde se selecciona si la medición es en **voltaje (V)** o **corriente (A)**, y el tipo de señal (**DC** o **AC**).

<div class="grid cards" markdown>
- ![Multímetro Virtual](recursos/imgs/multisim_multimeter.jpg)
</div>

---

### Depuración y Corrección de Errores

Durante la práctica surgieron errores comunes en simulación, principalmente **lógicos o de conexión**, que se corrigieron aplicando distintas técnicas:

**1. Errores de Convergencia:**
Se produjeron por ausencia de GND o terminales flotantes. Se solucionó verificando las conexiones y añadiendo el punto de tierra necesario.

**2. Valores Incorrectos:**
En algunos casos los LEDs no encendían debido a resistencias demasiado altas. Se corrigieron ajustando sus valores, por ejemplo, reemplazando `1kΩ` por `330Ω`.

**3. Cableado Erróneo:**
Se detectaron conexiones incorrectas que impedían la lectura de corriente o voltaje. La corrección consistió en eliminar los cables con **Supr** y rehacer el trazado.

Estas correcciones permitieron depurar el diseño hasta obtener un comportamiento estable y coherente con la lógica esperada.

---

### Tipos de Simulación en Multisim

Además de la simulación **interactiva**, usada en esta práctica para probar el circuito en tiempo real, Multisim ofrece distintos modos de análisis que permiten estudiar el comportamiento eléctrico con mayor detalle:

* **Simulación Transitoria (Time Domain):** analiza cómo varían las señales con el tiempo. Es ideal para estudiar secuencias de encendido, retardos o temporizaciones.
* **Análisis DC (Punto Operativo):** muestra voltajes y corrientes estables, útil para verificar caídas de tensión o polarización de transistores.
* **Análisis AC (Frecuencia):** permite observar la respuesta del circuito ante señales sinusoidales, empleado en filtros o amplificadores.
* **Barrido Paramétrico (Parametric Sweep):** estudia cómo varía la salida al modificar un valor de entrada, como la resistencia o frecuencia.

<div class="grid cards" markdown>
- ![Simulación transitoria](recursos/imgs/multisim_sim1.jpg)
- ![Simulación AC](recursos/imgs/multisim_sim2.jpg)
</div>

---

### Validación y Resultados

Una vez corregidos los errores, la simulación final mostró el funcionamiento esperado: los **LEDs se encendían y apagaban de forma secuencial**, confirmando la correcta conexión y lógica del circuito.
Con esto, el proyecto quedó validado y listo para ser trasladado a la etapa de diseño de PCB.

!!! success "Conclusión Técnica"
    Multisim permitió **verificar y ajustar el comportamiento del circuito** antes de su implementación física, reduciendo riesgos y mejorando la comprensión de los principios de simulación electrónica.

---

### Conclusiones y Aprendizajes

Esta práctica fortaleció la comprensión del flujo de trabajo dentro de **Multisim**, integrando diseño, simulación, análisis y depuración de errores.

* La simulación previa a la fabricación permite detectar errores sin desperdiciar materiales.
* El uso correcto de librerías e instrumentos virtuales agiliza el diseño y la comprobación.
* Multisim es una herramienta efectiva para **transicionar del entorno virtual al físico**, garantizando que los prototipos electrónicos funcionen desde la primera versión.

---
git add .

git commit -m "Actualizar documentacion porfin"

git push