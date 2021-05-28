/*
7. Шахматная игра
Дано поле N × M. На нем расположены две ладьи, координаты каждой (X1, Y1) и (X2, Y2) соответственно. Ладья ходит по классическим правилам
 шахмат: за один ход может переместиться в любую клетку, расположенную на одной вертикали либо горизонтали. Одна ладья может сбить другую,
 если та находится с ней на одной горизонтали либо вертикали.

Основное отличие от классических правил: ладья не может переместиться в клетку, если во время передвижения к ней она станет на клетку,
 которая находится под боем другой ладьи. У первого игрока в распоряжении первая ладья, а у второго —вторая. Игроки ходят по очереди,
 ход пропускать нельзя. Первым ходит первый игрок. Проигрывает тот, кому некуда ходить (куда бы ни пошел — собьют). Определите кто 
 победит при оптимальной игре обоих.
*/

#include <iostream>
int main() {
    int N, M, X1, Y1, X2, Y2;
    std::cin >> N >> M >> X1 >> Y1 >> X2 >> Y2;
    std::cout << (abs(X1 - X2) == abs(Y1 - Y2) ? "NO" : "YES");
}
