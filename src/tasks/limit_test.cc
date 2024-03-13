#include <iostream>
#include <iomanip>
#include "tasks.h"

int main(int argc, char** argv) {
	double* checkpoints = new double;
//	t_task4* table;
//
	int j = 1;
	task4(checkpoints, 0, j);

	for (int i = 0; i < j; i++) 
		std::cout << std::left << " sum: " << checkpoints[i] << std::endl;
		
//	for (int i = 0; i < 6; i++) {
//		std::cout << std::left << "x: " << std::internal << table->x << std::internal << " ref: " << table->ref << " taylor: " << table->taylor << " last_n: " << table->last_n << std::endl;
//		table = table->prev;
//	}
}
