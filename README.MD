# RetroSpy Server

RetroSpy is a GameSpy Project that aims to create GameSpy 2011/2012 services.

The server is written in C++ and it could be considered as the spiritual successor to OpenSpy Core since most of the modules are based from it.


See the [wiki](https://github.com/GameProgressive/RetroSpyServer/wiki) for more information about compiling and creating a RetroSpy Server.

### Cloning submodules
```
git submodule update --recursive --remote
```

### Special thanks
* [Luigi Auriemma](http://aluigi.altervista.org/papers.htm) for his papers about gamespy that i used as a reference
* [OpenSpy](https://github.com/Masaq-/Openspy-Core) for the idea of the architecture and the portions of code of the modules
* [MySQL](https://www.mysql.com/) for their database server that is used in RetroSpy
* [libUV](http://libuv.org/) for their awesome asyncrous I/O library that is used on the Server
