# termux_login

Termux es un emulador de terminal de Android y una aplicación de entorno Linux que funciona directamente sin necesidad de enraizamiento o configuración.

El no cuenta con un inicio de cecion  para  empezar a autenticarse en el equipo.

La autenticación sirve para comprobar que el usuario situado delante de la consola es quien pretende ser. Tiene que facilitar su identidad (nombre de inicio de sesión o login) y una prueba de esta (contraseña) para conectarse. Lo cual es el objetivo de este proyecto.


# Requisitos

**Hacker's Keyboard** [Teclado de cuatro o cinco filas](https://f-droid.org/packages/org.pocketworkstation.pckeyboard/)

![imagen de teclado](./img/teclado_1.jpg)
![imagen de teclado](./img/teclado_2.jpg)


```sh
apt install clang++ git -y 
```

# Intalacion

```sh
git clone [URL]
cd termux_login
make
```

# Configuracion

En el directorio de `$HOME` contaras con un archivo `.termux_login_conf.json` el cual es un formato de intercambio de datos  con el cual vas a poder configurar el menu.

- Color 
- Cursor 



# Recursos

Learning [ncurses](https://github.com/nasciiboy/NCURSES-Programming-HOWTO/blob/master/NCURSES-Programming-HOWTO-es.org)

[JSON](https://en.m.wikibooks.org/wiki/JsonCpp)

[La documentación de JsonCpp](http://open-source-parsers.github.io/jsoncpp-docs/doxygen/index.html#_intro)

Cómo hacer un [Makefile](https://hernandis.me/2017/03/20/como-hacer-un-makefile.html)
