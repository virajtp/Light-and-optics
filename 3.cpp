#include<iostream>
#include <random>
using namespace std;

int main() {

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> rndm100(0, 99);
	uniform_int_distribution<int> rndm1000(0, 999);
	uniform_int_distribution<int> rndm10000(0, 9999);

	int rounds=100;

		for (int i = 0; i < rounds; i++) {

			//declare variables
			int amountRefIn = 0;
			int amountAbsorb1 = 0;
			int amountAbsorb2 = 0;
			int amountRefExt1 = 0;
			int amountRefEnt2 = 0;
			int amountRefOut = 0;
			int amountOut = 0;

			for (int j = 0; j < 10000; j++) {
				int enteringSurface1 = rndm100(gen);	// enter first layer
				if (enteringSurface1 < 99) {
					int behave1 = rndm10000(gen);	//condition in the first layer
					if (behave1 < 10) {
						amountRefExt1++;
					}
					else if (behave1 < 75) {
						amountAbsorb1++;
					}
					else {
						int enteringSurface2 = rndm10000(gen);	// enter second layer
						if (enteringSurface2 > 50){
							int behave2 = rndm10000(gen);	//condition in the second layer
							if (behave2 < 1)
								amountRefOut++;
							else if (behave2 < 50)
								amountAbsorb2++;
							else
								amountOut++;
						}
						else
							amountRefEnt2++;	
					}
				}
				else
					amountRefIn++;
				}

			//display output
			cout << "Range " << i * 10000 << " - " << (i + 1) * 10000 << endl;
			cout << "Reflect on the entering surface\t : " << amountRefIn << endl;
			cout << "Absorbed to the medium 1\t : " << amountAbsorb1 << endl;
			cout << "Reflect exiting surface(Med. 1)\t : " << amountRefExt1 << endl;
			cout << "Reflect entering surface(Med. 2) : " << amountRefEnt2 << endl;
			cout << "Absorbed to the medium 2\t : " << amountAbsorb2 << endl;
			cout << "Reflect on the exiting surface\t : " << amountRefOut << endl;
			cout << "Exit from medium 2\t\t : " << amountOut << endl << endl;
	}
	cout << endl;
	system("pause");
	return 0;
}
