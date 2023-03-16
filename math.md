Encontrar o pos_x = coseno do ângulo \* a velocidade

`cos(player->angle) * speed`

Encontrar pos_y = seno do ângulo \* a velocidade

`sin(player->angle) * speed`

Esquerda e direita = subtrai ou adiciona ângulo de acordo com a tecla apertada e multiplica pela velocidade.
LEFT
`pos_x - sin(player_angle) * speed`
`pos_x - cos(player_angle) * speed`

RIGHT
`pos_x + sin(player_angle) * speed`
`pos_x + cos(player_angle) * speed`
