# Práctica #5 - Altium Designer

---

**Nombre del proyecto**: Introducción a Altium Designer

**Equipo:** Sebastián Montaño y Juan Jacobo Flórez

**Asignatura:** Producción Electrónica

**Fecha:** [FECHA]

---

### Resumen

Esta práctica representa una introducción al software profesional Altium Designer, una de las herramientas más utilizadas en la industria para el diseño de circuitos impresos. El objetivo fue familiarizarse con el entorno de trabajo, la estructura de proyectos, el diseño de esquemáticos, la gestión de librerías de componentes, y el proceso completo hasta la generación de PCB. Altium ofrece un ecosistema integrado con herramientas de simulación, verificación de diseño y características avanzadas de enrutado automático. Se aplicaron criterios de diseño similares a prácticas anteriores (separación de pistas de 0.4 mm y buenas prácticas de enrutado).

---

### Configuración Inicial y Creación de Proyecto

#### Estructura de Proyecto en Altium

Altium Designer organiza el trabajo mediante un sistema de proyectos (`.PrjPcb`) que integra todos los archivos relacionados: esquemáticos, PCB, librerías y documentos de salida.

**Creación del proyecto:**

1. **Nuevo proyecto:** `File` → `New` → `Project` → `PCB Project`
2. **Nombre y ubicación:** Se definió el nombre del proyecto y la carpeta de trabajo
3. **Estructura generada:** Altium creó automáticamente la estructura de carpetas

!!! tip "Organización de Archivos"
    Altium mantiene todos los archivos del proyecto en una carpeta centralizada. Es recomendable crear subcarpetas para librerías personalizadas, documentación y archivos de fabricación desde el inicio.

**IMAGEN SUGERIDA:** `altium_nuevo_proyecto.png` - Captura del diálogo de nuevo proyecto

---

### Gestión de Librerías de Componentes

Uno de los aspectos más importantes en Altium es la gestión de componentes, que integra símbolo esquemático, huella PCB y modelo 3D.

Altium incluye acceso a librerías en línea mediante **Manufacturer Part Search**, que permite buscar componentes con toda su información técnica, modelos 3D y disponibilidad comercial.

**Proceso de búsqueda de componentes:**

1. **Abrir panel Components:** `Panels` → `Components`
2. **Manufacturer Part Search:** Buscar por número de parte o descripción
3. **Selección:** Revisar footprint, símbolo y modelo 3D
4. **Agregar al proyecto:** Descargar e integrar al diseño

**IMAGEN SUGERIDA:** `altium_components_panel.png` - Panel de componentes con búsqueda activa

---

### Diseño del Esquemático

El editor de esquemáticos de Altium ofrece herramientas avanzadas de verificación y documentación.

#### Creación del Esquemático

1. **Nuevo esquemático:** Click derecho en el proyecto → `Add New to Project` → `Schematic`
2. **Configuración de página:** `Design` → `Document Options` para definir tamaño y marco

**Colocación de componentes:**

- **Tecla de acceso:** `P` → `P` (Place Part)
- **Búsqueda rápida:** Escribir nombre o número de parte
- **Rotación:** `Spacebar` durante colocación
- **Copiar múltiples:** Seleccionar + `Ctrl+D` (duplicar con espaciado)

**IMAGEN SUGERIDA:** `altium_esquematico_componentes.png` - Esquemático con componentes colocados

#### Conexiones y Cableado

- **Wire (cable):** `Ctrl+W` para iniciar conexión punto a punto
- **Net Labels:** `P` → `N` para etiquetar redes sin cables físicos
- **Bus:** Para múltiples señales relacionadas
- **Power Ports:** `P` → `Shift+P` para VCC, GND, etc.

!!! tip "Net Labels vs. Cables"
    Similar a KiCad, usar Net Labels limpia visualmente el esquemático. Altium conecta automáticamente todos los puntos con el mismo nombre de red, incluso entre múltiples hojas.

**IMAGEN SUGERIDA:** `altium_esquematico_completo.png` - Esquemático finalizado con etiquetas

#### Validación del Esquemático

Antes de pasar al PCB, Altium requiere compilación del proyecto:

1. **Compilar:** `Project` → `Compile PCB Project`
2. **Revisar errores:** Panel Messages muestra warnings y errors
3. **Electrical Rule Check (ERC):** Detecta problemas como pines sin conectar, cortocircuitos potenciales

**IMAGEN SUGERIDA:** `altium_compile_messages.png` - Panel de mensajes después de compilar

---

### Diseño de PCB

#### Transferencia desde Esquemático

1. **Crear PCB:** Click derecho en proyecto → `Add New to Project` → `PCB`
2. **Update PCB:** `Design` → `Update PCB Document`
3. **Validación:** Panel ECO (Engineering Change Order) muestra cambios a aplicar
4. **Ejecutar cambios:** `Validate Changes` → `Execute Changes`

**IMAGEN SUGERIDA:** `altium_update_pcb.png` - Diálogo de Engineering Change Order

#### Configuración de la Placa

**Definir contorno de placa:**

- **Design** → **Board Shape** → **Define from Selected Objects** (si se tiene un contorno dibujado)
- O usar **Define Board Shape** y dibujar manualmente

**Reglas de diseño:**

`Design` → `Rules` permite configurar:

- **Clearance:** Separación mínima entre pistas (0.4 mm como en Práctica #1)
- **Width:** Ancho mínimo de pistas (0.4 mm)
- **Via Style:** Tamaño de vías
- **Manufacturing:** Restricciones de fabricación

**IMAGEN SUGERIDA:** `altium_design_rules.png` - Editor de reglas de diseño

!!! note "Design Rule Check (DRC)"
    Altium verifica reglas en tiempo real. Violaciones aparecen como líneas verdes en el diseño. Ejecutar `Tools` → `Design Rule Check` genera un reporte completo.

#### Colocación de Componentes

Los componentes aparecen inicialmente en el área de trabajo fuera de la placa.

**Herramientas de organización:**

- **Auto-Position:** `Tools` → `Component Placement` → `Arrange Within Rectangle`
- **Alineación:** Seleccionar múltiples + Click derecho → `Align`
- **Distribución:** `Arrange` → `Distribute` para espaciado uniforme

**IMAGEN SUGERIDA:** `altium_componentes_colocados.png` - Vista de componentes organizados en PCB

#### Enrutado de Pistas

Altium ofrece múltiples modos de enrutado:

**Enrutado Manual:**

- **Iniciar ruta:** `Ctrl+W` o click en pad
- **Modo de esquina:** `Shift+Space` cambia entre 45°, 90° y arco
- **Terminar:** Click derecho → `End Route` o `Esc`

**IMAGEN SUGERIDA:** `altium_routing_manual.png` - Proceso de enrutado manual

#### Auto-Routing

Una de las características distintivas de Altium es su motor de enrutado automático.

**Configuración de Auto-Router:**

1. **Acceder:** `Auto Route` → `All` desde el menú
2. **Configurar estrategias:** 
   - **Número de pasadas:** Intentos que hará el algoritmo para mejorar el enrutado
   - **Prioridad de capas:** Define qué capa usar preferentemente
   - **Vías permitidas:** Cantidad máxima de vías a utilizar
   - **Estrategia de enrutado:**
     - **Fanout:** Crea vías iniciales desde pads SMD hacia área de enrutado
     - **Memory:** Utiliza resultados de pasadas anteriores para mejorar
     - **Main:** Algoritmo principal de enrutado
     - **Recorner:** Optimiza esquinas y reduce segmentos innecesarios
     - **Cleanup:** Limpia y optimiza rutas finales

3. **Ejecutar:** `Route All`

!!! warning "Auto-Routing: Consideraciones"
    El auto-routing es útil para evaluar rápidamente la viabilidad del layout y para diseños con muchas conexiones. Sin embargo, es importante revisar y optimizar las rutas generadas automáticamente para asegurar la calidad del diseño final.

**IMAGEN SUGERIDA:** `altium_autorouter_config.png` - Diálogo de configuración del auto-router

**IMAGEN SUGERIDA:** `altium_pcb_final.png` - PCB completamente enrutado

---

### Verificación y Validación

#### Design Rule Check (DRC)

El DRC es crucial antes de enviar a fabricación:

1. **Ejecutar:** `Tools` → `Design Rule Check`
2. **Configurar:** Seleccionar reglas a verificar
3. **Analizar resultados:** Panel muestra violaciones con ubicación exacta
4. **Navegación:** Double-click en error lleva directo a la ubicación

**Errores comunes:**

- Clearance violations (pistas muy cerca)
- Unrouted nets (conexiones sin completar)
- Width constraint violations (pistas muy delgadas)

**IMAGEN SUGERIDA:** `altium_drc_report.png` - Reporte de DRC con violaciones

#### Visualización 3D

Altium permite visualizar el diseño en 3D:

- **Activar vista 3D:** `View` → `Switch to 3D` o tecla `3`
- **Rotación:** Click y arrastrar
- **Componentes:** Requieren modelos STEP asociados

Esta vista ayuda a:

- Verificar clearances mecánicos
- Detectar componentes que puedan interferir
- Presentación profesional del diseño

**IMAGEN SUGERIDA:** `altium_vista_3d.png` - Vista 3D del PCB con componentes

---

### Generación de Archivos de Fabricación

Altium permite generar múltiples formatos de salida para fabricación y documentación.

#### Archivos Gerber y Otros Formatos

1. **Fabrication Outputs:** `File` → `Fabrication Outputs` → `Gerber Files`
2. **Configuración:**
   - Formato: 2:5 (suficiente precisión)
   - Unidades: Milímetros o pulgadas según fabricante
   - Capas: Seleccionar todas las necesarias

3. **Generar:** Altium crea carpeta con archivos `.gbr`

**Otros formatos de salida disponibles:**

- **DXF/DWG:** `File` → `Fabrication Outputs` → `DXF/DWG` - Para importar en software CAD mecánico
- **PDF:** Documentación de capas y ensamblaje
- **IDF (Intermediate Data Format):** Para validación mecánica en MCAD
- **STEP:** Modelo 3D completo de la PCB con componentes
- **ODB++:** Formato estándar de la industria, alternativa a Gerber

#### Drill Files

`File` → `Fabrication Outputs` → `NC Drill Files` para archivos de perforación en formato Excellon.

**IMAGEN SUGERIDA:** `altium_gerber_setup.png` - Configuración de salida Gerber

---

### Conclusiones

Altium Designer representa una herramienta profesional completa para diseño de PCB. La práctica permitió familiarizarse con:

1. **Flujo de trabajo integrado:** Desde esquemático hasta archivos de fabricación en un mismo entorno
2. **Gestión de componentes:** Acceso a librerías online de fabricantes con información técnica completa
3. **Herramientas avanzadas:** Auto-routing con estrategias configurables, DRC en tiempo real, y visualización 3D
4. **Preparación profesional:** Estándar industrial ampliamente utilizado en la industria electrónica

El proceso completo de diseño en Altium demostró ser eficiente y bien integrado, desde la concepción del esquemático hasta la generación de archivos para fabricación. Las herramientas de validación automática y el auto-router facilitan significativamente el proceso de diseño, aunque siempre requieren revisión y optimización manual para garantizar la calidad del producto final.


