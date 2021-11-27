#include<iostream>
#include <random>
using namespace std;

int main() {

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> rndm100(0, 99);
	uniform_int_distribution<int> rndm1000(0, 999);

	//variable declaration
	int rounds, selection;	

	cout << "------Select the number of Photons------\n\n";
	cout << "\t1 - 10000\n";
	cout << "\t2 - 100000\n";
	cout << "\t3 - 1 million\n\n\t";

	cin >> selection;	//getting user selection
	cout << endl;

	//check the user selection
	if (selection == 1)
		rounds = 1;
	else if (selection == 2)
		rounds = 10;
	else if (selection == 3)
		rounds = 100;
	else {
		cout << "Invalid selection !!!\n\n";
		system("pause");
		return 0;
	}

	for (int i = 0; i < rounds; i++) {
		int amountRefIn = 0;
		int amountAbsorb = 0;
		int amountRefExit = 0;
		int amountPassingThrough = 0;
		for (int j = 0; j < 10000; j++) {
			int num =rndm100(gen);

			if (num < 99) {
				int absorb = rndm1000(gen);
				if (absorb < 1)
					amountRefExit++;
				else if (absorb < 5)
					amountAbsorb++;
				else
					amountPassingThrough++;
			}
			else
				amountRefIn++;
		}

		//display output
		cout << "Range " << i * 10000 << " - " << (i + 1) * 10000 << endl;
		cout << "Amount of Photons reflect on the entering surface\t : " << amountRefIn << endl;
		cout << "Amount of Photons absorbed to the medium\t\t : " << amountAbsorb << endl;
		cout << "Amount of Rphotons reflect on the exiting surface\t : " << amountRefExit << endl;
		cout << "Amount of Photons exit from the glass\t\t\t : " << amountPassingThrough << endl << endl;
	}

	cout << endl;
	system("pause");
	return 0;
}
