#ifndef king
#define king
//count - ���������� ���������, ������� ����� ��������� (1 ��� 2)
// str - ������ ��� ������ ����� ������
int input(char str[], int cells, int count); // ���� 

// �����  ���� �������  - ����, ������� ������ ��� ������ (way)
// arr[0] - ���������� �����, arr[1] - ��������� ���������� ������
// � step_right, step_left - rec: 0 - ���� ������ 1 ���, 1 - ���� �����
int* step_right(int way[], int cells, int arr[], int end_point, int rec);// �������� ������
int* step_left(int way[], int cells, int arr[], int end_point, int rec);// �������� �����
int up(int way[], int cells, int arr[], int end_point);//�������� ����� ��� �<b  
int down(int way[], int cells, int arr[], int end_point);//�������� ���� ��� �>b 

#endif 