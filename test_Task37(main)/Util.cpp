#include <iostream>
#include <string>
#include <ctime>

using namespace std;

#define size 100

string finding_the_max_group_highest_marks(int matrix[size][size], int classes, int students);
string finding_group_lowest_marks(int matrix[size][size], int classes, int students);
void groups_with_the_highest_average_performance(int matrix[size][size],
	int classes, int students);
void sorting_groups_by_average_performance(int matrix[size][size],
	int classes, int students);

void random_init_matrix(int matrix[size][size], int max, int min,
	int classes, int students) {
	srand(time(NULL));
	if (min > max) {
		int t = min;
		min = max;
		max = t;
	}
	for (int i = 0; i < classes; i++) {
		for (int j = 0; j < students; j++) {
			matrix[i][j] = rand() % (max - min + 1) + min;
		}
	}
}

string convert_matrix_to_string(int matrix[size][size], int classes, int students) {
	if (students <= 0 || students > size ||
		classes <= 0 || classes > size) {
		return "Incorrect data was entered";
	}

	string msg = "";

	for (int i = 0; i < classes; i++) {
		for (int j = 0; j < students; j++) {
			if (matrix[i][j] < 0) {
				msg += to_string(matrix[i][j]) + " ";
			}
			else if (matrix[i][j] >= 0 && matrix[i][j] < 10) {
				msg += " " + to_string(matrix[i][j]) + " ";
			}
			else {
				msg += to_string(matrix[i][j]) + " ";
			}
		}
		msg += "\n";
	}

	return msg;
}

string choosing_an_action(int matrix[size][size], int classes, int students, int choice) {
	if (students <= 0 || students > size ||
		classes <= 0 || classes > size ||
		choice < 0 || choice > 4) {
		return "Incorrect data was entered";
	}
	string result = "";

	result += convert_matrix_to_string(matrix, classes, students) + "\n \n";

	if (choice == 0) {
		return "";
	}
	else if (choice == 1) {
		result += finding_the_max_group_highest_marks(matrix, classes, students) + "\n";
	}
	//else if (choice == 2) {
	//	result += finding_group_lowest_marks(matrix, classes, students);
	//}
	else if (choice == 3) {
		groups_with_the_highest_average_performance(matrix, classes, students);

		result += convert_matrix_to_string(matrix, classes, students) + "\n";
	}
	else {
		sorting_groups_by_average_performance(matrix, classes, students);

		result += convert_matrix_to_string(matrix, classes, students) + "\n";
	}

	return result;
}