#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
// вывод - прочитанное или прочитанное и посчитанное число 
int input(char str[], int cells, int count) //count - количество элементов, которые нужно прочитать (1 или 2)
{
	int value, value1, value2;
	printf(str);
	if (count == 1)
	{
		scanf_s("%d", &value);
	}
	else
	{
		scanf_s("%d%d", &value1, &value2);
		value = (value1 - 1) * cells + value2;
		if (value2 > cells)
			return 0;
	}
	return value;
}

// вывод всех остальных функций  - путь, который фигура уже прошла
// arr[0] - количество шагов, arr[1] - последняя клетка
int* step_right(int way[], int cells, int arr[], int end_point, int rec)// rec: 0 - если только 1 шаг, 1 - если много
{
	if (arr[1] == end_point)
		return way;
	arr[1]++;
	arr[0]++;
	way = realloc(way, (arr[0] + 1) * sizeof(int));	//добавление элемента
	way[arr[0]] = arr[1];
	if (rec == 1)		// продолжаем двигаться вправо
		way = step_right(way, cells, arr, end_point, 1);  // 1 - если надо сделать много шагов
	else way = up(way, cells, arr, end_point);	//шаг вверх
}

int* step_left(int way[], int cells, int arr[], int end_point, int rec)// rec: 0 - если только 1 шаг, 1 - если много
{
	if (arr[1] == end_point)
		return way;
	arr[1]--;
	arr[0]++;
	way = realloc(way, (arr[0] + 1) * sizeof(int));	//добавление элемента
	way[arr[0]] = arr[1];
	if (rec == 1)		// продолжаем двигаться влево
		way = step_left(way, cells, arr, end_point, 1);	// 1 - если надо сделать много шагов
	else way = down(way, cells, arr, end_point);	//шаг вниз
}

int up(int way[], int cells, int arr[], int end_point)
{
	if ((arr[1] - end_point > 0) && ((arr[1] - 1) / cells == (end_point - 1) / cells)) //если а и b в одной строке 
		way = step_left(way, cells, arr, end_point, 1); // 1 - если надо сделать много шагов
	if (arr[1] - end_point < 0)		//если а перескочило b
		way = step_right(way, cells, arr, end_point, 1); // 1 - если надо сделать много шагов
	if (arr[1] % cells == 1)	// нельзя двигаться вверх
		way = step_right(way, cells, arr, end_point, 0); // 0 - если надо сделать только  шаг
	else
	{
		if (arr[1] == end_point)	// если дошли до конца
			return way;
		arr[1] = arr[1] - cells - 1;
		arr[0]++;
		way = realloc(way, (arr[0] + 1) * sizeof(int)); //добавление элемента
		way[arr[0]] = arr[1];
		way = up(way, cells, arr, end_point); // продолжаем двигаться вверх
	}
}

int down(int way[], int cells, int arr[], int end_point)
{
	if ((end_point - arr[1] > 0) && ((arr[1] - 1) / cells == (end_point - 1) / cells)) //если а и b в одной строке
		way = step_right(way, cells, arr, end_point, 1); // 1 - если надо сделать много шагов
	if (end_point - arr[1] < 0) //еасли а перескочило b
		way = step_left(way, cells, arr, end_point, 1); // 1 - если надо сделать много шагов
	if (arr[1] % cells == 0) // нельзя двигаться вниз
		way = step_left(way, cells, arr, end_point, 0); // 0 - если надо сделать только  шаг
	else
	{
		if (arr[1] == end_point)
			return way;//  если дошли до конца
		arr[1] = arr[1] + cells + 1;
		arr[0]++;
		way = realloc(way, (arr[0] + 1) * sizeof(int)); //добавление элемента
		way[arr[0]] = arr[1];
		way = down(way, cells, arr, end_point); // продолжаем двигаться вниз
	}
}