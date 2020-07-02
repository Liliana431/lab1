#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
// ����� - ����������� ��� ����������� � ����������� ����� 
int input(char str[], int cells, int count) //count - ���������� ���������, ������� ����� ��������� (1 ��� 2)
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

// ����� ���� ��������� �������  - ����, ������� ������ ��� ������
// arr[0] - ���������� �����, arr[1] - ��������� ������
int* step_right(int way[], int cells, int arr[], int end_point, int rec)// rec: 0 - ���� ������ 1 ���, 1 - ���� �����
{
	if (arr[1] == end_point)
		return way;
	arr[1]++;
	arr[0]++;
	way = realloc(way, (arr[0] + 1) * sizeof(int));	//���������� ��������
	way[arr[0]] = arr[1];
	if (rec == 1)		// ���������� ��������� ������
		way = step_right(way, cells, arr, end_point, 1);  // 1 - ���� ���� ������� ����� �����
	else way = up(way, cells, arr, end_point);	//��� �����
}

int* step_left(int way[], int cells, int arr[], int end_point, int rec)// rec: 0 - ���� ������ 1 ���, 1 - ���� �����
{
	if (arr[1] == end_point)
		return way;
	arr[1]--;
	arr[0]++;
	way = realloc(way, (arr[0] + 1) * sizeof(int));	//���������� ��������
	way[arr[0]] = arr[1];
	if (rec == 1)		// ���������� ��������� �����
		way = step_left(way, cells, arr, end_point, 1);	// 1 - ���� ���� ������� ����� �����
	else way = down(way, cells, arr, end_point);	//��� ����
}

int up(int way[], int cells, int arr[], int end_point)
{
	if ((arr[1] - end_point > 0) && ((arr[1] - 1) / cells == (end_point - 1) / cells)) //���� � � b � ����� ������ 
		way = step_left(way, cells, arr, end_point, 1); // 1 - ���� ���� ������� ����� �����
	if (arr[1] - end_point < 0)		//���� � ����������� b
		way = step_right(way, cells, arr, end_point, 1); // 1 - ���� ���� ������� ����� �����
	if (arr[1] % cells == 1)	// ������ ��������� �����
		way = step_right(way, cells, arr, end_point, 0); // 0 - ���� ���� ������� ������  ���
	else
	{
		if (arr[1] == end_point)	// ���� ����� �� �����
			return way;
		arr[1] = arr[1] - cells - 1;
		arr[0]++;
		way = realloc(way, (arr[0] + 1) * sizeof(int)); //���������� ��������
		way[arr[0]] = arr[1];
		way = up(way, cells, arr, end_point); // ���������� ��������� �����
	}
}

int down(int way[], int cells, int arr[], int end_point)
{
	if ((end_point - arr[1] > 0) && ((arr[1] - 1) / cells == (end_point - 1) / cells)) //���� � � b � ����� ������
		way = step_right(way, cells, arr, end_point, 1); // 1 - ���� ���� ������� ����� �����
	if (end_point - arr[1] < 0) //����� � ����������� b
		way = step_left(way, cells, arr, end_point, 1); // 1 - ���� ���� ������� ����� �����
	if (arr[1] % cells == 0) // ������ ��������� ����
		way = step_left(way, cells, arr, end_point, 0); // 0 - ���� ���� ������� ������  ���
	else
	{
		if (arr[1] == end_point)
			return way;//  ���� ����� �� �����
		arr[1] = arr[1] + cells + 1;
		arr[0]++;
		way = realloc(way, (arr[0] + 1) * sizeof(int)); //���������� ��������
		way[arr[0]] = arr[1];
		way = down(way, cells, arr, end_point); // ���������� ��������� ����
	}
}