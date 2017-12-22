#include <iostream>
#include <vector>

#define SUBJECT_NUM 3
#define STUDENT_NUM 2

using namespace std;

// Sutdent info.
struct Student {
	int id;
	vector<int> score;
	int sum = 0;
	double average;

};

Student get_dataTo_Student(int, vector<int>, int, double);
Student make_Student();

int main() {



	vector<Student> students;


	/* Start of Inputing data.. */

	for (int i = 0; i < STUDENT_NUM; i++) {
		students.push_back(make_Student());
	}
	/* End of Inputing data.. */




	/* Start of Printing Result.. */
	
	for (int i = 0; i < students.size(); i++) {
		
		cout << "학번" << students[i].id << endl;
		for (int j = 0; j < SUBJECT_NUM; j++) {
			cout << j + 1 << "번째 과목 점수: " << students[i].score[j] << endl;
		}

		cout << "총점: " << students[i].sum << endl;
		cout << "평균: " << students[i].average << endl;
		cout << endl;
	}
	cout << endl;

}

Student get_dataTo_Student(int id, vector<int> score, int sum, double average) {
	Student temp;

	// Entering datas...
	temp.id = id;
	temp.score = score;
	temp.sum = sum;
	temp.average = average;

	return temp;

}

Student make_Student() {
	int id;
	vector<int> score;
	int sum = 0;
	double average;

	// Entering datas...
	cout << "학번 입력 >> ";
	cin >> id;

	int num; // temp number of score

	for (int i = 0; i < SUBJECT_NUM; i++) {
		cout << i + 1 << "번째 과목의 점수 입력 >> ";
		cin >> num;
		score.push_back(num);
		sum += num;

	}
	cout << endl;

	// Computing average of score...
	average = sum / score.size();

	Student temp = get_dataTo_Student(id, score, sum, average);

	return temp;
}