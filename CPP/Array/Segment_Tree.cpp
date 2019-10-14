// for objects cin, cout and function min
#include <iostream>

// for assertions
#include <cassert>

// N stores size of input array A
#define N 5

// input array
int A[N] = {5, 4, 3, 2, 1};

/*
Segment tree:
                     0-4
                      1
                   /     \
                0-2       3-4
                 3         1
               /   \     /   \
             0-1   2-2 3-3   4-4
              4     3   2     1
            /   \
         0-0    1-1
          5      4

Representation:

The array represents the above tree,
by storing the left child at index
(present_index + 1) * 2 - 1
and right child at
(present_index + 1) * 2.
       __ __ __ __ __ __ __ __ __ __ __ __ __ __ __
id:   | 0| 1| 2| 3| 4| 5| 6| 7| 8| 9|10|11|12|13|14|
      |__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|
data: | 1| 3| 1| 4| 3| 2| 1| 5| 4| X| X| X| X| X| X|
      |__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|

Let's consider that A is of size N.

As we can see, the leaf nodes
contain the array elements,
the number of leaf nodes is N.

What's the maximum size
of the segment tree?

We consider the case where
the last level contains
at least one of the leaf nodes.
Then the tree would have the
below distribution of nodes:

level | number of nodes
0     | 2 ^ 0
1     | 2 ^ 1
2     | 2 ^ 2
.     | .
.     | .
.     | .
n     | 2 ^ n

(where, 2 ^ n is
the lowest power of 2
greater than
or equal to N)

So, the size is the sum of the G.P.:

≈ pow(2, ceil(log2(N)) + 1) - 1
≈ pow(2, ceil(log2(N)) + 1)
≈ pow(2, log2(N) + 2)
≈ pow(2, log2(N)) x pow(2, 2)
≈ N x 4
≈ 4N
*/

int segment_tree[4 * N];

/* to create segment tree for
elements in range A[left ... right] */
void create_tree (int id, int left, int right) {
	/* id : value of index that
	stores value of min. element
	in A[left ... right] */
	if (left < right) {
		
		// stores index of right biased mid
		int mid = (left + right) / 2;

		// left subtree id : 2 x (id + 1) - 1
		int left_id = 2 * (id + 1) - 1;
		// right subtree id : 2 x (id + 1)
		int right_id = 2 * (id + 1);

		// call for constructing left subtree
		create_tree(left_id, left, mid);
		// call for constructing right subtree
		create_tree(right_id, mid + 1, right);

		/* now that the left subtree
		and the right subtree are
		created, the corresponding
		indices store the minimum
		value in the range specified */
		segment_tree[id] = std::min(
			segment_tree[left_id],
			segment_tree[right_id]
		);

	} else if (left == right) {
		// only one element
		segment_tree[id] = A[left];
	}
}


/* to return the minimum element
in range A[segment_left ... segment_right]
by recursively traversing the tree */
int find_minimum_in_range (
	int id,
	int query_left, int query_right,
	int segment_left, int segment_right) {

	// to store result
	int minimum;
	
	/* Case 1: query is out of range */
	/*
	QL ... QR | SL ... SR
	OR
	SL ... SR | QL ... QR
	*/
	if (
		query_right < segment_left
		or
		query_left > segment_right
	) {
		// high value to signify invalidity
		minimum = 0x7FFFFFFF;
	}

	/* Case 2: segment range is
	completely inside query range */
	/*
	QL ... SL ... SR ... QR
	*/
	else if (
		query_right >= segment_right
		and
		query_left <= segment_left
	) {
		// value at current index
		minimum = segment_tree[id];
	}

	/* Case 3: one bound of
	query is in segment range */
	/*
	QL ... SL ... QR ... SR
	OR
	SL ... QL ... SR ... QR
	*/
	else {
		// stores index of right biased mid
		int mid = (segment_left + segment_right) / 2;

		// left subtree id : 2 x (id + 1) - 1
		int left_id = 2 * (id + 1) - 1;
		// right subtree id : 2 x (id + 1)
		int right_id = 2 * (id + 1);

		// call for finding minimum of left subtree
		int minimum_of_left_subtree = find_minimum_in_range(
			left_id,
			query_left, query_right,
			segment_left, mid
		);
		// call for finding minimum of right subtree
		int minimum_of_right_subtree = find_minimum_in_range(
			right_id,
			query_left, query_right,
			mid + 1, segment_right
		);

		/* now that the minimum of
		left subtree and right subtree
		are found, the corresponding
		value of the present range will
		be the minimum of both */
		minimum = std::min(
			minimum_of_left_subtree,
			minimum_of_right_subtree
		);
	}
	return minimum;
}

/* simply uses a linear strategy to detect
least element in range A[left ... right] */
int solve_brute_force (int left, int right) {
	int temp_minimum = A[left];
	for (int i = left + 1; i <= right; ++i)
		if (A[i] < temp_minimum)
			temp_minimum = A[i];
	return temp_minimum;
}

/* generates test cases by querying
all possible valid ranges and
compares the results returned by 
the segment tree with the solutions
returned by the brute force solution */
bool validate (void ) {

	#ifdef DEBUG
		// Display A[]
		std::cout << "A[]:" << std::endl;
		for (int i = 0; i < N; ++i)
			std::cout << A[i] << " ";
		std::cout << std::endl << std::endl;
		// Display segment_tree[]
		std::cout << "segment_tree[]:" << std::endl;
		for (int i = 0; i < 4 * N; ++i)
			std::cout << segment_tree[i] << " ";
		std::cout << std::endl << std::endl;
		// header for query comparison table
		std::cout
			<< "[l, r]\t|\tbrute_force\t|\tsegment_tree"
			<< std::endl;
	#endif

	// lower bound
	for (int i = 0; i < N; ++i) {
		// upper bound
		for (int j = i; j < N; ++j) {
			int temp_minimum_brute_force =
				solve_brute_force(i, j);
			
			int temp_minimum_segment_tree =
				find_minimum_in_range(0, i, j, 0, N - 1);

			#ifdef DEBUG
				// Displaying each result
				std::cout
					<< "[" << i << ", " << j << "]\t|\t"
					<< temp_minimum_brute_force << "\t\t|\t"
					<< temp_minimum_segment_tree << std::endl;
			#endif
			
			if (temp_minimum_brute_force != temp_minimum_segment_tree)
				return false;
		}
	}
	// all results matched
	return true;
}

int main (void ) {
	create_tree(0, 0, N - 1);
	assert(validate()); // crashes program if incorrect
	return 0;
}
