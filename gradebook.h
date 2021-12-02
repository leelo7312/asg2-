#pragma once


using namespace std;

class Student
{
private:

	string name;
	int test;
	double grade;

public:

	Student() : Student("", 0, 0)
	{

	}

	Student(string name, int test, double  average) : name(name), test(test), grade(grade)
	{

	}

	~Student() {}


	bool operator < (const Student& other) const
	{
		return (grade < other.grade);
	}

	void inputEditStudent()
	{
		cout << endl << "Editing " << name << ", Enter test # 4 " << endl;
		cin >> test >> endl;

	}

	void outputEmployee()
	{
		cout << name << "\t" <<
			test << right << setw(10)
			<< fixed << setprecision(2) << grade << endl;

	}

	string getName()
	{
		return name;
	}

	void setName(string nameIn)
	{
		name = nameIn;
	}

	double getaverage()
	{
		return grade;
	}

	void setAvereage(double averageIn)
	{
		grade = averageIn;
	}

	void setTest(int testIn)
	{
		test = testIn;
	}

	int getTest()
	{
		return test;
	}

};

class Gradebook
{
private:
	string studname;
	vector <Student> studentlist;
	vector<int> numberList;
	vector <double> studentlist;


	int findIndex(string& studName)
	{
		int index = 0;
		for (unsigned int i = 0; i < studentList.size(); i++)
		{
			if (studName == studentList[i].getName())
				return i;
		}
		return -1;
	}


public:

	studentlist(string& name) : name(name)
	{
	}

	void loadStudent()
	{
		string name;
		int test;
		double average;

		ifstream infile;
		infile.open("dataStudents.txt");
		while (infile >> name >> age >> salary)
		{
			Student oneStudent(name, test, grade);

		}

		infile.close();
	}

	void addStudent(Student& oneStudent)
	{
		studentList.push_back(oneStudent);
	}

	void editStudent(string& name)
	{
		for (Student& oneStudent : studentList)
		{
			if (oneStudent.getName() == name)
			{
				break;
			}
		}
	}

	void removeStudent(string studentName)
	{
		studentList.erase(studentList.begin() + findIndex(studentName));
	}

	void inputNumbers()
	{
		cout << endl;
		int index = 1;
		for (int& oneString : numberList)
		{
			cout << "Enter int # " << index++ << endl;
			cin >> oneString;
		}
	}

	void outputNumbers()
	{
		for (int& oneNumber : numberList)
			cout << oneNumber << setw(5);
	}

	void outputCompanyInformation()
	{
		sort(studentList.begin(), studentList.end()); //might need to reverse

		cout << endl << "Student: " << name << endl;
		cout << "Name\t" << "test" << right << setw(15) << "Grade" << endl;

		for (Student& oneStudent : studentList)
		{
			oneStudent.outputStudent();
		}

		cout << endl << "Avg" << setw(10) << getAverageTest() << right << setw(9)
			<< fixed << setprecision(2) << getAverageGrade() << endl;

		Student tempStudent = getHighestGradeStudent();
		cout << "Highest Grade: " << setw(10) << tempStudent.getName() << setw(10)
			<< fixed << setprecision(2) << tempStudent.getGrade() << endl;

	}

	Student getHighestGradeStudent()
	{
		Student highGradeStudent;
		double test = 0;
		for (Student& oneStudent : studentList)
		{
			if (oneStudent.getGrade() > grade)
			{
				test = oneStudent.getGrade();
				highGradeStudent = oneStudent;
			}
		}

		return highGradeStudent;
	}

	double getAverageTest()
	{
		double test = 0;
		for (Student& oneStudent : studentList)
		{
			test += oneStudent.getTest();
		}

		return avg / studentList.size();
	}

	double getAverageGrade()
	{
		double test = 0;
		for (Student& oneStudent : studentList)
		{
			test += oneStudent.getGrade();
		}

		return test / studentList.size();
	}



	string getName()
	{
		return name;
	}

	string setName(string nameIn)
	{
		this->name = nameIn;
	}

	vector<Student>& getStudent()
	{
		return studentList;
	}

};
