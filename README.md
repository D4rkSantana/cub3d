## Cub3d ##

<p align="center">
  <img src="http://img.shields.io/static/v1?label=License&message=MIT&color=green&style=for-the-badge"/>
  <img src="http://img.shields.io/static/v1?label=TESTES&message=%3E5&color=RED&style=for-the-badge"/>
   <img src="http://img.shields.io/static/v1?label=STATUS&message=EM%20DESENVOLVIMENTO&color=RED&style=for-the-badge"/>
</p>

### Tópicos 

:small_blue_diamond: [Descrição do projeto](#descrição-do-projeto)

:small_blue_diamond: [Funcionalidades](#funcionalidades)

:small_blue_diamond: [Demonstração do funcionamento do game](#demonstração-do-funcionamento-do-game)

:small_blue_diamond: [Pré-requisitos](#pré-requisitos)

:small_blue_diamond: [Como rodar a aplicação](#como-rodar-a-aplicação)

:small_blue_diamond:  [Como rodar os testes](#como-rodar-os-testes)

:small_blue_diamond:  [Linguagens e libs utilizadas](#linguagens-e-libs-utilizadas)

:small_blue_diamond:  [Tarefas em aberto](#ltarefas-em-aberto)

:small_blue_diamond:  [Desenvolvedores](#desenvolvedores)


## Descrição do projeto 

Esse projeto faz parte do curriculo da 42 São Paulo e tem como objetivo a constução de um jogo ultilizando raycasting inspirado no classico Wolfenstein 3D

Aqui trabalhamos a implementação do racasting, criação e documentação de um programa complexo, gerenciamento correto dos recursos alocados e qualidade de codigo, todo o programa foi desenvolvido em C e utilizamos a biblioteca Minilibx fornecida pela 42 Paris


## Demonstração do funcionamento do game

> https://youtu.be/dQw4w9WgXcQ

> Adicionar prints e gifs

## Pré-requisitos

- Sistema operacional Linux
- Linguagem C instalada
- Compilador gcc
- Makefile instalado
- Git instalado


## Como rodar a aplicação

No terminal, clone o projeto: 

```
git clone https://github.com/D4rkSantana/cub3d.git
```

em seguida compile o projeto com o make

```
make
```

compilando com sucesso só rodar
```
./cub3d map.cub
```


## Como rodar os testes

Teste com os mapas padrões

	Mapa 1
```
./cub3d map1.cub
```
	Mapa 2
```
./cub3d map2.cub
```
	Mapa 3
```
./cub3d map3.cub
```

Teste de leaks com o valgrind
```
make val
```

Teste de leaks com sanitaze
```
make sanitaze
```


## Linguagens e libs utilizadas 

- [Linguagem C](https://pt.wikipedia.org/wiki/C_(linguagem_de_programa%C3%A7%C3%A3o)
- [Minilibx](https://github.com/42Paris/minilibx-linux)


## Tarefas em aberto

- Completar a documentação
- implementar do raycaster
- Definir e criar a arte do game
- Testar e resolver leaks e relativos
- Realizar a entrega do projeto

## Desenvolvedores

[Jessica Fernanda](https://github.com/nandajfa)

[Emerson Santana](https://github.com/D4rkSantana)

## Licença 

The [Nenhuma]() (NULL)
