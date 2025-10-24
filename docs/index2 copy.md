
# Práctica #2 - Multisim

---

**Nombre del proyecto:** Simulación de LEDs Secuenciales

**Equipo:** Sebastián Montaño y Juan Jacobo Flórez

**Asignatura:** Producción Electrónica

**Fecha:** 19/10/2025

---

### Resumen

Esta práctica consistió en realizar un proyecto básico en **NI Multisim**, un software especializado para diseñar, simular y analizar circuitos analógicos, digitales y de potencia.
El objetivo fue **familiarizarnos con la interfaz y las herramientas principales del programa**, para así poder desarrollar proyectos más complejos en el futuro.

El circuito diseñado permitió **encender LEDs de manera secuencial**, validando su comportamiento lógico y eléctrico **antes de proceder a la fabricación física de la PCB**.

!!! tip "Objetivo Técnico"
Comprender el flujo completo de trabajo en Multisim:
- Diseño esquemático.
- Conexión de componentes.
- Simulación y análisis del comportamiento.
- Corrección de errores lógicos.

---

### Entorno de Simulación y Herramientas

!!! note "Entorno de Simulación: NI Multisim"
Multisim combina el diseño esquemático con un potente motor **SPICE**.
Su ventaja principal es incluir instrumentos virtuales que **emulan herramientas reales de laboratorio**, como multímetros, generadores de señal y osciloscopios.

**Interfaz principal:**

* **Área de trabajo (Schematic):** el lienzo cuadriculado donde se construye el circuito.
* **Menú de Componentes:** `Place > Component...` abre la base de datos (*Master Database*) con todos los dispositivos eléctricos y electrónicos.
* **Barra de instrumentos virtuales:** ubicada al lado derecho, incluye herramientas como **Multímetro**, **Osciloscopio** y **Generador de Funciones**.
* **Controles de simulación:** botón verde ▶️ (*Run*) para iniciar la simulación, azul ⏸ (*Pause*) para pausarla y rojo ⏹ (*Stop*) para detenerla.

<div class="grid cards" markdown>
- ![Interfaz Multisim](recursos/imgs/multisim_entorno.jpg)
</div>

---

### Proceso de Diseño: Colocación y Cableado

!!! tip "Búsqueda por Palabras Clave"
La forma más rápida de encontrar componentes es usando la **barra de búsqueda (Filter)** dentro de la *Master Database*.
Ejemplos útiles:
- `"RES"` → resistencias
- `"LED_RED"` → LED rojo
- `"LM7805"` → regulador de voltaje

**1. Colocación y rotación de componentes**

* Selecciona el componente deseado → clic en **OK** → clic en el área de trabajo para colocarlo.
* Para rotarlo, haz **clic derecho → Rotate 90° clockwise**, o usa el atajo **Ctrl+R**.

**2. Edición de atributos**

* Doble clic sobre el componente para abrir su panel de propiedades.
* Se pueden modificar su **nombre (RefDes)**, **valor**, o **símbolo visual**.

<div class="grid cards" markdown>
- ![Colocación de componentes](recursos/imgs/multisim_place.jpg)
- ![Edición de atributos](recursos/imgs/multisim_edit.jpg)
</div>

**3. Cableado**

* Haz clic en un terminal para iniciar el cableado (aparecerá un carrete).
* Arrastra hasta el terminal de destino.
* Los cables pueden moverse libremente y ajustarse en ángulos rectos.

!!! warning "La Importancia del 'GND'"
Toda simulación **SPICE** necesita un punto de referencia de **0V (tierra)**.
En Multisim se inserta desde:
`Place > Component... > Group: Sources > Family: POWER_SOURCES > GROUND`.
Si se omite, la simulación **no iniciará** o mostrará el error “*Simulation failed to converge*”.

---

### Proceso de Simulación: Instrumentación Virtual

El objetivo de la simulación fue **verificar el encendido secuencial de los LEDs** y medir los valores eléctricos de corriente y voltaje.

!!! note "Control de Simulación"
- **Run (▶️):** inicia la simulación.
- **Pause (⏸):** detiene temporalmente.
- **Stop (⏹):** finaliza y permite editar el circuito.

**Uso del Multímetro Virtual:**

* **Voltaje (Voltímetro):** conectar en **paralelo** al componente.
* **Corriente (Amperímetro):** conectar en **serie** con la carga.
* Durante la simulación, doble clic sobre el multímetro abre su **panel frontal**, donde se elige entre `V`, `A`, `DC` o `AC`.

<div class="grid cards" markdown>
- ![Multímetro Virtual](recursos/imgs/multisim_multimeter.jpg)
</div>

!!! tip "Instrumentación Virtual"
Los instrumentos de Multisim imitan equipos reales.
Es posible observar las formas de onda, medir frecuencia o verificar caída de tensión sin necesidad de equipo físico.

---

### Técnicas de Depuración y Corrección

En la simulación, los errores son **lógicos**, no físicos.
Durante la práctica se aplicaron tres técnicas principales de corrección.

#### 1. Errores de Convergencia

**Síntoma:** “Simulation failed to converge”.
**Causa:** Falta de tierra (GND) o terminales flotantes.
**Corrección:** Revisar todas las conexiones y agregar el componente **GROUND** si no está presente.

#### 2. Valores Incorrectos de Componentes

**Síntoma:** El LED no enciende o el circuito no responde.
**Corrección:**

* Detener la simulación.
* Doble clic sobre el componente → ajustar el valor (por ejemplo, cambiar `1k` por `330 Ω`).
* Reiniciar la simulación.

#### 3. Recableado Incorrecto

**Síntoma:** Conexiones erróneas o mediciones imposibles.
**Corrección:**

* Detener simulación.
* Eliminar el cable incorrecto (**Supr**).
* Rehacer la conexión correctamente.

!!! tip "Depuración Eficiente"
Usa colores o etiquetas para identificar las señales principales (alimentación, tierra, señal de reloj).
Esto facilita el seguimiento visual del circuito y evita errores de conexión.

---

### Tipos de Simulación en Multisim

!!! info "Simulaciones Básicas Disponibles"
Multisim permite distintos tipos de simulación según el tipo de circuito o análisis requerido.
En esta práctica se trabajó con simulación **interactiva (tiempo real)**, pero el programa ofrece otras modalidades fundamentales:

1. **Simulación Transitoria (Time Domain)**

   * Permite observar cómo cambian las señales con el tiempo.
   * Ideal para estudiar **encendidos, secuencias de LEDs o respuestas de temporizadores**.

2. **Análisis de DC (Punto Operativo)**

   * Muestra los valores estables de voltaje y corriente cuando el circuito no varía en el tiempo.
   * Útil para verificar **polarización de transistores** o **caídas de tensión en resistencias**.

3. **Análisis AC (Frecuencia)**

   * Permite estudiar la respuesta de un circuito frente a señales sinusoidales.
   * Se usa para analizar **filtros, amplificadores o etapas de ganancia**.

4. **Análisis de Barrido Paramétrico (Parametric Sweep)**

   * Simula el comportamiento del circuito mientras **se varía un parámetro** (por ejemplo, una resistencia o frecuencia).
   * Ideal para estudiar **la sensibilidad del circuito** o comparar configuraciones.

<div class="grid cards" markdown>
- ![Ejemplo de simulación transitoria](recursos/imgs/multisim_sim1.jpg)
- ![Ejemplo de simulación AC](recursos/imgs/multisim_sim2.jpg)
</div>

---

### Inspección y Validación Final

Tras las pruebas de simulación y depuración, se confirmó el **funcionamiento lógico secuencial** del circuito, listo para ser exportado al entorno de diseño de PCB.

!!! success "Conclusión Técnica"
Multisim permitió **verificar y ajustar el comportamiento del circuito** antes de la implementación física, reduciendo riesgos y mejorando la comprensión del proceso de simulación electrónica.

---

### Conclusiones y Aprendizajes

Esta práctica consolidó la comprensión del flujo de trabajo en **Multisim**, desde la colocación de componentes hasta la validación final de la simulación.

* La **simulación previa a la fabricación** permite detectar errores lógicos o de cálculo sin desperdiciar materiales.
* El correcto uso de las **librerías de componentes** y la instrumentación virtual es clave para un diseño ágil.
* Los errores de simulación suelen ser humanos (pines flotantes, falta de GND). La atención al detalle es esencial.
* Multisim facilita la **transición del entorno virtual al físico**, haciendo más segura la producción electrónica.

---

