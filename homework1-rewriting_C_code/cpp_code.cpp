// Purpose: calculate the sum of the first N-1 numbers
// author: Jeronimo Agullo


#include <iostream>
#include <vector>

// The N-1 number to calculate its sum
const int N = 6;

using namespace std;

// @param p holds the sum of the vector
// @param d the vector which contains the values to sum
template <class sumType>
inline void sum(sumType& p, vector<sumType> d){
	// assure that the sum variable starts with zero value
	p = 0;
	// sum the vector data
	for (int i = 0; i < d.size(); ++i)
		p = p + d[i];
}

int main(){
	// variable to hold the sum
	float accum = 0;
	// vector which contains the data to sum
	vector<float> data(N);

	// inizialize the vector
	for (int i = 0; i < N; ++i)
		data[i] = i;

	// calculate the sum of vector values
	sum(accum, data);

	cout << "sum is: " << accum << endl;

	return 0;
}