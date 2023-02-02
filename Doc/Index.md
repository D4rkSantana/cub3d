Documentação do projeto Cub3d

## Sructs utilizadas

- *t_data*
	Struct principal que agrupa todos os elementos principais, como o mapa, o ponteiro mlx, ponteiro da janela, ponteiro da imagem, dimensões, variavel de fechamento e etc...
	A struct é inicializada pela função "init" contida em [[Init]]
	a struct é limpa pela função "destroy" contida em [[Destroy]]
```
typedef struct s_data

{

void *mlx; //Ponteiro geral da interface grafica

void *win; //Ponteiro para a janela da interface grafica

void *image; //Ponteiro para a imagem renderizada

int h_teste; // Variavel criada para testar a mlx_image

int w_teste; // Variavel criada para testar a mlx_image

t_map *map; //Ponteiro para o mapa

int close_game; //Variavel que indica quando o programa deve encerrar

} t_data;
```

- *t_map*
	Armazena os dados do mapa e um char \*\* com os caracteres do mapa
	A struct é inicializada pela função "init_map" chamada pela "init" contida em [[Init]]
	a struct é limpa pela função "destroy_map" chamada pela "destroy" contida em [[Destroy]]
```
typedef struct s_map

{

char *patch; //String contendo o caminho para o mapa

char **elements; //Matriz com os elementos do mapa

int height; //altura do mapa

int col; //largura do mapa

int player; 

char *no_path;

char *so_path;

char *we_path;

char *ea_path;

} t_map;
```