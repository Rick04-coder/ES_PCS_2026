#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	static const int N = 10;
	double arr[N] = {1.2, 3.4, 0.5, 9.8, 4.2, 7.1, 2.2, 5.5, 8.9, 1.0};
	double min_val = arr[0];
	double max_val = arr[0];
	double sum = 0;
	
	for(int i = 0; i < N; i++)
	{
		min_val = min(min_val, arr[i]);
		max_val = max(max_val, arr[i]);
		sum += arr[i];
	}
	
	double media = sum/N;
	double sum_sq_diff = 0;
	
	for(int i = 0; i < N; i++)
	{
		sum_sq_diff += pow(arr[i] - media, 2);   // pow trovato in cppreference
	}
	double dev_std = sqrt(sum_sq_diff/N);
	
	cout << "Minimo: " << min_val << "\n";
	cout << "Massimo: " << max_val << "\n";
	cout << "Media: " << media << "\n";
	cout << "Deviazione Standard: " << dev_std << "\n";
	
	
	// Bubblesort
	bool scambiato = true;
	while(scambiato)
	{
		scambiato = false;
		for(int i = 0; i < N-1; i++)
		{
			if(arr[i] > arr[i+1])
			{
				double temp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = temp;
				scambiato = true;
			}
		}
	}
	
	cout << "Array ordinato:" << "\n";
	for(int i = 0; i < N; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
	
	return 0;
}
