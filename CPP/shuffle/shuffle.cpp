#include <iostream>
#include <vector>
#include <time.h>


// Prints the array to stdout
void printArray(const std::vector<int> &array);

// Shuffles the array
std::vector<int> shuffle(const std::vector<int> &array);


int main(int argc, char **argv)
{
	// Set random seed
	srand(time(NULL));

	std::cout << "Please enter the number of terms in the array :\n> ";

	// Get the length of the array by user input
	size_t arrayLength;
	std::cin >> arrayLength;

	// Create the array
	std::vector<int> array;
	array.reserve(arrayLength);

	// Set all values
	for (size_t i = 0U; i < arrayLength; ++i)
	{
		std::cout << "Term " << i << " : ";

		// User input
		int term;
		std::cin >> term;

		array.emplace_back(term);
	}

	// Print the array
	std::cout << "Array : ";
	printArray(array);

	// Shuffle
	array = shuffle(array);

	// Print the new array
	std::cout << "New array : ";
	printArray(array);
}

void printArray(const std::vector<int> &array)
{
	// Print empty array
	if (array.empty())
	{
		std::cout << "[]\n";
		return;
	}

	// First term
	std::cout << "[" << array[0];

	// Display each term
	for (size_t i = 1U; i < array.size(); ++i)
		std::cout << ", " << array[i];

	// End
	std::cout << "]\n";
}

// Swaps two elements of an array by their index
inline void swap(std::vector<int> &array, const size_t FIRST, const size_t SECOND)
{
	const int TMP = array[FIRST];
	array[FIRST] = array[SECOND];
	array[SECOND] = TMP;
}

/*
	Algorithm (Fisher Yates):
- For each term from the last to the first
- Swap it with a term before it randomly
*/
std::vector<int> shuffle(const std::vector<int> &array)
{
	// New array
	std::vector<int> values = array;
	
	// Swap values
	for (int i = array.size() - 1; i >= 0; --i)
		swap(values, rand() % (i + 1), i);

	return values;
}

