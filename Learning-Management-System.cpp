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

//this statement will declare edit_course and delete course for the whole program
string edit_course_code;
int flag = 0, counter = 0, counter2;

// this function will add course name, credit hours, semester and course code to nameList, crtHrsList, semList, codeList respectively
void AddCourse(string codeList[], string nameList[], int crtHrsList[], int semList[], char course_code[], int credit_hours, int semester, char course_name[])
{
	ifstream op;
	op.open("AddCourse_Counter.txt");
	int var;
	op >> var;
	op.close();
	static int n = var + 1;
	static int c = 0;
	
	

	if (isValidSemester(semester) == 1 && isValidCourseCode(course_code) == 1 && isValidCreditHours(credit_hours) == 1 && isValidCourseName(course_name) == 1)
	{
		if (flag)
		{
			int a = counter;
			codeList[a] = course_code;
			crtHrsList[a] = credit_hours;
			semList[a] = semester;
			nameList[a] = course_name;
			cout << "\nCourse has been added successfully" << endl;
			a++;
			flag = 0;
		}
		else if (var!=0)
		{
			codeList[n] = course_code;
			crtHrsList[n] = credit_hours;
			semList[n] = semester;
			nameList[n] = course_name;
			cout << "\nCourse has been added successfully" << endl;
			n++;
		}
		else
		{
			codeList[c] = course_code;
			crtHrsList[c] = credit_hours;
			semList[c] = semester;
			nameList[c] = course_name;
			cout << "\nCourse has been added successfully" << endl;
			c++;	
		}
	}
	if(var == 0)
	{
		counter2 = c;
	}
	else
	{
		counter2 = n;
	}
	
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
	int index;
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
		cout << "\nCourse has been edited successfully\n";
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

int main()
{
	int option, credit_hours, semester, check_user = 1, loop = 0;
	char course_code[6], course_name[50], usersList[1000] = {'\0'}, passwordsList[1000] = {'\0'};
	string delete_course_code, codeList[100], nameList[100];
	int a = 1, crtHrsList[100], semList[100];
	for (int x = 0; x < 100; x++)
	{
		semList[x] = 0;
		crtHrsList[x] = 0;
	}

	int load = loadCourses(codeList, nameList, crtHrsList, semList);

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

			check_user = loadUsers(usersList, passwordsList);
		} while (check_user == 0);

		loop = check_user;
		cout << endl
			 << "You have successfully logged in in your LMS account." << endl;

		system("CLS");
		while (a)
		{

			cout << endl;
			cout << "Choose the following option: " << endl;
			cout << endl
				 << "1 	Add Course" << endl;
			cout << "2	Update Course" << endl;
			cout << "3	Delete Course" << endl;
			cout << "4 	View All Courses" << endl;
			cout << "5	View Courses of a Semester" << endl;
			cout << "6 	Logout of the system" << endl
				 << "7	Exit Program" << endl
				 << endl;

			cout << "Choose the option: ";
			cin >> option;
			cout << endl;

			if (cin.fail())
			{
				option = 7;
			}
			switch (option)
			{

			//Add courses
			case 1:
			{
				cout << "Enter the details of the course: ";
				cin >> course_code >> credit_hours >> semester;
				cin.get(course_name, 100);

				if (isValidCourseCode(course_code) == 0)
				{
					cout << "Invalid Course Code\n";
				}
				if (isValidCreditHours(credit_hours) == 0)
				{
					cout << "Invalid Credit" << endl;
				}
				if (isValidSemester(semester) == 0)
				{
					cout << "Invalid Semester\n";
				}
				bool b = isValidCourseName(course_name);
				if (b == false)
				{
					cout << "Invalid Course Name\n";
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
				system("CLS");
				loop = 0;
				a = 0;
				break;
			}

			//Exit the program
			case 7:
			{
				a = 0;
				int a = saveCourses(codeList, nameList, crtHrsList, semList, semester);
				ofstream b;
				b.open("check_for_loadCourses.txt");

				int c = 1;
				b << c;
				b.close();

				ofstream counter;
				counter.open("AddCourse_Counter.txt");
				counter << counter2 - 1;
				counter.close();
				break;
			}

			default:
			{
				cout << endl
					 << "Invalid Option. Please select from 1 to 6. ";
			}
			}

			cout << endl;
			cout << "**************************************************************************************";
			cout << endl;
		}
	}

	return 0;
}