#include<iostream> 
#include<fstream>
using namespace std;

/* 构造完成标志 */
bool sign = false;

/* 创建数独矩阵 */
int suduku[9][9];

/* 函数声明 */
bool Check(int n, int key);
int REP(int n);
void print_suduku();
int suduku_num;
int suduku_time;
/* 主函数 */
int main(int argc, char * argv[])
{
	suduku_num = (int)*argv[2] - 48;
	suduku_time = (int)*argv[4] - 48;
	ifstream myfile(argv[6]);
		for (int i = 0; i < suduku_time; i++)
		{
			for (int a = 0; a < suduku_num; a++)
			{
				for (int b = 0; b < suduku_num; b++)
				{
					myfile >> suduku[a][b];
				}
			}
			REP(0);
			print_suduku();
		}
	
	return 0;
}



void print_suduku()
{
	ofstream outfile("out.txt", ios::app);
	outfile << endl;
	for (int i = 0; i < suduku_num; i++)
	{
		for (int j = 0; j < suduku_num;j++)
		{
			outfile << suduku[i][j] << " ";
		}
		outfile << endl;
	}
	outfile.close();
}



bool Check(int n, int key)
{
	for (int i = 0; i < 9; i++)
	{
		int j = n / 9;
		if (suduku[j][i] == key) return false;
	}
	for (int i = 0; i < 9; i++)
	{
		int j = n % 9;
		if (suduku[i][j] == key) return false;
	}
	int x = n % 9 / 3 * 3;
	int y = n / 9 / 3 * 3;
	for (int i = y; i < y + 3; i++)
	{
		for (int j = x; j < x + 3; j++)
		{
			if (suduku[i][j] == key) return false;
		}
	}
	return true;
}

int REP(int n)
{
	if (n >= 81)
	{
		sign = true;
		return 0;
	}
	if (suduku[n / 9][n % 9] != 0)
	{
		REP(n + 1);
	}
	else
	{
		for (int i = 1; i <= 9; i++)
		{
			if (Check(n, i) == true)
			{
				suduku[n / 9][n % 9] = i;
				REP(n + 1);
				if (sign == true) return 0;
				suduku[n / 9][n % 9] = 0;
			}
		}
	}
}