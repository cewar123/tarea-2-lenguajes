# tarea-2-lenguajes
🚀 Instrucciones de Compilación y Ejecución
Es crítico utilizar las banderas de optimización indicadas para una comparación justa.

1. C++ (Enfoque Imperativo / Metal Desnudo)
El código utiliza punteros y gestión manual de memoria para máxima velocidad.

PowerShell

# Compilar con Optimización Nivel 3 (-O3)
g++ "tarea 2.cpp" -o tarea2_opt.exe -O3

# Ejecutar y Medir
Measure-Command { .\tarea2_opt.exe }
2. Rust (Enfoque de Sistemas Seguro)
Utiliza el sistema de Ownership y Borrowing para garantizar seguridad de memoria sin Garbage Collector.

PowerShell

# Compilar en modo Release (Optimizado)
cargo build --release

# Ejecutar y Medir (desde la carpeta del proyecto)
Measure-Command { .\target\release\simulador_quimico.exe }
3. Haskell (Enfoque Funcional Puro)
Utiliza recursividad de cola y tipos algebraicos estrictos.

PowerShell

# Compilar con Optimización Nivel 2 (-O2)
ghc -O2 main.hs -o simulador_haskell.exe

# Ejecutar y Medir
Measure-Command { .\simulador_haskell.exe }
