# Autores

Iury Lamonie
& 
Leonardo Igor

# 1. Introdução:

Este projeto contém a implementação de dois dictionary Abstract Data Type (ADT) baseada em uma Array List.

# 2. O programa de testes:

Foi utilizado uma copia do arquivo de testes disponibilizado no SIGAA. O conteudo do arquivo foi copiado para o ```main.cpp```.

Para compilar o arquivo de testes, utilize o comando ```make``` dentro da pasta ```list``` e em seguida o comando ```./bin/main``` para rodar o programa.

# 2. Makefile/Compiling:

Verifica se o setup está configurado, caso contrario, fará um novo setup chamando "make dir" e compila. Ele chama "make all" internamente.

```
make
```

Você também pode passar argumentos para o compilador. Como o exemplo abaixo:
```
make args="-D something=212"
```
Para ativar o modo debug, faça:

```
make args="-D DEBUG"
```

Fará tods os diretórios de trabalho. Você pode fazer isso manualmente ou automaticamente se você usar "make".
```
make dir
```

Limpa todo o diretorio de trabalho, irá apagar todos os arquivos contidos em bin e docs
```
make clean
```

Fará a documentação para o projeto atual.
```
make doxy
```

Irá chamar "make clear" e "make dir"
```
make fresh
```