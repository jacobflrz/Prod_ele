# Practica #1

---


**Nombre del proyecto**: Practica #1 - Primera PCB

**Equipo:** Sebastian Montaño y Juan Jacobo Florez

**Asignatura:** Produccion Electronica

**Fecha:** 19/09/2025

---
### Resumen

El proyecto fue un primer acercamiento al diseño y fabricación de PCB, utilizando KiCad como herramienta principal. Se aplicaron criterios básicos de diseño, como la separación entre pistas y la organización de los componentes, buscando una placa confiable y compacta. Más allá de obtener un diseño funcional o muy limpio, la actividad permitió entender cómo planear el enrutado, organizar los elementos en el espacio disponible y reconocer las limitaciones de las herramientas.

---

### Diseño de la PCB

 En nuestro caso, se nos entregó un esquemático de un circuito con cuatro entradas, cada una asociada a una única salida. Dichas salidas tienen como receptor de la señal un diodo LED, el cual actúa como indicador visual del funcionamiento del circuito.

A continuación, se presenta el esquemático correspondiente:
  
  ![Esquema](recursos/imgs/esquem.jpeg){ align=center } 


  En el diseño de la PCB fue necesario analizar las limitaciones de las herramientas disponibles, en este caso utilizamos la *Roland monoFab SRM-20* . Con base en ello, se definió una separación mínima entre pistas de **0.4 mm**, valor que garantiza la fabricabilidad de la placa.
  
  De igual forma, se evitó el uso de esquinas de 90° en las pistas, ya que este tipo de trazos puede generar acumulación de cargas eléctricas y dificultar el flujo de la corriente. Adoptar desde ahora estas buenas prácticas resulta importante para asegurar la escalabilidad de futuros proyectos.
  
  Adicionalmente, se buscó la organización más óptima de los componentes, priorizando la simplicidad del enrutado y la reducción del área ocupada. Con ello se logró que la placa utilizara únicamente los recursos necesarios, manteniendo un diseño limpio. 

   ![PCB](recursos/imgs/PCBB.jpeg){ align="center" width="95%" }


!!! note "Importante!"
    Entrar al panel de revision para ver que haya la menor cantidad de errores.

  Una vez tenemos definida la organizacion de la placa, añadimos las etiquetas y logotipos necesarios a la capa de `User.2`, el contorno a `EdgeCuts`, las pistas en `F.Cu` y los orificios donde pasaran nuestros pines los ponemos en la capa `User.1`. Todo esto busca otorgarnos mayor control sobre como se fabrica cada uno de los segmentos que conforman la PCB. Al momento de guardar las capas que ibamos a utilizar se guardo su trazo en un formato de vectores SVG.

  ![Esquema](recursos/imgs/Fabri.jpeg){ align=center } 


---


### Uso de Mods CE

 Esta herramienta web es la que nos ayudara a convertir los trazos SVG en codigo G que nuestra CNC pueda comprender y realizar su trabajo 