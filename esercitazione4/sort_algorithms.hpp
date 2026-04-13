#include <vector>
#include <algorithm>     // per swap 

template <typename T>
bool is_sorted(const std::vector<T>& vec) {
	if (vec.size() < 2) 
	{
		return true;
	}
	for (size_t i = 0; i < vec.size() - 1; i++) 
	{
		if (vec[i] > vec[i + 1]) 
		{ 
			return false;
		}
	}
	return true;
}


template <typename T>
void bubble_sort(std::vector<T>& A) {
	size_t n = A.size();
	if (n < 2)
	{
		return;
	}
	for (size_t i = 0; i < n - 1; i++) 
	{
		for (size_t j = n - 1; j > i; j--) 
		{
			if (A[j] < A[j - 1])
			{
				std::swap(A[j], A[j - 1]);
			}
		}
	}
}


template <typename T>
void insertion_sort(std::vector<T>& A) {
	if (A.size() < 2)
	{
		return;
	}
	for (size_t j = 1; j < A.size(); j++)
	{
		T key = A[j];
		int i = static_cast<int>(j) - 1;      // trovato su internet: static_cast trasforma j da size_t a int (altrimenti mi da warning)
		while (i >= 0 && A[i] > key)
		{
			A[i + 1] = A[i];
			i--;
		}
		A[i + 1] = key;
	}
}


template <typename T>
void selection_sort(std::vector<T>& A) {
	if (A.size() < 2) 
	{
		return;
	}
	for (size_t i = 0; i < A.size() - 1; i++) 
	{
		size_t min_idx = i;
		for (size_t j = i + 1; j < A.size(); j++)
		{
			if (A[j] < A[min_idx]) 
			{
				min_idx = j;
			}
		}
		std::swap(A[i], A[min_idx]);
	}
}