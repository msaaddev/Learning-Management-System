#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
using namespace std;

// this function will check whether credit hours are between 0 to 3 or not
bool isValidCreditHours(int credit_hours)
{
	bool var1 = false;
	if (credit_hours > 0 && credit_hours <= 3)
	{
		var1 = true;
	}
	return var1;
}

// this function will check whether course code is valid or not
bool isValidCourseCode(char course_code[])
{
	bool values1 = 0, values2 = 0;
	for (char i = 'A'; i <= 'Z'; i++)
	{
		if (course_code[0] == i)
		{
			values1 = 1;
		}
	}
	for (char j = 'A'; j <= 'Z'; j++)
	{
		if (course_code[1] == j)
		{
			values2 = 1;
		}
	}
	bool value = 0, value2 = 0, value3 = 0;
	for (char b = '0'; b <= '9'; b++)
	{
		if (course_code[2] == b)
		{
			value = 1;
		}
	}
	for (char c = '0'; c <= '9'; c++)
	{
		if (course_code[3] == c)
		{
			value2 = 1;
		}
	}
	for (char d = '0'; d <= '9'; d++)
	{
		if (course_code[4] == d)
		{
			value3 = 1;
		}
	}
	if (values1 == 1 && values2 == 1 && value == 1 && value2 == 1 && value3 == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

// this function will check whether semester is between 0 to 8 or not
bool isValidSemester(int semester)
{
	bool var = false;
	if (semester > 0 && semester <= 8)
	{
		var = true;
	}
	return var;
}

// this function will check whether course name is valid or not
bool isValidCourseName(char course_name[])
{
	bool value = true;
	int x = 0;
	while (course_name[x] != '\0')
	{
		for (char y = '0'; y <= '9'; y++)
		{
			if (course_name[x] == y)
			{
				value = false;
			}
		}
		x++;
	}
	return value;
}

//this function will calculate max index of integar array semList
int max_index(int semList[])
{
	int a = 0, counter = 0;
	while (semList[a] != 0)
	{
		counter++;
		a++;
	}
	return --counter;
}

//this function will calculate the max index of string array
int max_index_regNo(string stdRegNoList[])
{
	int a = 0, counter = 0;
	while (stdRegNoList[a] != "\0")
	{
		counter++;
		a++;
	}
	return --counter;
}

//this statement will declare edit_course and delete course for the whole program
string edit_course_code;
int flag = 0, counter = 0, counter2, flag2 = 0, counter3, flag3 = 0, counter4, check_1 = 0;
int var;
// this function will add course name, credit hours, semester and course code to nameList, crtHrsList, semList, codeList respectively
void AddCourse(string codeList[], string nameList[], int crtHrsList[], int semList[], char course_code[], int credit_hours, int semester, char course_name[])
{

	static int n = var + 1;
	static int c = 0;
	int b = 0;

	if (isValidSemester(semester) == 1 && isValidCourseCode(course_code) == 1 && isValidCreditHours(credit_hours) == 1 && isValidCourseName(course_name) == 1)
	{
		static int a = counter;
		if (flag == 1)
		{
			// when a course is deleted, addCourse function will use this logic to add course details
			b = counter;
			codeList[b] = course_code;
			crtHrsList[b] = credit_hours;
			semList[b] = semester;
			nameList[b] = course_name;
			cout << "\nCourse has been added successfully" << endl;
			b++;
			flag = 2;
		}
		else if (var != 0)
		{
			if (flag == 2)
			{
				n = a + 1;
				flag = 0;
			}
			//when there are already courses in an external file, addCourse function will use this logic to add new courses
			codeList[n] = course_code;
			crtHrsList[n] = credit_hours;
			semList[n] = semester;
			nameList[n] = course_name;
			cout << "\nCourse has been added successfully" << endl;
			n++;
		}
		else
		{
			//when there are no courses in the external file, addCourse function will use this logic to add new courses
			if (flag == 2)
			{
				c = counter + 1;
				flag = 0;
			}

			codeList[c] = course_code;
			crtHrsList[c] = credit_hours;
			semList[c] = semester;
			nameList[c] = course_name;
			cout << "\nCourse has been added successfully" << endl;
			c++;
		}
	}
	if (var == 0)
	{
		counter2 = c;
		check_1 = 1;
	}
	else
	{
		counter2 = n;
		check_1 = 1;
	}
	if (flag == 2)
	{
		counter2 = b;
		check_1 = 1;
	}
	ofstream counter;
	counter.open("AddCourse_Counter.txt");
	counter << counter2 - 1;
	counter.close();
}

//this function will check whether the course code which we want to edit is in the program.
int check_course_code(string codeList[], string edit_course_code)
{
	bool value = 0;
	for (int x = 0; x < 100; x++)
	{
		if (codeList[x] == edit_course_code)
		{
			value = 1;
			break;
		}
	}
	return value;
}

//this function will return the index where details of the course are placed
int index_course_code(string codeList[], string edit_course_code)
{
	int index = -1;
	for (int x = 0; x < 100; x++)
	{
		if (codeList[x] == edit_course_code)
		{
			index = x;
			break;
		}
	}
	return index;
}

//this function will return the index where details of the registration number are placed
int index_reg_code(string stdRegNoList[], string edit_reNo)
{
	int index = -1;
	for (int x = 0; x < 100; x++)
	{
		if (stdRegNoList[x] == edit_reNo)
		{
			index = x;
			break;
		}
	}
	return index;
}

//this function will return the index where registration number of the student is stored in 2D array
int index_stdCourseList(string stdCourseList[][100], string reg_No)
{
	int index = -1;
	for (int x = 0; x < 100; x++)
	{
		if (stdCourseList[x][0] == reg_No)
		{
			index = x;
			break;
		}
	}
	return index;
}

//this function will return us the index where the course is stored which we want to delete
int index_delete_code(string codeList[], string delete_course_code)
{
	int index;
	for (int x = 0; x < 100; x++)
	{
		if (codeList[x] == delete_course_code)
		{
			index = x;
			break;
		}
	}
	return index;
}

//this function will return us the max index of the row of the 2D array
int index_row(string stdCourseList[][100], string reg_No)
{
	int x = 1, counter = 1;
	int variable = index_stdCourseList(stdCourseList, reg_No);
	while (stdCourseList[variable][x] != "\0")
	{
		counter++;
		x++;
	}
	return counter;
}

//this function will replace a course of the specified course code with another course detail
void EditCourse(string codeList[], string nameList[], int crtHrsList[], int semList[], char course_code[], int credit_hours, int semester, char course_name[])
{
	cout << "Enter the new details of the course: ";
	cin >> course_code >> credit_hours >> semester;
	cin.get(course_name, 100);

	if (isValidSemester(semester) == 1 && isValidCourseCode(course_code) == 1 && isValidCreditHours(credit_hours) == 1 && isValidCourseName(course_name) == 1)
	{
		int n = index_course_code(codeList, edit_course_code);
		codeList[n] = course_code;
		crtHrsList[n] = credit_hours;
		semList[n] = semester;
		nameList[n] = course_name;
		cout << "\nCourse has been edited successfully.\n";
	}
	else
	{
		cout << endl
			 << "Invalid Course Details" << endl;
	}
}

//this function  will delete a course according to the course code which is given by the user
void DeleteCourse(string codeList[], string nameList[], int crtHrsList[], int semList[], string delete_course_code)
{

	int n = index_delete_code(codeList, delete_course_code);
	int m = max_index(semList);
	for (int x = n; x <= m; x++)
	{
		codeList[x] = codeList[x + 1];
		nameList[x] = nameList[x + 1];
		crtHrsList[x] = crtHrsList[x + 1];
		semList[x] = semList[x + 1];
	}

	codeList[m] = '\0';
	nameList[m] = '\0';
	crtHrsList[m] = '\0';
	semList[m] = '\0';
	flag = 1;
	counter = m;

	cout << endl
		 << "Course has been deleted successfully" << endl;
}

int max_index_2(int crtHrsList[])
{
	int a = 0, counter = 0;
	while (crtHrsList[a] != 0)
	{
		counter++;
		a++;
	}
	return counter;
}

// this function will display all the courses of a specific semester
void ViewSemesterCourse(string codeList[], string nameList[], int crtHrsList[], int semList[], int semester)
{
	int size = max_index(semList);
	cout << "Enter the semester of which you want to display course: ";
	cin >> semester;
	cout << endl;
	cout << left;

	cout << setw(15) << "\tCourse Code" << setw(30) << "Name" << setw(20) << "Credit Hours" << endl;
	int index, x = 0;

	while (semList[x] != 0)
	{
		if (semList[x] == semester)
		{
			cout << "\t" << setw(13) << codeList[x] << setw(31) << nameList[x] << setw(20) << crtHrsList[x] << endl;
		}
		x++;
	}
}

//this function will save all the added courses in the file when we exit the program
bool saveCourses(string codeList[], string nameList[], int crtHrsList[], int semList[], int semester)
{
	bool value = 0;
	ofstream outData;
	outData.open("Courses.txt");
	int size = max_index(semList);

	for (int x = 0; x <= size; x++)
	{
		outData << codeList[x] << "," << nameList[x] << "," << crtHrsList[x] << "," << semList[x] << endl;
		value = 1;
	}
	outData.close();
	return value;
}

//this function will load courses in memory when program is being loaded
bool loadCourses(string codeList[], string nameList[], int crtHrsList[], int semList[])
{
	ifstream check, op;
	check.open("check_for_loadCourses.txt");
	int a, value1 = 0;
	check >> a;
	check.close();

	op.open("AddCourse_Counter.txt");
	int var;
	op >> var;
	op.close();

	if (a == 1)
	{
		value1 = 1;
	}

	int x = 0, y = 0, creditHour, Semester, counter = 0;
	string data;

	ifstream inData;
	inData.open("Courses.txt");

	while (value1 == 1)
	{
		char courseCode[6] = {'\0'}, courseName[50] = {'\0'};
		getline(inData, data);
		while (data[x] != ',')
		{
			courseCode[y] = data[x];
			y++;
			x++;
		}

		codeList[counter] = courseCode;

		x++;
		y = 0;
		while (data[x] != ',')
		{
			courseName[y] = data[x];
			x++;
			y++;
		}

		nameList[counter] = courseName;

		x++;

		while (data[x] != ',')
		{
			char conversion;
			conversion = data[x];
			creditHour = conversion - 48;
			break;
		}
		crtHrsList[counter] = creditHour;

		x += 2;

		while (data[x] != '\0')
		{
			char con;
			con = data[x];
			Semester = con - 48;
			break;
		}

		x++;
		semList[counter] = Semester;

		x = 0;
		y = 0;
		counter++;

		if (counter > var)
		{
			break;
		}
	}

	inData.close();

	if (a == 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

//this function will display all the courses ,which are added, on console
void ViewCourses(string codeList[], string nameList[], int crtHrsList[], int semList[])
{
	int size;

	size = max_index(semList);

	cout << left;
	cout << setw(15) << "\tCourse Code" << setw(30) << "Name" << setw(20) << "Credit Hours" << setw(20) << "Semester" << endl;

	for (int i = 0; i <= size; i++)
	{
		cout << left;
		cout << "\t" << setw(13) << codeList[i] << setw(31) << nameList[i] << setw(20) << crtHrsList[i] << setw(20) << semList[i] << endl;
	}
}

//this function will check whether the inputed credentials are true or not
bool loadUsers(char usersList[], char passwordsList[])
{
	ifstream users;
	bool value = 0, value2 = 0;
	char username[200] = {'\0'}, password[200] = {'\0'};
	int x = 0;
	string user;

	cout << "Username: ";
	cin >> username;
	cout << "Password: ";
	cin >> password;
	users.open("Users.txt");

	while (value == 0 && value2 == 0)
	{

		getline(users, user);

		while (user[x] != ',')
		{

			if (user[x] == username[x])
			{
				value = 1;
			}
			else
			{
				value = 0;
				break;
			}
			x++;
		}

		if (username[x] != '\0')
		{
			value = 0;
		}

		x++;
		int y = 0;

		while (user[x] != '\0')
		{
			if (user[x] == password[y])
			{
				value2 = 1;
			}
			else
			{
				value2 = 0;
				break;
			}
			x++;
			y++;
		}

		if (password[y] != '\0')
		{
			value2 = 0;
		}

		if (value == 1 && value2 == 1)
		{
			break;
		}
		if (user[x] == '\0')
		{
			break;
		}
	}

	users.close();
	if (value == 1 && value2 == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//this function will check whether the entered registratoon number is valid or not
bool isValidRegistrationNumber(char regNo[])
{
	bool value = 1, value2 = 0, value3 = 0, value4 = 0, value5 = 0, value6 = 0;

	if (regNo[0] == '2' && regNo[1] == '0' && regNo[2] == '1' && regNo[4] == '-' && regNo[7] == '-' && regNo[11] == '\0')
	{

		for (char i = '0'; i < '9'; i++)
		{
			if (regNo[3] != i)
			{
				value = 0;
			}
			else
			{
				value = 1;
				break;
			}
		}

		for (char i = 'A'; i < 'Z'; i++)
		{
			if (regNo[5] == i)
			{
				value2 = 1;
			}
		}

		for (char i = 'A'; i < 'Z'; i++)
		{
			if (regNo[6] == i)
			{
				value3 = 1;
			}
		}

		for (char b = '0'; b <= '9'; b++)
		{
			if (regNo[8] == b)
			{
				value4 = 1;
			}
		}
		for (char c = '0'; c <= '9'; c++)
		{
			if (regNo[9] == c)
			{
				value5 = 1;
			}
		}
		for (char d = '0'; d <= '9'; d++)
		{
			if (regNo[10] == d)
			{
				value6 = 1;
			}
		}
	}
	else
	{
		value = 0;
	}

	if (value == 1 && value2 == 1 && value3 == 1 && value4 == 1 && value5 == 1 && value6 == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//this function checks whether the entered student name is valid or not
bool isValidStudentName(char studentName[])
{
	bool value = true;
	int x = 0;
	while (studentName[x] != '\0')
	{
		for (char y = '0'; y <= '9'; y++)
		{
			if (studentName[x] == y)
			{
				value = false;
			}
		}
		x++;
	}
	return value;
}

int var4, var6;
//this function will addstudent in an stdNameList
void addStudent(string stdNameList[], string stdRegNoList[], char studentName[], char regNo[])
{
	static int variable = 0;
	int a = counter3;
	int b = counter3;
	int an_flag = 0;
	static int n = var6;

	if (isValidRegistrationNumber(regNo) == 1 && isValidStudentName(studentName) == 1)
	{
		if (flag2 == 1)
		{
			//when a student is deleted, addStudent function will use this logic to add student

			stdNameList[a] = studentName;
			stdRegNoList[a] = regNo;
			cout << "\nStudent has been added successfully" << endl;
			a++;
			flag2 = 2;
		}
		else if (var6 != 0)
		{
			if (flag2 == 2)
			{
				n = counter3 + 1;
				flag2 = 0;
			}

			stdNameList[n] = studentName;
			stdRegNoList[n] = regNo;
			cout << endl
				 << stdNameList[n] << " " << stdRegNoList[n] << endl;
			n++;
			cout << "\nStudent has been added successfully" << endl;
		}
		else
		{
			//when we have to add students in the memory
			if (flag2 == 2)
			{
				variable = counter3 + 1;
				flag2 = 0;
			}

			stdNameList[variable] = studentName;
			stdRegNoList[variable] = regNo;
			cout << endl
				 << stdNameList[variable] << " " << stdRegNoList[variable] << endl;
			variable++;
			cout << "\nStudent has been added successfully" << endl;
		}
	}

	if (var6 != 0)
	{
		var4 = n;
		ofstream OUTDATA;
		OUTDATA.open("AddStudent_counter.txt");
		OUTDATA << n;
		OUTDATA.close();
	}
	else
	{
		var4 = variable;
		ofstream OUTDATA;
		OUTDATA.open("AddStudent_counter.txt");
		OUTDATA << variable;
		OUTDATA.close();
	}
}

string edit_reNo;

//this function will edit the student in the list
void updateStudent(string stdNameList[], string stdRegNoList[], char studentName[], char regNo[])
{
	if (isValidRegistrationNumber(regNo) == 1 && isValidStudentName(studentName) == 1)
	{
		int variable = index_reg_code(stdRegNoList, edit_reNo);
		stdNameList[variable] = studentName;
		stdRegNoList[variable] = regNo;
		cout << "\nStudent details have been edited successfully.\n";
	}
}

int var7;
//this function will register courses for the student
void registerCourse(string stdRegNoList[], string stdCourseList[][100], string codeList[], string reg_No, string courseCode)
{
	if (index_course_code(codeList, courseCode) == -1)
	{
		cout << "There is no course by this course code." << endl;
	}

	else
	{
		static int n = var7;
		cout << endl
			 << "value of n: " << n;

		//when we add courses in new student registration number in stdCourseList
		if (index_stdCourseList(stdCourseList, reg_No) == -1)
		{
			//this condition will be used to add courses in the index of deleted courses
			if (flag3)
			{
				stdCourseList[counter4][0] = reg_No;
				stdCourseList[counter4][1] = courseCode;
				flag3 = 0;
			}

			else
			{
				cout << "\nyo3\n";

				if (var7 != 0)
				{
					static int x = n;
					int y = 0;
					stdCourseList[x][y] = reg_No;
					y++;
					stdCourseList[x][y] = courseCode;
					x++;
				}
				else
				{
					static int x = 0;
					int y = 0;
					stdCourseList[x][y] = reg_No;
					y++;
					stdCourseList[x][y] = courseCode;
					x++;
				}
			}
		}
		else if (var7 != 0)
		{
			int variable = index_stdCourseList(stdCourseList, reg_No);
			if (variable != -1 && index_row(stdCourseList, reg_No) == 1)
			{
				cout << "\nyo\n";
				stdCourseList[variable][1] = courseCode;
			}
			else if (variable != -1 && index_row(stdCourseList, reg_No) != 1)
			{
				cout << "\nyo1\n";
				int y = index_row(stdCourseList, reg_No);
				stdCourseList[variable][y] = courseCode;
			}
			else
			{
				cout << "\nYO2\n";
				stdCourseList[n][0] = reg_No;
				stdCourseList[n][1] = courseCode;
				n++;
			}
		}
		//when we add courses in existing student registration number
		else
		{
			int variable = index_stdCourseList(stdCourseList, reg_No);
			int y = index_row(stdCourseList, reg_No);
			stdCourseList[variable][y] = courseCode;
		}

		cout << endl
			 << "Course has been registered for the student." << endl;
		cout << stdCourseList[0][0] << " " << stdCourseList[0][1] << " " << stdCourseList[0][2] << " " << stdCourseList[0][3] << endl;
		cout << stdCourseList[1][0] << " " << stdCourseList[1][1] << " " << stdCourseList[1][2] << " " << stdCourseList[1][3] << endl;
		cout << stdCourseList[2][0] << " " << stdCourseList[2][1] << " " << stdCourseList[2][2] << " " << stdCourseList[2][3] << endl;
		cout << stdCourseList[3][0] << " " << stdCourseList[3][1] << " " << stdCourseList[3][2] << " " << stdCourseList[3][3] << endl;
	}
}

//this function will delete the student from the studentlist
void deleteStudent(string stdNameList[], string stdRegNoList[], string stdCourseList[][100], string reg_no)
{
	int variable = index_reg_code(stdRegNoList, reg_no);
	int variable2 = max_index_regNo(stdRegNoList);

	for (int x = variable; x <= variable2; x++)
	{
		stdRegNoList[x] = stdRegNoList[x + 1];
		stdNameList[x] = stdNameList[x + 1];
	}
	stdRegNoList[variable2] = "\0";
	stdNameList[variable2] = "\0";
	flag2 = 1;
	counter3 = variable2;

	//this condition will delete student reg number and his/her registered courses from the stdCourseList
	if (index_stdCourseList(stdCourseList, reg_no) == -1)
	{
	}
	else
	{
		int variable3 = index_stdCourseList(stdCourseList, reg_no);
		int y = index_row(stdCourseList, reg_no);
		counter4 = variable3;

		for (int x = 0; stdCourseList[variable][x] != "\0"; x++)
		{
			stdCourseList[variable3][x] = "\0";
			flag3 = 1;
		}
	}

	cout << endl
		 << "Student has been deleted successfully" << endl;
}

//this function will unregister the course for the student
void unRegisterCourse(string stdRegNoList[], string stdCourseList[][100], string reg_no, string courseCode)
{
	int variable = index_reg_code(stdRegNoList, reg_no);
	bool value = 1;

	for (int i = 0; stdCourseList[variable][i] != "\0"; i++)
	{
		if (stdCourseList[variable][i] == courseCode)
		{
			stdCourseList[variable][i] = "\0";
			value = 1;
			break;
		}
		else
		{
			value = 0;
		}
	}
	if (value == 0)
	{
		cout << endl
			 << "There is no course registered for the student by this course code.\n";
	}
	else
	{
		cout << endl
			 << "Course has been unregistered successfully.\n";
	}
}

//this function will display all the registered students
void viewstudents(string stdRegNoList[], string stdNameList[])
{
	cout << left;
	cout << setw(30) << "\t Student Name"
		 << "Registration Number" << endl;
	for (int x = 0; stdRegNoList[x] != "\0"; x++)
	{
		cout << left;
		cout << "\t" << setw(29) << stdNameList[x] << stdRegNoList[x] << endl;
	}
}

//this function will return the index where details of the registration number are placed in 2D array
int index_cou_code(string stdCourseList[][100], string edit_reNo)
{
	int index = -1;
	for (int x = 0; x < 100; x++)
	{
		if (stdCourseList[x][0] == edit_reNo)
		{
			index = x;
			break;
		}
	}
	return index;
}

//this function will save students in an external file
void saveStudents(string stdRegNoList[], string stdNameList[], string stdCourseList[][100])
{
	ofstream outdata;
	outdata.open("Students.txt");
	for (int x = 0; stdRegNoList[x] != "\0"; x++)
	{
		string f = stdRegNoList[x];
		outdata << stdRegNoList[x] << "," << stdNameList[x] << endl;

		if (index_cou_code(stdCourseList, f) == -1)
		{
			outdata << endl;
		}
		else
		{
			int j = index_cou_code(stdCourseList, f);
			for (int i = 1; stdCourseList[j][i] != "\0"; i++)
			{
				outdata << stdCourseList[j][i];
				if (stdCourseList[j][i + 1] != "\0")
				{
					outdata << ",";
				}
			}
			outdata << endl;
		}
	}
	outdata.close();
}

//this function will load the students in the external file in the memory
void loadsStudents(string stdRegNoList[], string stdNameList[], string stdCourseList[][100])
{

	ifstream check, op;
	check.open("check_for_student.txt");
	int a, value1 = 0;
	check >> a;
	check.close();

	if (a == 1)
	{
		value1 = 1;
	}

	op.open("AddStudent_counter.txt");
	int var5;
	op >> var5;
	op.close();

	int x = 0, y = 0, counter = 0;
	string data;

	ifstream inData;
	inData.open("Students.txt");

	while (value1 == 1)
	{
		char stdregno[12] = {'\0'}, stdname[50] = {'\0'}, courses[6] = {'\0'};
		getline(inData, data);

		while (data[x] != ',')
		{
			stdregno[y] = data[x];
			y++;
			x++;
		}

		stdRegNoList[counter] = stdregno;
		x++;
		y = 0;

		while (data[x] != '\0')
		{
			stdname[y] = data[x];
			x++;
			y++;
		}

		stdNameList[counter] = stdname;
		stdCourseList[counter][0] = stdRegNoList[counter];

		cout << endl
			 << stdCourseList[counter][0] << endl;

		getline(inData, data);
		x = 0;
		y = 0;
		int j = 1;
		while (data[x] != '\0')
		{
			y = 0;
			while (data[x] != ',' && data[x + 1] != '\0')
			{
				courses[y] = data[x];
				x++;
				y++;
				if (data[x + 1] == '\0')
				{
					courses[y] = data[x];
				}
			}
			x++;
			stdCourseList[counter][j] = courses;
			cout << stdCourseList[counter][j] << " ";
			j++;
		}

		cout << endl
			 << "yO" << endl;

		cout << stdCourseList[0][0] << " " << stdCourseList[0][1] << " " << stdCourseList[0][2] << " " << stdCourseList[0][3] << endl;
		cout << stdCourseList[1][0] << " " << stdCourseList[1][1] << " " << stdCourseList[1][2] << " " << stdCourseList[1][3] << endl;
		cout << stdCourseList[2][0] << " " << stdCourseList[2][1] << " " << stdCourseList[2][2] << " " << stdCourseList[2][3] << endl;
		cout << stdCourseList[3][0] << " " << stdCourseList[3][1] << " " << stdCourseList[3][2] << " " << stdCourseList[3][3] << endl;

		x = 0;
		y = 0;
		counter++;

		if (counter == var5)
		{
			break;
		}
	}
	inData.close();
}

int main()
{

	int option, credit_hours, semester, check_user = 1, loop = 0, tab = 0;
	char course_code[6], course_name[50], usersList[1000] = {'\0'}, passwordsList[1000] = {'\0'}, studentName[100] = {'\0'};
	char regNo[12] = {'\0'};
	string delete_course_code, codeList[100], nameList[100], stdNameList[100], stdRegNoList[100] = {"\0"}, stdCourseList[100][100], reg_no, courseCode;
	int a = 1, crtHrsList[100], semList[100], c = 0, another_var;

	ifstream file;
	file.open("check_for_student.txt");
	file >> another_var;
	file.close();

	ifstream op;
	op.open("AddCourse_Counter.txt");
	op >> var;
	op.close();

	ifstream opi;
	opi.open("AddStudent_counter.txt");
	opi >> var6;
	opi.close();

	ifstream opid;
	opid.open("AddStudent_counter.txt");
	opid >> var7;
	opid.close();

	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			stdCourseList[i][j] = "\0";
		}
	}

	if (another_var)
	{
		loadsStudents(stdRegNoList, stdNameList, stdCourseList);
	}

	for (int x = 0; x < 100; x++)
	{
		semList[x] = 0;
		crtHrsList[x] = 0;
	}

	int load = loadCourses(codeList, nameList, crtHrsList, semList);
	if (load)
	{
		check_1 = 1;
	}

	while (loop == 0)
	{
		cout << "			    ** Welcome to University Learning Management System ** \n";
		cout << endl
			 << "Dear user, current software is intended for authorized users only. \nLogin to the system to get access";
		cout << endl;
		cout << endl;
		do
		{
			if (check_user == 0)
			{
				char dec;
				cout << "\nDear User, username/password is incorrect. Enter the username/password again \nto get access to the system" << endl
					 << endl;
				cout << "Do you want to end the program? Please enter 'Y' for yes and 'N' for no: ";
				cin >> dec;
				cout << endl;
				if (dec == 'Y')
				{
					return 0;
				}
			}
			a = 1;
			check_user = loadUsers(usersList, passwordsList);
		} while (check_user == 0);

		loop = check_user;

		system("CLS");
		cout << endl
			 << "You have successfully logged in in your LMS account." << endl;
		while (a)
		{
			if (flag2 == 1)
			{
				ofstream OUTDATA;
				OUTDATA.open("AddStudent_counter.txt");
				OUTDATA << var4 - 1;
				OUTDATA.close();
			}

			if (flag == 1)
			{
				ofstream counter;
				counter.open("AddCourse_Counter.txt");
				counter << counter2 - 2;
				counter.close();
			}

			cout << endl;
			cout << "Choose the following option: " << endl;
			cout << endl
				 << "1 	Add Course" << endl;
			cout << "2	Update Course" << endl;
			cout << "3	Delete Course" << endl;
			cout << "4 	View All Courses" << endl;
			cout << "5	View Courses of a Semester" << endl;
			cout << "6	Add Student" << endl;
			cout << "7	Update Student" << endl;
			cout << "8	Delete Student" << endl;
			cout << "9 	Register the course for student" << endl;
			cout << "10	Unregister the course for student" << endl;
			cout << "11	View All students" << endl;
			cout << "12	Logout of the system" << endl
				 << "13	Exit Program" << endl
				 << endl;

			cout << "Choose the option: ";
			cin >> option;
			cout << endl;

			if (cin.fail())
			{
				option = 13;
			}
			switch (option)
			{

			//Add courses
			case 1:
			{
				cout << "Enter the details of the course: ";
				cin >> course_code >> credit_hours >> semester;
				cin.get(course_name, 100);

				while (isValidCourseCode(course_code) == 0)
				{
					cout << endl
						 << "Invalid Course Code\n";
					cout << "Enter Course Code again: ";
					cin >> course_code;
				}
				while (isValidCreditHours(credit_hours) == 0)
				{
					cout << endl
						 << "Invalid Credit hours" << endl;
					cout << "Enter Credit hours again: ";
					cin >> credit_hours;
				}
				while (isValidSemester(semester) == 0)
				{
					cout << endl
						 << "Invalid Semester\n";
					cout << "Enter semester again: ";
					cin >> semester;
				}

				if (isValidCourseName(course_name) == 0)
				{
					cout << endl
						 << "Invalid Course Name\n";
				}

				AddCourse(codeList, nameList, crtHrsList, semList, course_code, credit_hours, semester, course_name);

				break;
			}

			//Edit Course
			case 2:
			{
				cout << "Enter the course code to edit: ";
				cin >> edit_course_code;
				cout << endl;
				if (check_course_code(codeList, edit_course_code) == 0)
				{
					cout << endl
						 << "This is no course by this course code";
				}
				else
				{

					EditCourse(codeList, nameList, crtHrsList, semList, course_code, credit_hours, semester, course_name);
				}

				break;
			}

			//Delete Course
			case 3:
			{
				cout << "Enter course code of the course which you want to delete: ";
				cin >> delete_course_code;

				if (check_course_code(codeList, delete_course_code) == 0)
				{
					cout << endl
						 << "This is no course by this course code";
				}
				else
				{

					DeleteCourse(codeList, nameList, crtHrsList, semList, delete_course_code);
				}
				break;
			}

			//View all courses
			case 4:
			{
				int size = max_index(semList);

				if (size == -1)
				{
					cout << endl
						 << "There is no course to display. Please add courses first.\n";
				}
				else
				{
					ViewCourses(codeList, nameList, crtHrsList, semList);
				}
				break;
			}

			//View courses by semester
			case 5:
			{
				int size = max_index(semList);

				if (size == -1)
				{
					cout << endl
						 << "There is no course to display. Please add courses first.\n";
				}
				else
				{
					ViewSemesterCourse(codeList, nameList, crtHrsList, semList, semester);
				}
				break;
			}

			case 6:
			{

				cout << "Enter the details of the student: ";
				cin >> regNo;
				cin.get(studentName, 100);

				if (isValidRegistrationNumber(regNo) == 0)
				{
					cout << endl
						 << "Invalid Registration number. Couldn't add the student" << endl;
				}
				if (isValidStudentName(studentName) == 0)
				{
					cout << endl
						 << "Invalid Student Name. Couldn't add the student" << endl;
				}

				addStudent(stdNameList, stdRegNoList, studentName, regNo);
				break;
			}

			case 7:
			{
				cout << "Enter the registration number of the student to edit: ";
				cin >> edit_reNo;

				if (index_reg_code(stdRegNoList, edit_reNo) == -1)
				{
					cout << "\nThere is no student by this registration number. \n";
				}
				else
				{
					cout << "Enter new details of the student: ";
					cin >> regNo;
					cin.get(studentName, 100);
					updateStudent(stdNameList, stdRegNoList, studentName, regNo);
				}

				break;
			}

			case 8:
			{
				cout << "Enter Registration number of the student to delete: ";
				cin >> reg_no;
				cout << endl;
				if (index_reg_code(stdRegNoList, reg_no) == -1)
				{
					cout << "There is no student by this registration number.\n ";
				}

				else
				{
					deleteStudent(stdNameList, stdRegNoList, stdCourseList, reg_no);
				}
				break;
			}

			case 9:
			{

				cout << "Enter registration Number of the student for course registration: ";
				cin >> reg_no;
				cout << endl;
				if (index_reg_code(stdRegNoList, reg_no) == -1)
				{
					cout << "There is no student by this registration number.\n ";
				}
				else
				{
					cout << "Enter the Course Code to register: ";
					cin >> courseCode;
					cout << endl;
					registerCourse(stdRegNoList, stdCourseList, codeList, reg_no, courseCode);
				}
				break;
			}

			case 10:
			{
				cout << "Enter registration number of the student: ";
				cin >> reg_no;
				if (index_reg_code(stdRegNoList, reg_no) == -1)
				{
					cout << "There is no student by this registration number.\n ";
				}

				else
				{
					cout << "Enter course code to unregister: ";
					cin >> courseCode;
					unRegisterCourse(stdRegNoList, stdCourseList, reg_no, courseCode);
				}
				break;
			}

			case 11:
			{
				viewstudents(stdRegNoList, stdNameList);
				break;
			}

			//logout from the account
			case 12:
			{
				system("CLS");
				loop = 0;
				a = 0;
				break;
			}

			//Exit the program
			case 13:
			{
				a = 0;

				/*this condition will check save 1 in an external file if there are courses stored in another external file.
				it also save addcourse counter in the external file*/

				if (check_1)
				{
					int var1 = saveCourses(codeList, nameList, crtHrsList, semList, semester);

					if (codeList[0] != "\0")
					{
						ofstream b;
						b.open("check_for_loadCourses.txt");
						c = 1;
						b << c;
						b.close();
					}
					else
					{
						ofstream b;
						b.open("check_for_loadCourses.txt");
						c = 0;
						b << c;
						b.close();
					}
				}

				//this condition will check whether any student has been entered or not
				if (stdRegNoList[0] != "\0")
				{
					ofstream file;
					file.open("check_for_student.txt");
					file << "1";
					file.close();
				}
				else
				{
					ofstream file;
					file.open("check_for_student.txt");
					file << "0";
					file.close();
				}
				saveStudents(stdRegNoList, stdNameList, stdCourseList);
				break;
			}

			default:
			{
				cout << endl
					 << "Invalid Option. Please select from 1 to 6. ";
			}
			}

			cout << endl;
			cout << "                    *********************************************************************";
			cout << endl;
		}
	}
	return 0;
}
