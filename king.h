#ifndef king
#define king
//count - количество элементов, которые нужно прочитать (1 или 2)
// str - строка дл€ вывода перед вводом
int input(char str[], int cells, int count); // ввод 

// вывод  всех функций  - путь, который фигура уже прошла (way)
// arr[0] - количество шагов, arr[1] - последн€€ записанна€ клетка
// в step_right, step_left - rec: 0 - если только 1 шаг, 1 - если много
int* step_right(int way[], int cells, int arr[], int end_point, int rec);// движение вправо
int* step_left(int way[], int cells, int arr[], int end_point, int rec);// движение влево
int up(int way[], int cells, int arr[], int end_point);//движение вверх при а<b  
int down(int way[], int cells, int arr[], int end_point);//движение вниз при а>b 

#endif 