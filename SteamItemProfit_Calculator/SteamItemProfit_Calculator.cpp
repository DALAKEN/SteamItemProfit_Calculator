#include <iostream>

using std::cout;
using std::cin;

class ProfitCalc
{
	public:

		ProfitCalc()
		{
			_steamPrice = 0;
			_marketPrice = 0;
			_result = 0;
			_money = "\tUSD\t";
		}

		void FormatNumber(double& num) {

			int a = num;
			double b = int((num - a) * 100) / (double)100;

			num = a + b;
		}
		void CommissionSteam(double& _steamPrice) {

			double STEAM_PRC = 13;
			double commissionResult = _steamPrice - (_steamPrice * STEAM_PRC / 100);

			FormatNumber(commissionResult);
			_steamPrice = commissionResult;
		}
		double DifferencePercentages(double& a, double& b) {

			// Difference in percentages: a < b = ((b - a) / a) * 100 || a > b = ((a - b) / a) * 100 

			if (a > b) _result = ((a - b) / a) * 100;
			else _result = 0;

			FormatNumber(_result);

			return _result;
		}
		void ShowMenu()
		{
			do
			{
				InputPrice();
				ShowSteamProfit();

			} while (true);
		}
		void InputPrice() {

			cout << "\n ENTER ANY MARKET PRICE\t> ";
			cin >> _marketPrice;

			cout << " ENTER STEAM PRICE\t> ";
			cin >> _steamPrice;
		}
		void ShowSteamProfit() {

			system("cls");

			cout << "\n ---- STEAM ----\n\n";

			cout << " " << _marketPrice << _money << "ANY MARKET PRICE \n\n";
			cout << " " << _steamPrice << _money << "STEAM PRICE \n\n";

			CommissionSteam(_steamPrice);

			cout << " " << _steamPrice << _money << "STEAM COMMISSION (13%)\n\n";
			cout << " " << _steamPrice - _marketPrice << _money << "PROFIT (MONEY)\n\n";

			cout << " ---------------\n\n ";

			cout << DifferencePercentages(_steamPrice, _marketPrice) << " %\tPROFIT (PERCENT)\n";
		}

	private:

		double _steamPrice;
		double _marketPrice;
		double _result;
		const char* _money;
};

int main() 
{
	ProfitCalc *profitCalc = new ProfitCalc;
	profitCalc->ShowSteamProfit();
	profitCalc->ShowMenu();

	return 0;
}