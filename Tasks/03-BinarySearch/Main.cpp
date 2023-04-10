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

bool BinarySearch(const int* list, const size_t size, const int value)
{
	if (size == 0)
		return false;

	const size_t half = size / 2;
	const int num = list[half];

	if (num == value)
		return true;
	
	else if (size == 1)
		return false;

	else if (num > value)
		return BinarySearch(list, half, value);
	
	else
		return BinarySearch(list + half + 1, size % 2 ? half : (half - 1), value);
}
	
int main(int, char**)
{
	int* array;
	size_t len = FileToArray("binarysearchIn.txt", array);

	for (size_t i = 0; i < len; i++)
		cout << array[i] << ' ';
	cout << endl;

	int num;
	cin >> num;
	cout << (BinarySearch(array, len, num) ? "true" : "false") << endl;
}