#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <string>
using namespace std;

/*
struct containing the cache hit rate and cache miss
penalty of a given computer
*/
struct Computer {
	double cacheHitR;
	int cacheMissP;
};

/*
Prototype for function that will compute how many
cycles a program with x% of the x instructions
being memory operations on a given computer
*/
int cycles(int&& instr, double&& mem, const Computer& c);

int main() {

	Computer a;
	a.cacheHitR = 0.95;
	a.cacheMissP = 6;

	Computer b;
	b.cacheHitR = 0.96;
	b.cacheMissP = 7;

	//testing computers with program 1
	cout << "Computer A, Program 1: " << cycles(1500, 0.25, a) << endl;
	cout << "Computer B, Program 1: " << cycles(1500, 0.25, b) << endl;

	//testing computers with program 2
	cout << "Computer A, Program 2: " << cycles(1500, 0.3, a) << endl;
	cout << "Computer B, Program 2: " << cycles(1500, 0.3, b) << endl;

	/*
	//testing computers with program 3
	cout << "Computer A, Program 3: " << cycles(2000, 0.6, a) << endl;
	cout << "Computer B, Program 3: " << cycles(2000, 0.6, b) << endl;

	//testing computers with program 4
	cout << "Computer A, Program 4: " << cycles(2000, 0.8, a) << endl;
	cout << "Computer B, Program 4: " << cycles(2000, 0.8, b) << endl;
	*/
}

int cycles(int&& instr, double&& mem, const Computer& c) {

	//used std::ceil to round up (as instructed on exam)
	int memOps = ceil(instr * mem);
	int non_memOps = instr - memOps;
	//used std::ceil to round up (as instructed on exam)
	int cacheHits = ceil(memOps * c.cacheHitR);
	int cacheMiss = memOps - cacheHits;
	//used std::ceil to round up (as instructed on exam)
	int cycles = ceil((non_memOps)+(memOps * 2)+(cacheMiss * c.cacheMissP));

	return cycles;
}
