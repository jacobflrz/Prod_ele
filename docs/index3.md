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

### Soldadura con Pasta para Soldar

Para los componentes SMD más pequeños, se utilizó el método de pasta para soldar, que ofrece mejor control y permite soldaduras más consistentes en espacios reducidos.

#### Aplicación de la Pasta

Se aplicó la pasta para soldar directamente sobre los pads de cobre utilizando una aguja de precisión o dispensador. La cantidad aplicada fue mínima, aproximadamente del tamaño de una lenteja, para evitar puentes de soldadura entre pads adyacentes.

!!! tip "Espesor de la Pasta"
    La pasta debe formar una capa uniforme sobre el pad. Si es demasiada, causa cortocircuitos; si es muy poca, no hay suficiente material para crear una unión robusta.

#### Posicionamiento del Componente

Con la pasta aplicada, se colocó el componente sobre el pad utilizando pinzas. La pasta actuó como adhesivo temporal, manteniendo el componente en su lugar.

#### Calentamiento Controlado

Se aplicó calor con el cautín directamente sobre el componente, permitiendo que la pasta se funda y establezca la conexión. Se utilizó movimiento circular leve del cautín para distribuir el calor uniformemente.

!!! note "Punto de Fusión de la Pasta"
    La pasta para soldar tiene un punto de fusión entre 217°C y 260°C. El cautín a 340°C funde la pasta rápidamente, típicamente en 3 a 5 segundos.

#### Limpieza Posterior

Una vez que la soldadura se solidificó, se retiró el cautín y se permitió que enfriara naturalmente. Finalmente, se limpió cualquier residuo de flux con alcohol isopropílico.

!!! warning "Ventajas y Limitaciones"
    La pasta para soldar es excelente para componentes pequeños y espaciados muy cerca, pero requiere mayor precisión en la aplicación. No es recomendable para soldaduras en cables o pines de inserción grandes.

---

### Herramientas y Preparación del Área

El éxito de la soldadura depende de la calidad de las herramientas y de un área de trabajo preparada adecuadamente.

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

### Soldadura con Pasta para Soldar

Para los componentes SMD más pequeños, se utilizó el método de pasta para soldar, que ofrece mejor control y permite soldaduras más consistentes en espacios reducidos.

#### Aplicación de la Pasta

Se aplicó la pasta para soldar directamente sobre los pads de cobre utilizando una aguja de precisión o dispensador. La cantidad aplicada fue mínima, aproximadamente del tamaño de una lenteja, para evitar puentes de soldadura entre pads adyacentes.

!!! tip "Espesor de la Pasta"
    La pasta debe formar una capa uniforme sobre el pad. Si es demasiada, causa cortocircuitos; si es muy poca, no hay suficiente material para crear una unión robusta.

#### Posicionamiento del Componente

Con la pasta aplicada, se colocó el componente sobre el pad utilizando pinzas. La pasta actuó como adhesivo temporal, manteniendo el componente en su lugar.

#### Calentamiento Controlado

Se aplicó calor con el cautín directamente sobre el componente, permitiendo que la pasta se funda y establezca la conexión. Se utilizó movimiento circular leve del cautín para distribuir el calor uniformemente.

!!! note "Punto de Fusión de la Pasta"
    La pasta para soldar tiene un punto de fusión entre 217°C y 260°C. El cautín a 340°C funde la pasta rápidamente, típicamente en 3 a 5 segundos.

#### Limpieza Posterior

Una vez que la soldadura se solidificó, se retiró el cautín y se permitió que enfriara naturalmente. Finalmente, se limpió cualquier residuo de flux con alcohol isopropílico.

!!! warning "Ventajas y Limitaciones"
    La pasta para soldar es excelente para componentes pequeños y espaciados muy cerca, pero requiere mayor precisión en la aplicación. No es recomendable para soldaduras en cables o pines de inserción grandes.

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
