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
			int amountRefPaint = 0;
			int amountReEnter = 0;
			int amountExitMed1 = 0;

			for (int j = 0; j < 100000; j++) {
				int enteringSurface1 = rndm100(gen);	//enter through surface 1
				if (enteringSurface1 < 99) {
					int behave1 = rndm10000(gen);
					if (behave1 >= 75) {
						int enteringSurface2 = rndm10000(gen);	//enter through surface 2
						if (enteringSurface2 >= 10) {
							int behave2 = rndm10000(gen);
							if (behave2 >= 50) {
								int absorb2 = rndm10000(gen);
								if (absorb2 >= 50) {
									int behave3 = rndm10000(gen);
									if (behave3 >= 500) {
										amountRefPaint++;
										int absorb3 = rndm10000(gen);
										if (absorb3 >= 50) {
											int reEnteringSurface2 = rndm1000(gen);	//re-enter through surface 2
											if (reEnteringSurface2 > 1) {
												int reEntering = rndm100(gen);
												if (reEntering > 1) {
													amountReEnter++;
													int behave4 = rndm10000(gen);
													if (behave4 >= 75) {
														int exit = rndm1000(gen);
														if (exit > 1) {
															amountExitMed1++;
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}

			//display output
			cout << "Range " << i * 100000 << " - " << (i + 1) * 100000 << endl;
			cout << "Total number of photons reflects from the paint\t\t\t: " << amountRefPaint << endl;
			cout << "Total number of photons that re-enter the medium 1 from medium 2: " << amountReEnter << endl;
			cout << "Total number of photons exit form the medium 1\t\t\t: " << amountExitMed1 << endl<<endl;
	}
	cout << endl;
	system("pause");
	return 0;
}