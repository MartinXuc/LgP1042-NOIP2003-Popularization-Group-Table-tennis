#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
class board
{
public:
	int A_score = 0;
	int B_score = 0;
	board(int sign) { this->sign = sign; }
	~board() {}
	int sign;
	void A_add() { A_score++; }
	void B_add() { B_score++; }
	int gap() { return abs(A_score - B_score); }
	bool result()
	{
		if (gap() >= 2 && (A_score >= sign || B_score >= sign)) return true;
		else return false;
	}
	void init()
	{
		A_score = 0;
		B_score = 0;
	}
};
int main()
{
	board board11(11), board21(21);
	vector<int> result11;
	vector<int> result21;
	char ch;
	while(1)
	{
		cin >> ch;
		if (ch == 'E')break;
		if (ch == '\n')continue;
		if (ch == 'W')
		{
			board11.A_add();
			board21.A_add();
		}
		if (ch == 'L')
		{
			board11.B_add();
			board21.B_add();
		}
		if (board11.result())
		{
			result11.push_back(board11.A_score);
			result11.push_back(board11.B_score);
			board11.init();
		}
		if (board21.result())
		{
			result21.push_back(board21.A_score);
			result21.push_back(board21.B_score);
			board21.init();
		}
	}
	result11.push_back(board11.A_score);
	result11.push_back(board11.B_score);
	result21.push_back(board21.A_score);
	result21.push_back(board21.B_score);
	for (int i = 0; i < result11.size(); i+=2)
		cout << result11[i] << ':' << result11[i + 1] << endl;
	cout << endl;
	for (int i = 0; i < result21.size(); i += 2)
		cout << result21[i] << ':' << result21[i + 1] << endl;
	return 0;
}