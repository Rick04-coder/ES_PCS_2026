#include <vector>
#include <algorithm>     // per swap 
#include <limits>        // per l'inf

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


template <typename T>
void merge(std::vector<T>& A, int p, int q, int r) {
	int n1 = q - p + 1;
	int n2 = r - q;
	std::vector<T> L(n1 + 1);
	std::vector<T> R(n2 + 1);
	for (int i = 0; i < n1; i++) {
		L[i] = A[p + i];
	}
	for (int j = 0; j < n2; j++) {
		R[j] = A[q + 1 + j];
	}
	if constexpr (std::is_arithmetic_v<T>) {           // (Suggerito da AI) se T è aritmetico
 		L[n1] = std::numeric_limits<T>::max();         // imposta il valore massimo per il tipo T
		R[n2] = std::numeric_limits<T>::max();
	}
	else {
		L[n1] = "{";     // ho usato carattere '{' perché viene dopo la z in ASCII (simula inf per stringhe)
		R[n2] = "{"; 
	}
	int i = 0;
	int j = 0;
	for (int k = p; k <= r; k++) {
		if (L[i] <= R[j]) {
			A[k] = L[i];
			i = i + 1;
		}
		else {
			A[k] = R[j];
			j = j + 1;
		}
	}
}		


template <typename T>
void mergesort_ricorsivo(std::vector<T>& A, int p, int r) {
	if (p < r) {
		int q = p + (r - p) / 2;
		mergesort_ricorsivo(A, p, q);
		mergesort_ricorsivo(A, q + 1, r);
		merge(A, p, q, r);
	}
}


template <typename T>
void merge_sort(std::vector<T>& A) {
	if (A.size() > 1) {
		mergesort_ricorsivo(A, 0, static_cast<int>(A.size()) - 1);
	}
}


template <typename T>
int partition(std::vector<T>& A, int p, int r) {
	T x = A[r];
	int i = p - 1;
	for (int j = p; j < r; j++) {
		if (A[j] <= x) {
			i++;
			std::swap(A[i], A[j]);
		}
	}
	std::swap(A[i + 1], A[r]);
	return i + 1;
}


template <typename T>
void quicksort_ricorsivo(std::vector<T>& A, int p, int r) {
	if (p < r) {
		int q = partition(A, p, r);
		quicksort_ricorsivo(A, p, q - 1);
		quicksort_ricorsivo(A, q + 1, r);
	}
}


template <typename T>
void quick_sort(std::vector<T>& A) {
	if (A.size() > 1) {
		quicksort_ricorsivo(A, 0, static_cast<int>(A.size()) - 1);
	}
}


// ordina solo il pezzo da p a r
template <typename T>
void insertion_sort_range(std::vector<T>& A, int p, int r) {
    for (int j = p + 1; j <= r; j++) {
        T key = A[j];
        int i = j - 1;
        while (i >= p && A[i] > key) {
            A[i + 1] = A[i];
            i--;
        }
        A[i + 1] = key;
    }
}

template <typename T>
void quicksort_ricorsivo_mod(std::vector<T>& A, int p, int r) {
    const int SOGLIA = 36; 
    if (p < r) {
        int dimensione_segmento = r - p + 1;        
        if (dimensione_segmento <= SOGLIA) {
            // ordina solo il pezzetto da p a r
            insertion_sort_range(A, p, r); 
        } else {
            int q = partition(A, p, r); 
            quicksort_ricorsivo_mod(A, p, q - 1);
            quicksort_ricorsivo_mod(A, q + 1, r);
        }
    }
}

template <typename T>
void quick_sort_mod(std::vector<T>& A) {
    if (A.size() > 1) {
        quicksort_ricorsivo_mod(A, 0, static_cast<int>(A.size()) - 1);
    }
}
			
    
