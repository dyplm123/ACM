#include"iostream"
using namespace std;
#define MIN(a,b) a<b?a:b
#define MAX(a,b) a>b?a:b
int tryeggs(int break_height[][100], int n, int f)
{
	if (f == 1)
	{
		return 1;
	}
	else if (n == 1)
	{
		return f;
	}
	else
	{
		int min = 100, i, up, down, t;
		for (i = 1; i <= f; i++)
		{
			if (break_height[n - 1][i - 1] == -1)
			{
				up = tryeggs(break_height, n - 1, i - 1);
			}
			else
			{
				up = break_height[n - 1][i - 1];
			}
			if (break_height[n][f - i - 1] == -1)
			{
				down = tryeggs(break_height, n - 1, i - 1);
			}
			else
			{
				down = break_height[n][f - i - 1];
			}
			t = MAX(up, down);
			min = MIN(t, min);
		}
		return min + 1;
	}
}

int main()
{
	int n, f;
	while (cin >> n >> f)
	{
		int break_height[100][100] = {-1};
		int result;
		result = tryeggs(break_height, n, f);
		cout << result << endl;
	}
	return 0;
}