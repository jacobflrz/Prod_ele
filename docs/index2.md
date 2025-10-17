# Práctica #2 - PCB's en Vinil

---

**Nombre del proyecto**: Fabricación de PCB Flexible con Cortadora de Vinil

**Equipo:** Sebastián Montaño y Juan Jacobo Flórez

**Asignatura:** Producción Electrónica

**Fecha:** 28/09/2025

---

### Resumen

La práctica consistió en un estudio sobre la viabilidad de adaptar tecnologías de fabricación digital, específicamente una cortadora de vinil Brother, para el prototipado rápido de circuitos impresos flexibles. El objetivo fue desarrollar y documentar un flujo de trabajo completo desde la preparación de archivos en KiCad hasta la ejecución del corte sobre cinta de cobre. 

Los resultados, aunque funcionales, demuestran que el proceso se encuentra en una fase temprana de caracterización. Se identificaron desafíos significativos relacionados con la naturaleza del material, el cual, al ser una cinta delgada no rígida, tiende a arrugarse y atorarse en la navaja. Además, limitaciones en los parámetros de calibración de la máquina y problemas mecánicos durante el proceso requieren optimización considerable para lograr resultados confiables.

---

### Preparación de Archivos en KiCad

A diferencia de un proceso de fresado, la cortadora de vinil sigue líneas vectoriales. Por ello, fue necesario invertir la lógica del diseño para que la máquina cortara el material de aislamiento entre las pistas.

!!! danger "Paso Crítico: Exportación en Negativo"
    La cortadora está diseñada para seguir líneas. Si se exporta el diseño normal, cortaría las pistas como líneas, haciendo inviable el circuito. Al exportar en negativo, las líneas que la máquina sigue son las del aislamiento entre pistas, que es precisamente el cobre que queremos remover.

El procedimiento inició en KiCad con el uso de la herramienta creador de polígonos. Se dibujó un polígono que abarcaba la totalidad de la capa de cobre del diseño.

En el menú de `Salidas de fabricación`, se activó la opción de trazado en negativo. El archivo se exportó en formato SVG para asegurar su compatibilidad.

<figure style="text-align:center;">
  <img src="recursos/imgs/kicad_negativo.png" alt="Exportación en Negativo" style="width:80%;">
  <figcaption style="font-size:0.9em; color:gray;">Previsualización de la exportación en negativo en KiCad.</figcaption>
</figure>

---

### Preparación del Tapete y Material

La correcta fijación de la cinta de cobre fue un aspecto crítico e influyente en los parámetros de corte elegidos. Al ser una lámina metálica muy delgada y sin rigidez (similar a un tape), su comportamiento es muy diferente al del vinil convencional.

**Posicionamiento correcto del tapete:** La máquina Brother Scan N Cut SDX225 requiere que el tapete adhesivo se coloque de manera específica, con la flecha del tapete señalando hacia adentro de la máquina.

**Adhesivo de Refuerzo:** Se aplicó una delgada capa de pegamento extra sobre la cama adhesiva para contrarrestar la tendencia del material a moverse o arrugarse. Sobre esta se colocó una cama de sacrificio de vinil como protección, y finalmente la cinta de cobre sobre esta capa.

!!! warning "Área de Carga"
    Es importante asegurar que no haya material sobre los bordes negros del tapete, ya que esto puede interferir con el mecanismo de carga de la máquina.

**Carga del Material:** Con la cinta de cobre ya fijada, se posicionó el tapete alineando la flecha hacia adentro y se presionó el botón ubicado justo debajo del botón de `home` para cargar el tapete adhesivo en la máquina.

!!! tip "Mantenimiento del Tapete"
    Es indispensable limpiar el tapete con alcohol antes y después de cada uso. La acumulación de adhesivo y residuos de cobre puede afectar la planitud de la superficie y la calidad de futuros cortes. Para descargar el tapete, se presiona nuevamente el botón debajo de home.

---

### Proceso de Corte y Caracterización

Esta fase fue la más experimental. Se preparó el archivo en formato SVG (compatible con la máquina Brother J-103) en una memoria USB.

**Carga de archivos:** Se insertó la USB en el puerto ubicado en el costado derecho de la máquina. Con la máquina encendida y en la pantalla `Home`, se seleccionó la opción `Retrieve Data` y luego `Buscar dentro de USB` para acceder a los archivos compatibles (PHX, PHC, FCM, PES, SVG).

**Posicionamiento del diseño:** Una vez seleccionado el archivo, la máquina mostró una cuadrícula representando el área de corte. Se utilizó la opción `Edit` para arrastrar con el dedo el dibujo completo y posicionarlo en una zona de la cuadrícula donde se confirmaba la presencia de material.

**Pruebas previas:** Antes de ejecutar el trabajo completo, se realizó una prueba de corte en una pequeña esquina del material para verificar la presión y profundidad del corte sin arruinar toda la pieza.

#### Configuración de Parámetros

La configuración utilizada se basó en experimentación y se accedió a través de la opción `cut` (corte) en el menú de configuración:

- **Cut speed:** 3
- **Cut pressure:** -9
- **Cut pressure manual:** -9
- **Cut amount:** auto
- **Half cut:** On
- **Half cut:** -2

!!! warning "Limitaciones de Calibración"
    La máquina Brother Scan N Cut SDX225 solo permite valores de calibración en números enteros, con especificaciones vagas sobre las unidades y direcciones que cada parámetro representa. Esta falta de precisión hace difícil reproducir resultados consistentes entre intentos. Es necesario colocar el material sobre otro sustrato (por ejemplo, vinil) para evitar daños a la base de la máquina.

---

### Resultados y Desafíos Observados

Los principales fallos del proceso estuvieron directamente relacionados con la naturaleza no rígida de la cinta de cobre y limitaciones mecánicas de la máquina.

**Arrugamiento del metal:** La presión de la navaja a menudo provocaba que la delgada lámina de cobre se arrugara en lugar de ser cortada limpiamente, afectando especialmente en secciones donde se requería mayor precisión.

**Atascamiento en la navaja:** Pequeños fragmentos de cobre se quedaban atorados en la punta de la navaja, ocasionando que en trazados posteriores el material fuera desgarrado en lugar de cortado.

**Problemas mecánicos:** Una rotura en la máquina requirió mantener manualmente el cabezal durante el proceso de corte, lo que seguramente causó inconsistencias fundamentales en la profundidad y uniformidad del corte.

#### Limitaciones Identificadas

- **Fijación inconsistente:** A pesar del refuerzo adhesivo y la cama de sacrificio, algunas áreas tendían a levantarse durante el corte.
- **Repetibilidad limitada:** Los resultados variaban significativamente entre intentos, sugiriendo alta sensibilidad a condiciones iniciales y problemas de calibración.
- **Desgaste de herramienta:** La navaja requiere reemplazo frecuente debido a la naturaleza abrasiva del cobre.
- **Falta de precisión en parámetros:** La imposibilidad de ajustar valores con decimales limita el control fino necesario para este tipo de material.

#### Aspectos Funcionales

A pesar de los desafíos:

- Se lograron líneas de aislamiento de hasta 0.8 mm de ancho en algunas secciones
- Las pistas resultantes mantuvieron continuidad eléctrica donde el corte fue exitoso
- El proceso demostró viabilidad para prototipos de baja complejidad bajo condiciones óptimas

---

### Conclusiones

El uso de cortadora de vinil para fabricación de PCB flexibles representa una alternativa interesante para prototipado rápido. Sin embargo, el proceso actual requiere:

1. **Caracterización sistemática:** Los parámetros de corte necesitan optimización basada en pruebas controladas.
2. **Mejoras en fijación:** Desarrollo de métodos más confiables para mantener la cinta de cobre plana y adherida durante todo el proceso.
3. **Resolución de limitaciones mecánicas:** Reparación o reemplazo de componentes dañados es fundamental para obtener resultados reproducibles.

La técnica se encuentra en fase experimental pero muestra potencial para circuitos simples y flexibles, representando una herramienta valiosa cuando se comprenden sus limitaciones actuales.

---

### Recomendaciones para Trabajos Futuros

- Experimentar con diferentes tipos de cinta conductora (distintos espesores y aleaciones).
- Desarrollar plantillas de fijación personalizadas para mejorar la sujeción del material.
- Investigar tratamientos superficiales que mejoren la rigidez temporal del material durante el corte.
- Documentar sistemáticamente la relación entre parámetros de corte y calidad del resultado.
- Reparar o reemplazar componentes mecánicos dañados antes de continuar con pruebas.
- Considerar alternativas a la cortadora de vinil estándar que permitan mayor control de parámetros.