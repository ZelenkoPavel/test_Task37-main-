#include <iostream>

using namespace std;

#define size 100

void random_init_matrix(int matrix[size][size], int max, int min,
	int classes, int students);
string convert_matrix_to_string(int matrix[size][size], int classes, int students);

string choosing_an_action(int matrix[size][size], int classes, int students, int choice);

int main() {
	int max = 10, min = 0;

	int classes, students;

	int matrix[size][size];


	do {
		system("cls");
		cout << "Input the number of students in the classes" <<
			"and the number of classes: ";
		cin >> students >> classes;
	} while (students <= 0 || students > size ||
		classes <= 0 || classes > size);

	random_init_matrix(matrix, max, min, classes, students);


	while (true) {
		cout << convert_matrix_to_string(matrix, classes, students) << endl;

		int choice;
		cout << "What do you want to do?\n" <<
			"1.Finding the max group highest marks;\n" <<
			"2.Finding group lowest marks;\n" <<
			"3.Increase grades by one point for students in\n" <<
			"groups with the highest average performance;\n" <<
			"4.sorting groups by average performance;\n" <<
			"0.Exit." << endl;
		cin >> choice;

		system("cls");

		cout << choosing_an_action(matrix, classes, students, choice) << endl;

		int answer;
		do {
			cout << "Want to continue? (1.Yes or 0.No): ";
			cin >> answer;
		} while (answer < 0 || answer > 2);

		if (answer == 0) {
			break;
		}

		system("cls");
	}

	return 0;
}