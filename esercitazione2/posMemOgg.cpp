#include <iostream>
using namespace std;

int main()
{
	double ad[4] = {0.0, 1.1, 2.2, 3.3};
	float af[8] = {0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
	int ai[3] = {0, 1, 2};
	
	int x = 1;
	float y = 1.1;
	
	cout << "indirizzo x: " << &x << "\n";
	cout << "indirizzo y: " << &y << "\n";
	
	for(int i=0; i<4; i++)
	{
		cout << "indirizzo ad[" << i << "]: " << &ad[i] << "\n";
	}
	
	for(int i=0; i<8; i++)
	{
		cout << "indirizzo af[" << i << "]: " << &af[i] << "\n";
	}
	
	for(int i=0; i<3; i++)
	{
		cout << "indirizzo ai[" << i << "]: " << &ai[i] << "\n";
	}
	
	(&y)[1] = 0;
	
	cout << x << "\n";
	
	
	return 0;
}