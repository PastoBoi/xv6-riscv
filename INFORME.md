#Informe paso a paso

## Informacion Personal

Nombre: Felipe Céspedes 
Fecha: 08/28/2025

## Paso a Paso

1. El repositorio fue forkeado, del github "https://github.com/mit-pdos/xv6-riscv", usando la funcion de clonacion en la aplicacion de github Desktop

2. Luego como ya habia sido forkeado, se creo la nueva rama con el nombre de Pasto, usando la funcion para crear ramas de Github Desktop

3. wsl fue instalado usando en el Poweshell el comando "wsl --install"

4. Una vez en el subsistema de linux, se hizo sudo "apt update" para mantener la informacion de los paquetes a la fecha

5. luego se instalaron todas las dependencias usando el comando "sudo apt install git build-essential gdb-multiarch qemu-system-misc gcc-riscv64-linux-gnu binutils-riscv64-linux-gnu"

6. Luego compilamos usando el makefile con el comando "make"

7. Luego usamos QEMU, que es un emulador de hardware con el comando "make qemu"