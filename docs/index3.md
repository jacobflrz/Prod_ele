# Práctica #3 - Soldadura

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

!!! note "Control de Temperatura"
    Se ajustó el cautín a una temperatura de aproximadamente 340°C para la soldadura convencional. Esta temperatura es un punto óptimo para transferir calor eficientemente a los pads en una placa sin arriesgar dañar los componentes por sobrecalentamiento. Para la soldadura con pasta, se utilizó 420°C.

**Herramientas utilizadas:**
- **Pinzas:** Antiestáticas de punta fina y curveadas para manipulación precisa de componentes pequeños.
- **Estaño:** Soldadura de estaño estándar para todas las uniones.
- **Flux:** Pasta de flux para mejorar la capilaridad del estaño y asegurar uniones rápidas y limpias
- **Superficie de Trabajo:** Se trabajó sobre una superficie plana y resistente al calor para dar soporte completo a la placa, asegurando su estabilidad durante el proceso.

---

### Proceso de Soldadura: Componentes SMD

Para los componentes 1206, se implementó la técnica de anclaje.

!!! tip "Técnica de Anclaje"
    Este método es muy efectivo porque convierte un problema de alineación (sostener el componente, el cautín y la soldadura a la vez) en dos pasos sencillos. Anclar un lado primero inmoviliza la pieza, permitiendo soldar el segundo lado con total estabilidad.

Primero, se aplicó una mínima cantidad de estaño a un solo pad. Sosteniendo el componente con pinzas, se recalentó ese pad para fijar un extremo del componente. Con el componente ya inmovilizado, se soldó el terminal restante. 

<figure style="text-align:center;">
  <img src="recursos/imgs/smd_soldering.png" alt="Soldadura SMD" style="width:80%;">
  <figcaption style="font-size:0.9em; color:gray;">Primer plano de un componente SMD siendo soldado sobre la PCB.</figcaption>
</figure>

---

### Soldadura con Pasta para Soldar

Para los componentes SMD más pequeños, se utilizó el método de pasta para soldar, que ofrece mejor control y permite soldaduras más consistentes en espacios reducidos.

Se aplicó la pasta para soldar directamente sobre los pads de cobre. La cantidad aplicada fue mínima, para evitar puentes de soldadura entre pads adyacentes.

!!! tip "Espesor de la Pasta"
    La pasta debe formar una capa uniforme sobre el pad. Si es demasiada, podría causa cortocircuitos; si es muy poca, no hay suficiente material para crear una unión robusta.

Con la pasta aplicada, se colocó el componente sobre el pad utilizando pinzas. La pasta actuó como adhesivo temporal, manteniendo el componente en su lugar. Se aplicó calor con un cautín a una temperatura aproximada de 420°C, permitiendo que la pasta se funda y establezca la conexión. Se utilizó movimiento leve y uniforme del cautín para distribuir el calor de forma controlada.

!!! note "Punto de Fusión de la Pasta"
    La pasta para soldar tiene un punto de fusión entre 217°C y 260°C. Al utilizar un cautín a 420°C, la pasta se funde casi instantáneamente, típicamente en 2 a 3 segundos, lo que minimiza el riesgo de dañar componentes adyacentes.

Una vez que la soldadura se solidificó, se retiró el cautín y se permitió que enfriara naturalmente. Finalmente, se limpió cualquier residuo de flux con alcohol isopropílico.

!!! warning "Ventajas y Limitaciones"
    La pasta para soldar es excelente para componentes pequeños y espaciados muy cerca, pero requiere mayor precisión en la aplicación. El uso de un cautín a mayor temperatura (420°C) acelera significativamente el proceso de fusión en comparación con métodos alternativos, permitiendo mayor control y precisión en espacios muy reducidos. No es recomendable para soldaduras en cables.

---

### Proceso de Soldadura: Componentes Through-Hole (THT)

El principal objetivo con los pines de conexión fue asegurar su perpendicularidad respecto a la placa.

Se insertaron las tiras de pines y se soldó un único pin en cada extremo para fijar la orientación. Se procedió a soldar los pines restantes aplicando calor a la base del pin y al pad de cobre simultáneamente antes de introducir el estaño.

!!! note "La Unión Perfecta en Forma de Cono"
    Una soldadura THT correcta debe tener una forma cóncava, similar a un pequeño volcán. Esta forma indica que el estaño se ha unido correctamente tanto el pin como el pad (unión por capilaridad), garantizando una conexión eléctrica y mecánica robusta, una mala manipulacion o soldaura puede provocar por acción mecánica el quiebre de las pistas.

---

### Inspección y Resultados Finales

Tras la soldadura, se realizó una limpieza con alcohol isopropílico.

!!! tip "La Importancia de la Limpieza"
    Remover los residuos de flux no es solo por estética. pueden crear caminos conductivos no deseados en la placa, ademas de crear un terminado estetico indeseable.

#### Pruebas de Continuidad y Validación

La inspección visual confirmó que todas las uniones eran brillantes y no presentaban signos de soldadura fría. El circuito ensamblado fue sometido a pruebas de continuidad utilizando un multímetro.

**Resultados de resistencia:**
- **Líneas de señal:** 11 kΩ (valor esperado: 1 kΩ. La discrepancia aunque considerable se determinó que no iba a repercutir en el funcionamiento de la placa)

- **Positivo de LEDs:** 330 Ω (valor esperado: correcto)

**Problemas identificados y soluciones:**

Durante el proceso se identificaron soldaduras frías en algunas uniones realizadas con pasta que no solidificaron correctamente en el primer intento. Estas fueron re-soldadas aplicando pequeñas cantidades de pasta y recalentando con el cautín a 420°C.

Los pines THT inicialmente mal aplicados provocaron la desaparición de algunas pistas de cobre. Estas se repararon de forma rudimentaria conectando pequeños pedazos de cable entre los puntos dañados, restaurando la continuidad del circuito.

Los botones requirieron re-soldadura después del primer intento, logrando finalmente uniones confiables, aunque no se logró el resultado esperado.

#### Validación Final

A pesar de las desviaciones en la resistencia de las líneas de señal (11 kΩ en lugar de 1 kΩ esperado) y los problemas identificados durante el proceso, el circuito demostró continuidad eléctrica y funcionalidad. El resultado final validó que las técnicas de soldadura empleadas, aunque requirieron correcciones, fueron suficientes para obtener un circuito operacional.

<figure style="text-align:center;">
  <img src="recursos/imgs/pcb_final.png" alt="Placa Ensamblada" style="width:75%;">
  <figcaption style="font-size:0.9em; color:gray;">Vista de la placa estándar completamente ensamblada.</figcaption>
</figure>