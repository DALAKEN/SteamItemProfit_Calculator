#include <iostream>

using namespace std;

class SteamCalc
{
	public:

		SteamCalc()
		{
			_steamPrice = 0;
			_marketPrice = 0;
			_money = "\tUSD\t";
		}

		void number_format(double& num) {

			int a = num;
			double b = int((num - a) * 100) / (double)100;

			num = a + b;
		}
		void Steam_commission(double& _steamPrice) {

			double STEAM_PRC = 13;
			double result = _steamPrice - (_steamPrice * STEAM_PRC / 100);

			number_format(result);
			_steamPrice = result;
		}
		double prc_diff(double& a, double& b, double result = 0) {

			// Разница в процентах: a < b = ((b - a) / a) * 100 || a > b = ((a - b) / a) * 100 

			if (a > b) result = ((a - b) / a) * 100;
			else result = 0;

			number_format(result);

			return result;
		}
		void ShowSteamProfit() {

			system("cls");

			cout << "\n ---- STEAM ----\n\n";

			cout << " " << _marketPrice << _money << "PRICE ANY MARKET\n" << endl;
			cout << " " << _steamPrice << _money << "PRICE STEAM\n" << endl;

			Steam_commission(_steamPrice);

			cout << " " << _steamPrice << _money << "13% COMMISSION STEAM\n" << endl;
			cout << " " << _steamPrice - _marketPrice << _money << "money PROFIT\n" << endl;

			cout << " ---------------\n\n ";

			cout << prc_diff(_steamPrice, _marketPrice) << " %\tPROFIT" << endl;
		}
		void input_price() {

			cout << "\n ENTER ANY MARKET PRICE\t> ";
			cin >> _marketPrice;

			cout << " ENTER STEAM PRICE\t> ";
			cin >> _steamPrice;
		}

	private:

		double _steamPrice;
		double _marketPrice;
		const char* _money;
};

int main() 
{

	SteamCalc steamCalc;
	steamCalc.ShowSteamProfit();

	do 
	{
		steamCalc.input_price();
		steamCalc.ShowSteamProfit();

	}
	while(true);

	return 0;
}