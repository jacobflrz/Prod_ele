# Práctica #3

---

**Nombre del proyecto**: Soldadura y Ensamblaje de Componentes

**Equipo:** Sebastián Montaño y Juan Jacobo Flórez

**Asignatura:** Producción Electrónica

**Fecha:** 12/10/2025

---

### Resumen

Esta práctica documenta el proceso de ensamblaje manual de una placa de circuito impreso estándar (PCB), aplicando las técnicas de soldadura para componentes de montaje superficial (SMD) y de inserción (Through-Hole). El objetivo fue desarrollar la destreza necesaria para realizar uniones de soldadura limpias, robustas y eléctricamente confiables. Se empleó una técnica de anclaje para los componentes SMD y el método estándar para los pines de conexión. El resultado final fue un circuito completamente funcional, validando las técnicas de soldadura empleadas y la importancia de un proceso metódico para el ensamblaje electrónico.

---

### Herramientas y Preparación del Área

El éxito de la soldadura depende de la calidad de las herramientas y de un área de trabajo preparada.

!!! note "Control de Temperatura"
    Se ajustó el cautín a una temperatura de aproximadamente 340°C. Esta temperatura es un punto óptimo para transferir calor eficientemente a los pads en una placa de FR-4 sin arriesgar dañar los componentes por sobrecalentamiento.

- **Superficie de Trabajo:** Se trabajó sobre una superficie plana y resistente al calor para dar soporte completo a la placa, asegurando su estabilidad durante el proceso.
- **Flux:** Su uso fue indispensable para mejorar la capilaridad del estaño y asegurar una unión rápida.

---

### Proceso de Soldadura: Componentes SMD

Para los componentes 1206, se implementó la técnica de anclaje.

!!! tip "Técnica de Anclaje"
    Este método es muy efectivo porque convierte un problema de alineación difícil (sostener el componente, el cautín y la soldadura a la vez) en dos pasos sencillos. Anclar un lado primero inmoviliza la pieza, permitiendo soldar el segundo lado con total estabilidad.

#### Anclaje de Precisión

Primero, se aplicó una mínima cantidad de estaño a un solo pad. Sosteniendo el componente con pinzas, se recalentó ese pad para fijar un extremo del componente.

#### Soldadura Final

Con el componente ya inmovilizado, se soldó el terminal restante. Finalmente, se retocó la unión inicial con flux para asegurar su calidad.

<figure style="text-align:center;">
  <img src="recursos/imgs/smd_soldering.png" alt="Soldadura SMD" style="width:80%;">
  <figcaption style="font-size:0.9em; color:gray;">Primer plano de un componente SMD siendo soldado sobre la PCB.</figcaption>
</figure>

---

### Proceso de Soldadura: Componentes Through-Hole (THT)

El principal objetivo con los pines de conexión fue asegurar su perpendicularidad respecto a la placa.

#### Fijación y Alineamiento

Se insertaron las tiras de pines y se soldó un único pin en cada extremo para fijar la orientación.

#### Unión por Capilaridad

Se procedió a soldar los pines restantes aplicando calor a la base del pin y al pad de cobre simultáneamente antes de introducir el estaño.

!!! note "La Unión Perfecta en Forma de Cono"
    Una soldadura THT correcta debe tener una forma cóncava, similar a un pequeño volcán. Esta forma indica que el estaño ha "mojado" correctamente tanto el pin como el pad (unión por capilaridad), garantizando una conexión eléctrica y mecánica robusta.

---

### Inspección y Resultados Finales

Tras la soldadura, se realizó una limpieza exhaustiva con alcohol isopropílico.

!!! tip "La Importancia de la Limpieza"
    Remover los residuos de flux no es solo por estética. Muchos tipos de flux son corrosivos y, con el tiempo, pueden degradar las uniones de soldadura o crear caminos conductivos no deseados en la placa.

La inspección visual confirmó que todas las uniones eran brillantes y no presentaban signos de soldadura fría. El circuito ensamblado fue sometido a pruebas de continuidad, las cuales superó exitosamente.

<figure style="text-align:center;">
  <img src="recursos/imgs/pcb_final.png" alt="Placa Ensamblada" style="width:75%;">
  <figcaption style="font-size:0.9em; color:gray;">Vista de la placa estándar completamente ensamblada.</figcaption>
</figure>

