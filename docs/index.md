# Práctica #1

---

**Nombre del proyecto**: Práctica #1 - Primera PCB

**Equipo:** Sebastián Montaño y Juan Jacobo Flórez

**Asignatura:** Producción Electrónica

**Fecha:** 19/09/2025

---

### Resumen

El proyecto constituyó un primer acercamiento al diseño y fabricación de PCB, utilizando KiCad como herramienta principal. Se aplicaron criterios básicos de diseño, como la separación entre pistas y la organización de componentes, buscando obtener una placa confiable y compacta. Más allá de lograr un diseño funcional y limpio, la actividad permitió comprender cómo planificar el enrutado, organizar los elementos en el espacio disponible y reconocer las limitaciones de las herramientas disponibles.

---

### Diseño de la PCB

#### Configuración inicial en KiCad

Para comenzar en KiCad, descargamos bibliotecas que contenían no solo los componentes, sino también las huellas que íbamos a utilizar recurrentemente en la clase. El menú principal de KiCad nos muestra varias herramientas, siendo las más relevantes el **editor de esquemas** y el **editor de placas**.  

- El **editor de esquemas** permite construir el esquemático de nuestro circuito, mostrando cómo se conectan los elementos.  
- El **editor de placas** nos permite organizar físicamente los componentes sobre la PCB y planificar el enrutado.

<figure style="text-align:center;">
  <img src="recursos/imgs/PrinciKcad.png" alt="Página principal KiCad" style="width:80%;">
  <figcaption style="font-size:0.9em; color:gray;">Página principal de KiCad</figcaption>
</figure>

#### Trabajo con el editor de esquemas

En esta sección definimos qué componentes necesitamos y cómo se conectan, sin preocuparnos aún por la disposición física.  

**Colocación de componentes:**  
Se utiliza `(A)` para abrir la biblioteca de componentes, seleccionando cada uno según necesidad. Cada componente tiene su huella correspondiente para el editor de placas.

<figure style="text-align:center;">
  <img src="recursos/imgs/Acomponen.png" alt="Menú de componentes" style="width:80%;">
  <figcaption style="font-size:0.9em; color:gray;">Menú de componentes (A)</figcaption>
</figure>

**Métodos de conexión:**  
1. **Conexiones con cable `(W)`**: Conexiones directas entre componentes cercanos.  
2. **Etiquetas `(L)`**: Conexiones entre puntos distantes, evitando cables largos que ensucien el esquema. Las etiquetas con nombres descriptivos como `VCC` y `GND` simplifican la comprensión del circuito.

#### Esquemático del circuito

Se nos proporcionó un esquemático con cuatro entradas y sus correspondientes salidas hacia diodos LED, que sirven como indicadores visuales.

![Esquema](recursos/imgs/esquem.jpeg){ align="center" }

#### Transición al editor de placas

Para acceder al editor de placas, se utiliza el icono verde en la esquina superior derecha del editor de esquemas. Desde el editor de placas también podemos regresar al editor de esquemas. Es importante actualizar la placa desde el esquema, lo que permite detectar errores y visualizar las huellas.

<figure style="text-align:center;">
  <img src="recursos/imgs/Actual.png" alt="Actualización de placa" style="width:70%;">
  <figcaption style="font-size:0.9em; color:gray;">Actualización de placa desde el esquema</figcaption>
</figure>

#### Consideraciones de diseño

Se analizaron las limitaciones de la *Roland monoFab SRM-20*, definiendo una separación mínima entre pistas de **0.4 mm** y evitando esquinas de 90° para mejorar el flujo de corriente y reducir acumulación de carga.  

#### Optimización del layout

Se priorizó la simplicidad del enrutado y la reducción del área ocupada, logrando un diseño limpio y eficiente.

![PCB](recursos/imgs/PCBB.jpeg){ align="center" width="95%" }

!!! tip "Importante!"
    Entrar al panel de revisión y ejecutar el DRC para verificar que haya la menor cantidad de errores.

![DRC](recursos/imgs/DRC.jpeg){ align="center" width="99%" }

#### Preparación para fabricación

Se añadieron etiquetas y logotipos a la capa `User.2`, contorno a `EdgeCuts`, pistas en `F.Cu` y orificios en `User.1`. Al guardar estas capas, se exportaron en formato SVG para facilitar el uso en la CNC.

![Esquema](recursos/imgs/Fabri.jpeg){ align="center" }

!!! tip "Importante!"
    La casilla "Fit page to board" debe estar marcada y el formato debe ser SVG.

---

### Uso de Mods CE

Esta herramienta convierte los trazos SVG en código G para la CNC. Accedimos a la página de [Mods][doc-ref] y seguimos la ruta:

**programs --> open program --> Roland --> SRM-20mill --> mill 2D PCB**

Se cargó el SVG en **read SVG**, se invirtió en **Convert SVG** y se configuró la herramienta `mill traces 1/64` en **set PCB defaults**.  

![mods](recursos/imgs/Mods_4.png){ align="center" width="85%" }  
![PCB](recursos/imgs/Mods_3.png){ align="center" width="55%" }  

!!! tip "PCB DEFAULTS"
    Para capas de hoyos y perímetro, usar `mill traces 1/32`.

En **mill raster 2D** se visualizó el recorrido y se ajustó `offset number` a `2` o `3`. Para hoyos o contornos, `tool diameter` se colocó en `0.99mm`.  

![PCB](recursos/imgs/Mods_2.png){ align="center" width="110%" }  

En **Roland SRM-20 milling machine**, se configuró la velocidad: perforaciones `0.4mm/s`, contorno `1mm/s`, pistas `4mm/s`.  

!!! tip "Roland SRM-20 milling machine"
    Establecer X, Y, Z en `0` y ajustar velocidad según trazo.

Se activó la sección **inputs on/offs** para guardar el archivo cada vez que se presiona `calculate`.  

![PCB](recursos/imgs/Mods_1.png){ align="center" width="87%" }  

---

### Uso de la monoFab

Se conectó la máquina vía USB y se abrió **VPanel** para controlar movimientos en X, Y, Z. Se instalaron herramientas aflojando y ajustando el tornillo prisionero.

<figure style="text-align:center;">
  <img src="recursos/imgs/prisionero.jpeg" alt="Herramienta en prisionero" style="width:50%;">
</figure>

En la sección **Spindle** se controla la velocidad de rotación y encendido/apagado del motor. Se cargaron archivos `.rml` generados en Mods para realizar el corte.

![VP](recursos/imgs/Vpanel.jpeg){ align="center" width="99%" }

!!! tip "Definir Orígenes"
    El origen X/Y corresponde a la esquina inferior izquierda, de donde se realizará todo el trazado.

---

## Maquinado

<video width="640" height="360" controls muted>
  <source src="recursos/Videos/cncc.mp4" type="video/mp4">
  Tu navegador no soporta la reproducción de video.
</video>

![VP](recursos/imgs/pcbbb.jpeg){ align="center" width="75%" }

El resultado fue satisfactorio: las pistas mantienen su tamaño, con variaciones mínimas en zonas donde el material era de calidad inferior.

[doc-ref]: https://modsproject.org/ "Mods"


