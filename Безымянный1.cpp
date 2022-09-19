#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <Windows.h>
#include <fstream>
using namespace std;
int main()
{
	ofstream fout("answer1111.XLS");
	double dt = 0.005;
	double dx = 0.01;
	double u[1001],uold[1001] ;
	double uu[1001];
	double e = 0.00001;
	double maxdif = -10;
	int k = 0;
	double x;
	double pi=3.14;

	for (int j = 0; j <= 1000; j++) {
		uold[j] = 0.0;//j*dx*(1-j*dx);
	}
	
	for (int i = 1; i < 1000; i++) {
		maxdif = -10;
		
			u[i] =(dt / dx*dx) *(uold[i + 1] - 2 * uold[i] + uold[i - 1]) + uold[i]; 
		
		
		for (int j = 0; j < 1001; j++) {
			if (maxdif < abs(u[i] - uold[i])) {
				maxdif = abs(u[i] - uold[i]);
			}
		}
		k++;
		if (maxdif < e) break;
	}
	for (int j = 1; j < 1000; j++) {
			
			uu[j] = exp(-sqrt(dx*j))*cos(2*dt*k- sqrt(dx*j));
		} 
	for (int j = 1; j < 1001; j++) {
		cout << u[j] << "\t" <<uu[j]<< endl;
	}
	cout << "maxdif:" << maxdif << endl;
	
	cout << "maxdif:" << k << endl;
	system("pause");
    return 0;
}
