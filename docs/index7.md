# Práctica #6 - Proyecto Final

---

**Nombre del proyecto**: Circulo Loading 

**Equipo:** Sebastián Montaño y Juan Jacobo Flórez

**Asignatura:** Producción Electrónica

**Fecha:** 1/12/2025

---

### Resumen

Este proyecto integró todos los conocimientos adquiridos en las prácticas anteriores para el diseño y fabricación de un dispositivo wearable funcional: una diadema electrónica con efecto de "rueda de carga" (loading spinner). El diseño combina electrónica digital y analógica para crear una secuencia visual de 8 LEDs  con efecto de atenuación suave (fading). El proyecto se desarrolló completamente en Altium Designer, aplicando los criterios de diseño establecidos en prácticas previas. Originalmente planificado para fabricación con la xTool F1, problemas de calibración requirieron el uso de la monoFab SRM-20 para el proceso completo de fabricación. El resultado fue un circuito compacto, y visualmente atractivo, demostrando la aplicación práctica de técnicas de diseño de PCB, selección de componentes SMD y fabricación con CNC.

---

### Concepto y Funcionamiento del Circuito

#### Descripción General

El circuito implementa una rueda de carga visual mediante una secuencia de 8 LEDs que se encienden y apagan de forma secuencial, creando un efecto de movimiento circular. La característica distintiva es el efecto de atenuación suave (fading) que evita transiciones bruscas entre LEDs.

**Especificaciones:**

- **Alimentación:** 4.5V (3 pilas AAA)
- **LEDs:** 8 LEDs en secuencia
- **Frecuencia:** ~3 Hz (cada LED encendido ~0.33 segundos)
- **Componentes:** SMD tamaño 1206 principalmente


#### Arquitectura del Circuito

El diseño se divide en tres bloques funcionales:

**1. Generación de Reloj (LMC555):**

El temporizador LMC555 genera la señal de reloj base del sistema.

- **Frecuencia:** ~3 Hz
- **Función:** Proporcionar pulsos regulares al contador

**2. Lógica Secuencial (CD4017/74HC4017):**

El contador de décadas distribuye los pulsos secuencialmente a través de sus 10 salidas (Q0-Q9).

- **Configuración especial:** Pin de Reset (Pin 15) conectado a Q8 (Pin 9)
- **Resultado:** El contador se reinicia después de 8 pasos, creando un bucle perfecto

**3. Circuito de Fading (por cada LED):**

Cada LED tiene su propio circuito de atenuación, repetido 8 veces:

- **Diodo :** Evita que la carga del capacitor regrese al contador
- **Capacitor de fading (470µF):** Almacena energía y se descarga gradualmente
- **Efecto logrado:** Atenuación suave de ~70ms que crea "cola de luz"
- **Resistor limitador:** Protección del LED

!!! note "Principio del Fading"
    Cuando el contador activa una salida, el capacitor se carga rápidamente a través del diodo. Al desactivarse, el capacitor se descarga lentamente a través del LED, creando el efecto de atenuación gradual que da sensación de movimiento fluido.

**IMAGEN SUGERIDA:** `diadema_esquematico.png` - Esquemático completo del circuito en Altium

---

### Diseño en Altium Designer

El proyecto aplicó las técnicas aprendidas en prácticas anteriores, especialmente de la Práctica #5 (Introducción a Altium).

#### Selección de Componentes

**Componentes principales:**

| Componente | Especificación | Package | Cantidad |
|------------|----------------|---------|----------|
| Temporizador | LMC555 | SOIC-8 | 1 |
| Contador | CD4017/74HC4017 | SOIC-16 | 1 |
| LEDs |  SMD | 1206 | 8 |
| Diodos | 1n4148 | SOD-123 | 8 |
| Capacitor fading | 470-1000µF | E-Case | 8 |
| Resistores | Varios valores | 1206 | 10 |
| Capacitores | Varios valores | 1206 | 3 |

**Consideraciones de diseño:**

- Todos los componentes pasivos en SMD 1206 para facilitar soldadura
- Capacitores de fading en package más grande (E-Case)
- Selección de componentes disponibles 

**IMAGEN SUGERIDA:** `diadema_componentes.png` - Vista de componentes en Altium con designadores


**Criterios aplicados:**

- **Forma:** Diseño circular adaptado a la forma de la rueda de carga
- **Separación de pistas:** 0.4 mm (estándar de prácticas anteriores)
- **Distribución de LEDs:** Espaciado uniforme en arco para efecto visual óptimo


**IMAGEN SUGERIDA:** `diadema_pcb_layout.png` - Layout completo en Altium


---

### Fabricación del PCB

#### Preparación de Archivos

Aplicando el proceso de la Práctica #5, se prepararon los archivos para fabricación:

1. **Creación de máscara de aislamiento:**
   - Convertir outline curvo a polígono
   - Crear Polygon Pour con No Net
   - Repour All para generar máscara completa

2. **Exportación:** Archivos generados en formato SVG

**IMAGEN SUGERIDA:** `diadema_archivos_fab.png` - Capas preparadas para fabricación

#### Fabricación con monoFab SRM-20

Aunque inicialmente se planeó utilizar la xTool F1 con láser de fibra IR (Práctica #5), problemas de calibración de la máquina requirieron cambiar a la monoFab SRM-20 para todo el proceso.

**Proceso completo en monoFab:**

1. **Grabado de pistas:**
   - Herramienta: Fresa 1/64
   - Configuración de offset: 2 pasadas para limpieza
   - Velocidad: 4 mm/s

2. **Perforación de orificios:**
   - Broca: 0.8 mm
   - Velocidad reducida: 0.8 mm/s
   - Precisión crítica para pads SMD

3. **Corte de contorno:**
   - Herramienta: Broca 2 mm"
   - Velocidad: 2 mm/s


**IMAGEN SUGERIDA:** `diadema_monofab_proceso.jpg` - PCB durante fabricación en monoFab

---

### Ensamblaje y Soldadura

El proceso de soldadura aplicó las técnicas de la Práctica #4, con especial atención a los componentes SMD pequeños.

**Secuencia de soldadura:**

1. **Componentes SMD pequeños primero:**
   - Resistores 1206
   - Diodos 

2. **Chips integrados:**
   - LMC555 
   - CD4017 
   - Técnica de anclaje

3. **LEDs:**
   - Atención a polaridad

4. **Capacitores electrolíticos:**
   - Componentes más grandes (E-Case)
   - Verificación de polaridad crítica
   - Soldadura cuidadosa por tamaño


**IMAGEN SUGERIDA:** `diadema_ensamblada.jpg` - PCB completamente ensamblada

---

### Pruebas y Resultados

#### Validación Funcional

**Pruebas realizadas:**

1. **Continuidad:** Verificación de todas las conexiones con multímetro
2. **Polaridad:** Confirmación de orientación correcta de componentes polarizados
4. **Funcionamiento:** Verificación de secuencia de LEDs

**Resultados:**

- Secuencia de LEDs funcionando correctamente
- Efecto de fading visible y suave
- Frecuencia de ~3 Hz lograda
- Consumo dentro de especificaciones

**IMAGEN SUGERIDA:** `diadema_funcionando.jpg` - Diadema en operación mostrando secuencia de LEDs


El resultado fue un dispositivo funcional que demuestra la aplicación práctica de conceptos teóricos en un producto real. El proyecto destacó la importancia de la flexibilidad en manufactura (cambio de xTool a monoFab) y la integración de conocimientos multidisciplinarios para lograr un resultado exitoso.