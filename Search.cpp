#include <cstdio>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <stack>

///////////////////////////////////////////////////

template <typename T>
int LinearSearch(T* arr, int size, T val)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == val) return i;
	}
	return -1;
}


////////////////////////////////////////////////



template <typename T>
int BynarySearch(T* k, int size, T val)
{
	bool flag = false;
	int mid = 0;
	while ((left <= right) && (!flag))
	{
		mid = (left + right) / 2;
		if (k[mid] == value)
			flag = true;
		else if (k[mid] > value)
			right = mid - 1;
		else
			left = mid + 1;
	}
	if (flag) return mid;
	return -1;
}


/////////////////////////////////////////////////////////


template <typename T>
int FibSearch(T* k, int size, T value)
{
	int fibM1 = 1;
	int fibM2 = 0;
	int fibM = fibM1 + fibM2;
	while (fibM < size)
	{
		fibM2 = fibM1;
		fibM1 = fibM;
		fibM = fibM1 + fibM2;
	}
	int change = -1;
	while (fibM > 1)
	{
		int i = std::min(change + fibM2, size - 1);
		if (k[i] < value)
		{
			fibM = fibM1;
			fibM1 = fibM2;
			fibM2 = fibM - fibM1;
			change = i;
		}
		else if (k[i] > value)
		{
			fibM = fibM2;
			fibM1 = fibM1 - fibM2;
			fibM2 = fibM - fibM1;
		}
		else
			return i;
	}
	if (fibM1 && k[change + 1] == value)
	{
		return change + 1;
	}
	return -1;
}

//////////////////////////////////////////////////////////////////


template <typename T>
int InterpolSearch(T* k, int left, int right, T value)
{
	bool mean;
	int mid = 0;
	if (k[left] == value) return left;
	if (k[right] == value) return right;
	for (mean = false; (k[left] <= value) && (k[right] >= value) && (!mean);)
	{
		mid = left + (((value - k[left]) * (right - left)) / (k[right] - k[left]));
		if (k[mid] < value)
			left = mid + 1;
		else if (k[mid] > value)
			right = mid - 1;
		else
			mean = true;
	}
	if (mean)
		return mid;
	else
		return -1;
}

//////////////////////////////////////////////////////////////////


template <typename T>
int IndexSearch(T* k, int size, T value, int m)
{
	int s = (size - 1) / m + 1;
	T* kindex = new T[s];
	int* pindex = new int[s];
	int i, j;
	for (j = 0; j < s; j++)
	{
		pindex[j] = (j + 1) * m - 1;
		kindex[j] = k[pindex[j]];
	}
	for (j = 0; j < s; j++)
	{
		if (value <= kindex[j])
			break;
	}
	if (j == 0)
		i = 0;
	else
		i = pindex[j - 1];
	for (; i <= pindex[j]; i++)
	{
		if (k[i] == value) {
			delete[] kindex, pindex;
			return i;
		}
	}
	delete[] kindex, pindex;
	return -1;
}
