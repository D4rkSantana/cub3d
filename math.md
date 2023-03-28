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

------------------------------------
hasWallAt(x, y) {
# protection don't go outside the map
if (x < 0 || x > WINDOW_WIDTH || y < 0 || y > WINDOW_HEIGHT) {
    return true;
}
# Math.floor round the number to int
var mapGridIndexX = Math.floor(x / TILE_SIZE);
var mapGridIndexY = Math.floor(y / TILE_SIZE);
return this.grid[mapGridIndexY][mapGridIndexX];
}

-----------------------
const FOV_ANGLE(angulo de visão) = 60 * (PI / 180);
const NUM_RAYS = 320; (largura da tela em pixels)

rayAngle += FOV_ANGLE / NUM_RAYS;
------------------------
rotationSpeed = 2 * (PI / 180)
