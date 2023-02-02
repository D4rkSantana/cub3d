
```
int	check_color(char *line)
```
	Verifica se os caracteres de cor estão corretos, se o path é válido 
	encaminha para as funções.

```
int	check_cl_floor(char *line, t_map *map, int i, int j)
```
	Verifica se a cor do piso em RGB está entre 0 e 255, e se o caractere é um número. 

```
int	check_cl_ceilling(char *line, t_map *map, int i, int j)
```
	Verifica se a cor do teto em RGB está entre 0 e 255, e se o caractere é um número.