Instalaciones previas:
Se destaca que este código está pensado para su empleo en máquinas MacOS debido a que todos los integrantes del grupo poseen dichas máquinas.


Se ha empleado la herramienta Homebrew para la instalación de flex y bison.
$ brew install flex
$ brew install bison
En caso de no tener instalado la herramienta homebrew, será necesario correr previamente en el terminal de mac el siguiente comando:
$ ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"


Ejecute el archivo comp.sh con un parámetro que sea el nombre del archivo .ada que desee compilar
De forma que quede por ejemplo:
sh comp.sh IfTest.ada