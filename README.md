# AGV Filoguiado — Equipo 0 (demo de clase)

Trabajo práctico de **Sistemas Automáticos Basados en Microcontroladores** Grado en Ingeniería
Electrónica Industrial · Universidad de Cádiz · Curso 2026-27

> [!WARNING]
> Repositorio de **ejemplo**, generado para la introducción a Git y GitHub de la clase 1.
> No es el firmware real del AGV: sirve para practicar el flujo de ramas por hito y para mostrar, ya
> rellenas con datos de ejemplo, las plantillas obligatorias del curso (`Plantillas/`). La plantilla
> en blanco de este README está en `Plantillas/README_equipo.md`.

## 1. Descripción del repositorio de ejemplo

Este repositorio simula el trabajo de un equipo durante varias sesiones de laboratorio de Sistemas
Automáticos Basados en Microcontroladores. Su objetivo es servir como demostración práctica del
flujo de trabajo con Git y GitHub.

El historial está preparado para recorrer tres hitos de desarrollo:

- **H1 — Sensor:** lectura simulada del sensor de guiado, con una prueba de oscilación para
  comprobar el filtrado.
- **H2 — Máquina de estados:** esqueleto de la FSM y sus transiciones, desarrollados en ramas
  independientes y fusionados posteriormente.
- **H3 — Control PWM:** incorporación del esqueleto de control de motores y resolución en directo de
  un conflicto de fusión en `src/fsm.c`.

Además, el repositorio incluye ejemplos de ramas, fusiones `--no-ff`, etiquetas, mensajes de commit
y algunas plantillas de código, documentación y declaración de uso de IA generativa.

## 2. Primer día de laboratorio

### 2.1 Lo que necesitáis antes de empezar

| Elemento | Nota |
| --- | --- |
| Un PC con Windows, macOS o Linux | El del laboratorio ya lo tiene todo instalado; en vuestro portátil, seguid esta guía completa |
| La tarjeta **FRDM-MCXA156** | Con su cable USB tipo C |
| El software de NXP **MCUXpressoInstaller** | Para instalar VS Code, el compilador de ARM, la extensión y el resto de herramientas necesarias para compilar y programar el microcontrolador |
| El software de configuración **MCUXpresso_Config_Tools_26.06_x64** | Para configurar visualmente los periféricos de la tarjeta |
| Conexión a Internet | Para descargar VS Code, la extensión y el SDK (~cientos de MB) |
| Una carpeta de trabajo **sin espacios ni acentos en la ruta** | P. ej. `C:\SABEM` o `~/sabem`, nunca `C:\Users\Mi Usuario\Prácticas AGV` |

**Nota importante:** Los ficheros del escritorio de los PC del laboratorio se borran al apagar el
equipo. Guardad vuestro trabajo en vuestro repositorio Git antes de iros cada día.

### 2.2 Instalación paso a paso

Estos son los pasos esenciales para dejar el entorno funcionando:

1. **Instalar Visual Studio Code** desde [code.visualstudio.com](https://code.visualstudio.com/) y
comprobad que arranca correctamente.
2. **Instalar la aplicación MCUXpresso Config Tools** desde el campus virtual.
3. **Instalar la extensión MCUXpresso for VS Code** (de NXP) desde el panel de Extensiones
(`Ctrl+Shift+X`). Al terminar, aparecerá un nuevo icono de MCUXpresso en la barra lateral.
4. **Importar el SDK de la FRDM-MCXA156** desde el gestor de SDK dentro de la extensión. La primera
descarga tarda varios minutos.
5. **Conectar la tarjeta FRDM-MCXA156** al PC con el cable USB-C al conector J22. El LED de
alimentación debe encenderse.
6. **Verificar la conexión:** el sistema operativo debe reconocer la sonda de depuración (MCU-Link)
y el puerto serie virtual.

**Para una guía detallada con capturas y solución de problemas**, consultad la
[Guia de instalación](docs/Guia_instalacion_VSCode_MCUXpresso.md).

### 2.3 Entorno Recomendado

#### Extensión oficial

La extensión de **NXP: `nxpsemiconductors.mcuxpresso`** es obligatoria. Es la herramienta central
para gestionar SDKs, proyectos, compilación y depuración durante todo el curso.

#### Extensiones útiles para empezar

Para un entorno funcional y sin distracciones, recomendamos instalar:

- **`editorconfig.editorconfig`** — mantiene la consistencia de indentación y espacios en blanco
entre distintos editores del equipo.
- **`usernamehw.errorlens`** — muestra los errores de compilación inline en el código, sin necesidad
de abrir la consola.

#### Extensiones opcionales para documentación

Si trabajáis frecuentemente con documentación dentro del repositorio:

- **`davidanson.vscode-markdownlint`** — valida la sintaxis de Markdown mientras escribís.
- **`bierner.markdown-mermaid`** — renderiza diagramas Mermaid dentro de los ficheros `.md`.
- **`tomoki1207.pdf`** — abre PDFs dentro de VS Code (útil para consultar referencias rápidamente).

#### Extensiones a evitar en esta práctica

Por favor, **no instaléis**:

- **Extensiones remotas** (Remote SSH, Remote Containers, etc.) — pueden complicar innecesariamente
la configuración.
- **Otras extensiones C/C++ o depuradores** — la extensión MCUXpresso ya trae integrado todo lo que
necesitáis.

El objetivo es mantener un entorno común y ágil, sin distracciones visuales ni dependencias
adicionales.

### 2.4 Proyecto de prueba: parpadeo del LED

Antes de empezar cualquier desarrollo, es necesario verificar que **toda la cadena de herramientas
funciona de extremo a extremo**.

#### Importar y ejecutar

1. Desde el panel de MCUXpresso, **importad el ejemplo** `driver_examples/gpio/led_output` para la
tarjeta `frdmmcxa156`, eligiendo como cadena de herramientas **`arm-none-eabi-gcc`**.
2. **Compilad** el proyecto (botón de compilar del panel). Fijaos en la salida: al final aparece el
tamaño del programa.
3. **Cargad y ejecutad** el programa sobre la tarjeta con la MCU-Link. El LED de la tarjeta debe
empezar a parpadear inmediatamente.

Si el LED parpadea, la cadena completa —VS Code, extensión, SDK, compilador, sonda, tarjeta—
funciona. Es todo lo que necesitamos verificar en este momento.

> Para una comprobación más profunda del depurador (opcional), consultad la sección 4.2 de
> [Guía de instalación](docs/Guia_instalacion_VSCode_MCUXpresso.md#4-proyecto-de-prueba-parpadeo-del-led).

## 10. Agradecimientos y Herramientas

Parte del contenido de este repositorio de ejemplo se ha generado y/o modificado con IA generativa:

| Modelo / herramienta | Función concreta realizada | Ficheros afectados |
| - | - | - |
| Claude Sonnet 5 | Creación del repositorio de ejemplo | `README.md` |
| GPT-5.6 Luna | Configuración del fichero de configuración de VS Code | `.vscode/settings.json` |

- [Plantilla de Declaración de IA generativa](Plantillas/DECLARACION_IAG.md).

## 11. Referencias y recursos de aprendizaje

- **Github**
    - [Github para estudiantes](https://docs.github.com/es/education/about-github-education/github-education-for-students/about-github-education-for-students)
    - [GitHub Docs](https://docs.github.com/es)
    - [Guía de sintaxis de escritura y formato en GitHub](https://docs.github.com/es/get-started/writing-on-github/getting-started-with-writing-and-formatting-on-github/basic-writing-and-formatting-syntax)
- **Curso de introducción a Git y GitHub** (GitHub Skills)
    - [Introducción a Github](https://github.com/skills/introduction-to-github)
    - [Comunicación con Markdown](https://github.com/skills/communicate-using-markdown)
    - [Introducción a Git](https://github.com/skills/introduction-to-git)
    - [Introducción a la gestión de repositorios](https://github.com/skills/introduction-to-repository-management)
- **FRDM-MCXA156**
    - [Página oficial de la tarjeta](https://www.nxp.com/design/development-boards/freedom-development-boards/freedom-development-platform-for-mcxa156:FRDM-MCXA156)
    - [Guía de inicio rápido](https://www.nxp.com/document/guide/getting-started-with-frdm-mcxa156:GS-FRDM-MCXA156)
    - [Manual de usuario](https://www.nxp.com/docs/en/user-manual/UM12121.pdf)
    - [Página oficial del MCXA156](https://www.nxp.com/products/MCX-A13X-A14X-A15X)
    - Manual de referencia del MCXA156 disponible en el Campus Virtual
- [Documentación de MCUXpresso](https://mcuxpresso.nxp.com/mcux-vscode/latest/)

## 11. Licencia

Licencia Creative Commons Attribution-ShareAlike 4.0 International (CC BY-SA 4.0) para este
repositorio.

---

En el caso del repositorio final del equipo, las licencias están recogidas en la plantilla de README
del equipo (`Plantillas/README_equipo.md`), y son las siguientes:

- Hardware: CERN Open Hardware Licence Version 2 - Strongly Reciprocal [^1]
- Código fuente (firmware): GNU General Public License version 3 or later [^2]
- Documentación: GNU Free Documentation License, Version 1.3 or later [^3]

[^1]: El hardware del AGV (PCB, esquemático, planos de mecanizado) está licenciado bajo la licencia
CERN OHL v2.0, que permite el uso, modificación y distribución del hardware siempre que se mantenga
la misma licencia y se reconozca a los autores originales.

[^2]: El firmware del AGV está licenciado bajo la GNU GPL v3 o posterior, lo que permite el uso,
modificación y distribución del código fuente siempre que se mantenga la misma licencia y se
reconozca a los autores originales.

[^3]: La documentación del AGV (manuales, guías, diagramas) está licenciada bajo la GNU FDL v1.3 o
posterior, lo que permite el uso, modificación y distribución de la documentación siempre que se
mantenga la misma licencia y se reconozca a los autores originales.
