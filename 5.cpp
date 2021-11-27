#include<iostream>
#include<random>
using namespace std;
 
int main() {

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> rndm100(0, 99);
	uniform_int_distribution<int> rndm60000(0, 59999);

	//declare variables
	double Pi = 3.14159265;
	int output = 0;
	int validArea = 1 * sin(Pi*20/180) * 10000; //get the valid area

	for(int photons =0 ;photons < 10000; photons++){
		int enteringSurface1 = rndm60000(gen); 
		if (validArea * 6 < enteringSurface1) { // first layer condition
			int refOutSurface1 = rndm100(gen);
			if (refOutSurface1 >= 5) { 
				int absorb1 = rndm100(gen);
				if (absorb1 >= 10) {
					int refInSurface1 = rndm100(gen);
					if (refInSurface1 >= 3) {
						int enteringSurface2 = rndm60000(gen);
						if (validArea * 4 < enteringSurface2) {	//second layer condition
							int refOutSurface2 = rndm100(gen);
							if (refOutSurface2 >= 5) { 
								int absorb2 = rndm100(gen);
								if (absorb2 >= 10) {
									int refInSurface2 = rndm100(gen);
									if (refInSurface2 >= 3) {
										int refOutSurface3 = rndm60000(gen);
										if (validArea * 6 < refOutSurface3) { //third layer condition
											int refOutSurface3 = rndm100(gen);
											if (refOutSurface3 >= 5) { 
												int absorb3 = rndm100(gen);
												if (absorb3 >= 10) {
													int refInSurface3 = rndm100(gen);
													if (refInSurface3 >= 3) {
														output++;
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
	}
	int finalOut = output / 100 ; //get the output as a percentage
	//display output
	cout << "Percentage of light that pass through the structure  =  " << finalOut<<"% \n" << endl;
	system("pause");
	return 0;
}