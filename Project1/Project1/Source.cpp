#include<iostream>
#include<ctime>
#include<iomanip>
#include<conio.h>
#include<Windows.h>

using namespace std;
void SetColor(int col)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), col);
}

void SetColorBack(int text, int background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}
void main()
{
	//1. «робити трикутники вар≥анти б, в, д

	/*setlocale(LC_ALL, "Russian");
	srand(time(0));
	const int row = 11;
	const int col = 11;
	int arr[row][col] = {};
	for (int i = 0; i < row; i++)
	{
	for (int j = 0; j < col; j++)
	{
	arr[i][j] = rand() % 10;
	}
	}

	for (int i = 0; i < row; i++)
	{
	for (int j = 0; j < col; j++)
	{
	cout << setw(4) << arr[i][j];
	}
	cout << endl;
	}
	cout << endl;
	cout << endl;
	cout << " б " << endl;

	for (int i = 0; i < row; i++)
	{
	for (int j = 0; j < col; j++)
	{
	if (j < i)
	{
	arr[i][j];
	}
	}
	}
	for (int i = 0; i < row; i++)
	{
	for (int j = 0; j < col; j++)
	{
	if (j < i)
	{
	cout << setw(4) << arr[i][j];
	}
	else
	{
	cout << setw(4) << '.';
	}
	}
	cout << endl;
	}
	cout << endl;
	cout << endl;

	cout << " в " << endl;
	for (int i = 0; i < row; i++)
	{
	for (int j = 0; j < col; j++)
	{

	if ((j <= col / 2 && i < j + 1) || (j >= col / 2 && i < row - j))
	{
	cout << setw(4) << arr[i][j];
	}
	else
	{
	cout << setw(4) << '.';
	}
	}
	cout << endl;
	}
	cout << endl;
	cout << " д " << endl;
	for (int i = row - 1; i >= 0; i--)
	{
	for (int j = 0; j < col; j++)
	{
	if ((j <= col / 2 && i <= j) || (j >= col / 2 && i < row - j))
	{
	cout << setw(4) << arr[i][j];
	}
	else
	{
	cout << setw(4) << '.';
	}
	}
	cout << endl;
	}
	cout << endl;
	cout << endl;*/

	//2.ƒана матриц€ розм≥рн≥стю 10х10, заповнена випадковими числами в д≥апазон≥[1..50].
	//«найти м≥н≥мальний елемент матриц≥ ≥ пом≥н€ти м≥сц€ми р€дки матриц≥ так щоб м≥н≥мальний елемент опинивс€
	//у верхньому р€дку(додатково можна пом≥н€ти м≥сц€ми ще й стовпц≥ так, щоб цей елемент опинивс€ у крайньому
	//правому стовпц≥).
	srand(time(0));
	const int row = 10;
	const int col = 10;
	int arr[row][col] = {};
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			arr[i][j] = rand() % 50 + 1;
		}
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << setw(5) << arr[i][j];
		}
		cout << endl;
	}
	cout << endl;
	cout << endl;
	int min = arr[0][0];
	int colMin = 0;
	int rowMin = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (arr[i][j] < min)
			{
				min = arr[i][j];
				colMin = j;
				rowMin = i;
			}
		}
	}
	for (int j = 0; j < col; j++)
	{
		int temp = arr[0][j];
		arr[0][j] = arr[colMin][j];
		arr[colMin][j] = temp;
	}
	for (int i = 0; i < row; i++)
	{
		int temp = arr[i][rowMin];
		arr[i][rowMin] = arr[i][9];
		arr[i][9] = temp;
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (arr[i][j] == min)
				SetColor(12);
			cout << setw(5) << arr[i][j];
			SetColor(7);
		}
		cout << endl;
	}
	cout << endl;
}