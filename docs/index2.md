# Práctica #2

---

**Nombre del proyecto**: Fabricación de PCB Flexible con Cortadora de Vinil

**Equipo:** Sebastián Montaño y Juan Jacobo Flórez

**Asignatura:** Producción Electrónica

**Fecha:** 28/09/2025

---

### Resumen

El presente proyecto constituyó un estudio sobre la viabilidad de adaptar tecnologías de fabricación digital, específicamente una cortadora de vinil Brother, para el prototipado rápido de circuitos impresos flexibles. El objetivo principal fue desarrollar y documentar un flujo de trabajo completo, desde la preparación de archivos en KiCad hasta la ejecución del corte sobre cinta de cobre. La metodología se centró en la generación de trazados de corte en negativo y en una modificación de la superficie del tapete de corte para asegurar la adhesión del material. Los resultados, aunque funcionales, demuestran que el proceso se encuentra en una fase temprana de caracterización. Se identificaron desafíos significativos relacionados con la naturaleza del material, el cual, al ser una cinta delgada no rígida, tiende a arrugarse y atorarse en la navaja, estableciendo que la técnica requiere una optimización considerable para ser confiable.

---

### Preparación de Archivos en KiCad

A diferencia de un proceso de fresado, la cortadora de vinil sigue líneas vectoriales. Por ello, fue necesario invertir la lógica del diseño para que la máquina cortara el material de aislamiento entre las pistas.

!!! danger "Paso Crítico: Exportación en Negativo"
    La cortadora está diseñada para seguir líneas. Si se exporta el diseño normal, cortaría el contorno de las pistas, destruyendo el circuito. Al exportar en negativo, las líneas que la máquina sigue son las del aislamiento entre pistas, que es precisamente el cobre que queremos remover.

#### Creación de la Máscara de Aislamiento

El procedimiento inició en KiCad con el uso de la herramienta creador de polígonos. Se dibujó un polígono que abarcaba la totalidad de la capa de cobre del diseño.

#### Exportación en Negativo

En el menú de Salidas de fabricación, se activó la opción de trazado en negativo. El archivo se exportó en formato SVG para asegurar su compatibilidad.

<figure style="text-align:center;">
  <img src="recursos/imgs/kicad_negativo.png" alt="Exportación en Negativo" style="width:80%;">
  <figcaption style="font-size:0.9em; color:gray;">Previsualización de la exportación en negativo en KiCad.</figcaption>
</figure>

---

### Preparación del Tapete y Material

La correcta fijación de la cinta de cobre fue uno de los mayores desafíos. Al ser una lámina metálica muy delgada y sin rigidez (similar a un tape), su comportamiento es muy diferente al del vinil.

**Adhesivo de Refuerzo:** Se aplicó una delgada capa de pegamento extra sobre la cama adhesiva para contrarrestar la tendencia del material a moverse o arrugarse.

**Carga del Material:** Con la cinta de cobre ya fijada, se posicionó el tapete y se utilizó el botón de **Carga tapete** para que la máquina lo sujetara.

!!! tip "Mantenimiento del Tapete"
    Es indispensable limpiar el tapete con alcohol después de cada uso. La acumulación de adhesivo y residuos de cobre puede afectar la planitud de la superficie y la calidad de futuros cortes.

---

### Proceso de Corte y Caracterización

Esta fase fue la más experimental. Se cargó el archivo desde una memoria USB usando la opción **"Retrieve Data"** y se posicionó digitalmente usando la función **"Edit"**.

#### Pruebas de Calibración

!!! tip "Realizar Siempre una Prueba de Corte"
    Antes de ejecutar el trabajo completo, se utilizó la opción **"Test"**. Este paso es fundamental en procesos experimentales para verificar la presión y profundidad del corte en una pequeña esquina del material sin arruinar toda la pieza.

#### Análisis de Parámetros

La configuración inicial se basó en la experimentación:

- **Cut speed:** 3
- **Cut pressure:** -9
- **Half cut:** On

---

### Resultados y Desafíos Observados

!!! warning "Proceso Aún en Caracterización"
    Los principales fallos del proceso estuvieron directamente relacionados con la naturaleza no rígida de la cinta de cobre.

Se identificaron dos problemas recurrentes:

**Arrugamiento del metal:** La presión de la navaja a menudo provocaba que la delgada lámina de cobre se arrugara en lugar de ser cortada limpiamente.

**Atascamiento en la navaja:** Pequeños fragmentos de cobre se quedaban atorados en la punta de la navaja, ocasionando que en trazados posteriores el material fuera desgarrado.