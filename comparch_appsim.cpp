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
	a.cacheMissP = 10;

	Computer b;
	b.cacheHitR = 0.92;
	b.cacheMissP = 8;

	//testing computers with program 1
	cout << "Computer A, Program 1: " << cycles(2000, 0.2, a) << endl;
	cout << "Computer B, Program 1: " << cycles(2000, 0.2, b) << endl;

	//testing computers with program 2
	cout << "Computer A, Program 2: " << cycles(2000, 0.4, a) << endl;
	cout << "Computer B, Program 2: " << cycles(2000, 0.4, b) << endl;

	//testing computers with program 3
	cout << "Computer A, Program 3: " << cycles(2000, 0.6, a) << endl;
	cout << "Computer B, Program 3: " << cycles(2000, 0.6, b) << endl;

	//testing computers with program 4
	cout << "Computer A, Program 4: " << cycles(2000, 0.8, a) << endl;
	cout << "Computer B, Program 4: " << cycles(2000, 0.8, b) << endl;

}

int cycles(int&& instr, double&& mem, const Computer& c) {

	int memOps = instr * mem;
	int non_memOps = instr - memOps;
	int cacheHits = memOps * c.cacheHitR;
	int cacheMiss = memOps - cacheHits;
	int cycles = (non_memOps)+(memOps * 2)+(cacheMiss * c.cacheMissP);

	return cycles;
}
