#include<iostream>
#include <random>
using namespace std;

int main() {

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> rndm100(0, 99);
	uniform_int_distribution<int> rndm1000(0, 999);

	int rounds=100;
	
		for (int i = 0; i < rounds; i++) {

			//declare variables
			int amountRefIn = 0;
			int amountAbsorb = 0;
			int amountRef = 0;
			int amountPassingThrough = 0;
			int amountOut = 0;

			for (int i = 0; i < 10000; i++) {

				int enteringSurface = rndm100(gen);
				if (enteringSurface < 99) {
					int behave = rndm1000(gen);
					if (behave >= 5) {
						int refSecSurface = rndm100(gen);
						if (refSecSurface < 99) {
							behave = rndm1000(gen);
							if (behave < 1)
								amountRef++;
							else if (behave < 5)
								amountAbsorb++;
							else
								amountOut++;
						}
					}
				}
			}
			//display output
			cout << "Range " << i * 10000 << " - " << (i + 1) * 10000 << endl;
			cout << "Amount of Photons exit from entering surface\t\t\t : " << amountOut << endl << endl;
	}
	cout << endl;
	system("pause");
	return 0;
}