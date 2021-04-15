# Act. Integradora 1
### Jacobo Soffer A01028653
Programa que carga una lista de logs a un vector, los ordena y posteriormente permite a usuario buscar logs entre cierto rango de fechas.

## Compilación
Por conveniencia, en sistemas UNIX o Linux el siguiente script puede ser ejecutado:
```sh
$ ./build.sh
```
Este script genera un ejecutable llamado `main` en el directorio donde es ejecutado.
Para Windows o para compilar manualmente, basta con llamar el compilador de preferencia y pasarle los archivos que se encuentran en el directorio `src` con extensión `.cpp`. No son necesarios argumentos o flags adicionales. En caso de moverse al directorio `src` al momento de compilación, es recomendable mover el ejecutable resultante al directorio principal para una ejecución más sencilla.

## Ejecución
Para ejecutar sólo llame el ejecutable resultante por el proceso de compilación:
```sh
$ ./main
```
Asegurese de que el archivo que contiene los logs se llame `bitacora.txt` y se encuentre en el directorio donde esta el ejecutable, de lo contrario ocurrirá un error de ejecución.

Los logs deben estar en el siguiente formato:
```
Fecha hora ip:puerto razón
Mmm hh:mm:ss 00.000.00.00:0000 Error message
```
Por ejemplo:
```
Sep 23 12:58:18 80.169.79.65:1150 Failed password for illegal user root
```
Por conveniencia, puede compilar y ejecutar este programa en el siguiente [replit](https://replit.com/@sofferjacob/ActividadIntegradora1).