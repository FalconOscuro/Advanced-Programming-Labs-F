#include <iostream>
#include <fstream>
#include <limits>

using namespace std;

size_t FileToArray(const char filename[], int*& array)
{
	ifstream input(filename);
	if (!input)
		return 0;
	
	if (input.peek() == EOF)
		return 0;

	size_t len = 0;
	while (!input.eof())
	{
		input.ignore(numeric_limits<streamsize>::max(), '\n');
		len++;
	}

	input.seekg(0);
	array = new int[len];

	for (size_t i = 0; i < len; i++)
		input >> array[i];
	
	input.close();
	return len;
}

/**
 * @brief Recursive binary search
 * 
 * @param list Pointer to start of array
 * @param size Array length
 * @param value Value being searched
 * @return true if value found in array
 */
bool RecBinarySearch(const int* list, const size_t size, const int value)
{
	if (size == 0)
		return false;

	const size_t half = size / 2;
	const int num = list[half];

	if (num == value)
		return true;
	
	else if (size == 1)
		return false;

	// Each recursion, pass on a cut down version of the array
	// array pointer and size relate to currently searched portion of list
	else if (num > value)
		return RecBinarySearch(list, half, value);
	
	else
		return RecBinarySearch(list + half + 1, size % 2 ? half : (half - 1), value);
}

/**
 * @brief Iterative binary search
 * 
 * @param list Pointer to start of array
 * @param size Array length
 * @param value Value being searched
 * @return true if value found in array
 */
bool ItBinarySearch(const int* array, const size_t size, const int value)
{
	size_t width = size;
	size_t start = 0;

	while (true)
	{
		size_t half = width / 2;

		if (array[start + half] == value)
			return true;
		
		else if (width <= 1)
			return false;

		width--;
		width /= 2;

		if (array[start + half] < value)
			start += half + 1;
	}
}
	
int main()
{
	int* array;
	size_t len = FileToArray("binarysearchIn.txt", array);

	for (size_t i = 0; i < len; i++)
		cout << array[i] << ' ';
	cout << endl;

	int num;
	cin >> num;
	cout << (RecBinarySearch(array, len, num) ? "true" : "false") << endl;
	cout << (ItBinarySearch(array, len, num) ? "true" : "false") << endl;
}