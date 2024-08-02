#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

class BookData
{
    char bookName[30];
    char bookNumber[6]; // Book number limit set to 5 characters + null terminator
    char authorName[20];

public:
    void createBook()
    {
        cout << "\n NEW BOOK ENTRY...\n";
        cout << "\n Enter the Book No. here  :- " << endl;
        cin >> setw(6) >> bookNumber; // Reading up to 5 characters
        cin.ignore();
        cout << "Enter the name of book here :- " << endl;
        cin.getline(bookName, 30);
        cout << "Enter the author of " << bookName << " here :- " << endl;
        cin.getline(authorName, 20);
        cout << "\n\n\n Book is successfully created.....";
    }

    void showBook()
    {
        cout << "\n Book No. :- " << bookNumber;
        cout << "\n Book Name :- " << bookName;
        cout << "\n Book Author Name :- " << authorName << endl;
    }

    void modifyBookData()
    {
        int ch = 0;
        cout << "\n Book Number :- " << bookNumber << endl;
        do
        {
            cout << " 1.\tModify Book Name." << endl;
            cout << " 2.\tModify Author Name. " << endl;
            cout << " 3.\tExit from Modification. " << endl;
            cout << "\tEnter your choice here(1-3) :- ";
            cin >> ch;
            cin.ignore();

            switch (ch)
            {
            case 1:
            {
                cout << "\n Enter the Book Name :- ";
                cin.getline(bookName, 30);
                break;
            }

            case 2:
            {
                cout << "\n Enter the author name :- ";
                cin.getline(authorName, 20);
                break;
            }

            case 3:
            {
                return;
            }

            default:
            {
                cout << " Invalid Value ";
                break;
            }
            }
        } while (ch != 3);
    }

    char *retBookNo()
    {
        return bookNumber;
    }

    void report()
    {
        cout << setw(6) << bookNumber << setw(30) << bookName << setw(30) << authorName << endl;
    }
};

class StudentData
{
    char admissionNO[12];
    char nameOfStudent[20];
    char studentBookNumber[6]; // Book number limit set to 5 characters + null terminator
    int token;

public:
    void createStudent()
    {
        system("cls");
        cout << "\n NEW STUDENT ENTRY..." << endl;
        cout << "\n Enter the admission no. of student here :- " << endl;
        cin >> setw(12) >> admissionNO;
        cin.ignore();
        cout << "\n Enter the student name here :- " << endl;
        cin.getline(nameOfStudent, 20);
        token = 0;
        strcpy(studentBookNumber, "\0");
        cout << "\n\n Student Record Created Successfully....";
    }

    void displayStudentData()
    {
        cout << "\n Admission Number : " << admissionNO;
        cout << "\n Student Name : " << nameOfStudent;
        cout << "\n Number of Books issued : " << token;
        if (token == 1)
        {
            cout << "\n Book Number :" << studentBookNumber;
        }
        cout << endl;
    }

    void modifyStudentData()
    {
        cout << "\n Admission No. :" << admissionNO;
        cout << "\n Modify Student Name : ";
        cin.getline(nameOfStudent, 20);
    }

    char *retAdmissionNo()
    {
        return admissionNO;
    }

    char *retstudentBookNo()
    {
        return studentBookNumber;
    }

    int retToken()
    {
        return token;
    }

    void createToken()
    {
        token = 1;
    }

    void resetToken()
    {
        token = 0;
    }

    void getStudentBNumber(char t[])
    {
        strcpy(studentBookNumber, t);
    }

    void report()
    {
        cout << setw(12) << admissionNO << setw(20) << nameOfStudent << setw(20) << token << endl;
    }
};

// File Handling
fstream fp, fp01;
BookData objB;
StudentData objS;

void writeBook()
{
    char ch;
    fp.open("book.dat", ios::out | ios::app);

    do
    {
        system("cls");
        objB.createBook();
        fp.write((char *)&objB, sizeof(BookData));
        cout << "\n\n Do you want to add more data ..(y/n) : ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');

    fp.close();
}

void writeStudent()
{
    char ch;
    fp.open("student.dat", ios::out | ios::app);

    do
    {
        system("cls");
        objS.createStudent();
        fp.write((char *)&objS, sizeof(StudentData));
        cout << "\n\n Do you want to add more data ..(y/n) : ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');

    fp.close();
}

void displaySBook(char n[])
{
    cout << "\n BOOK DETAILS \n";
    int flag = 0;

    fp.open("book.dat", ios::in);

    while (fp.read((char *)&objB, sizeof(BookData)))
    {
        if (strcmp(objB.retBookNo(), n) == 0)
        {
            objB.showBook();
            flag = 1;
        }
    }

    fp.close();

    if (flag == 0)
    {
        cout << "\n\n Book does not exist ..." << endl;
    }
}

void displaySStudent(char n[])
{
    cout << "\n STUDENT DETAILS \n";
    int flag = 0;

    fp.open("student.dat", ios::in);

    while (fp.read((char *)&objS, sizeof(StudentData)))
    {
        if (strcmp(objS.retAdmissionNo(), n) == 0)
        {
            objS.displayStudentData();
            flag = 1;
        }
    }

    fp.close();

    if (flag == 0)
    {
        cout << "\n\n Student does not exist ..." << endl;
    }
}

// Modify book data
void modifyBook()
{
    char n[6];
    int found = 0;
    system("cls");
    cout << "\n\n MODIFY BOOK RECORD...";
    cout << "\n\n Enter the book Number here :- ";
    cin >> n;

    fp.open("book.dat", ios::in | ios::out);

    while (fp.read((char *)&objB, sizeof(BookData)) && found == 0)
    {
        if (strcmp(objB.retBookNo(), n) == 0)
        {
            objB.showBook();
            cout << "\n Enter the new details of book : " << endl;
            objB.modifyBookData();
            int position = -1 * sizeof(objB);
            fp.seekp(position, ios::cur);
            fp.write((char *)&objB, sizeof(BookData));
            cout << "\n\n\t record Updated Successfully.." << endl;
            found = 1;
        }
    }

    fp.close();

    if (found == 0)
    {
        cout << "\n\n  Book is not found..." << endl;
    }

    cin.get(); // Replacing getch() with cin.get()
}

// Modify student data
void modifyStudent()
{
    char n[12];
    int found = 0;
    system("cls");
    cout << "\n\n MODIFY STUDENT RECORD...";
    cout << "\n\n Enter the student Admission Number here :- ";
    cin >> n;

    fp.open("student.dat", ios::in | ios::out);

    while (fp.read((char *)&objS, sizeof(StudentData)) && found == 0)
    {
        if (strcmp(objS.retAdmissionNo(), n) == 0)
        {
            objS.displayStudentData();
            cout << "\n Enter the new details of student : " << endl;
            objS.modifyStudentData();
            int position = -1 * sizeof(objS);
            fp.seekp(position, ios::cur);
            fp.write((char *)&objS, sizeof(StudentData));
            cout << "\n\n\t record Updated Successfully.." << endl;
            found = 1;
        }
    }

    fp.close();

    if (found == 0)
    {
        cout << "\n\n  record is not found..." << endl;
    }

    cin.get(); // Replacing getch() with cin.get()
}

// Delete student data
void deleteStudent()
{
    char n[12];
    int flag = 0;
    system("cls");
    cout << "\n\n\n\tDELETE STUDENT DATA ";
    cout << "\n\n Enter the admission no. of student here : " << endl;
    cin >> n;

    fp.open("student.dat", ios::in | ios::out);
    fstream fp02;
    fp02.open("temp.dat", ios::out);
    fp.seekg(0, ios::beg);

    while (fp.read((char *)&objS, sizeof(StudentData)))
    {
        if (strcmp(objS.retAdmissionNo(), n) != 0)
        {
            fp02.write((char *)&objS, sizeof(StudentData));
        }
        else
        {
            flag = 1;
        }
    }

    fp02.close();
    fp.close();
    remove("student.dat");
    rename("temp.dat", "student.dat");

    if (flag == 1)
    {
        cout << "\n\n\t Record Deleted Successfully.." << endl;
    }
    else
    {
        cout << "\n\n\t Record not Found .." << endl;
    }

    cin.get(); // Replacing getch() with cin.get()
}

// Delete book data
void deleteBook()
{
    char n[6];
    system("cls");
    cout << "\n\n\n\tDELETE BOOK DATA ";
    cout << "\n\n Enter the book no. of book here : ";
    cin >> n;

    fp.open("book.dat", ios::in | ios::out);
    fstream fp02;
    fp02.open("temp.dat", ios::out);
    fp.seekg(0, ios::beg);

    while (fp.read((char *)&objB, sizeof(BookData)))
    {
        if (strcmp(objB.retBookNo(), n) != 0)
        {
            fp02.write((char *)&objB, sizeof(BookData));
        }
    }

    fp02.close();
    fp.close();
    remove("book.dat");
    rename("temp.dat", "book.dat");
    cout << "\n\n\t Record Deleted Successfully.." << endl;
    cin.get(); // Replacing getch() with cin.get()
}

void displayAllSBooks()
{
    system("cls");
    fp.open("book.dat", ios::in);

    if (!fp)
    {
        cout << "ERROR!!! FILE COULD NOT BE OPEN ";
        cin.get(); // Replacing getch() with cin.get()
        return;
    }

    cout << "\n\n\t\t Book List \n\n";
    cout << "==================================================================================\n";
    cout << " Book Number " << setw(20) << " Book Name " << setw(25) << " Author " << endl;
    cout << "==================================================================================\n";

    while (fp.read((char *)&objB, sizeof(BookData)))
    {
        objB.report();
    }

    fp.close();
    cin.get(); // Replacing getch() with cin.get()
}

void displayAllSStudents()
{
    system("cls");
    fp.open("student.dat", ios::in);

    if (!fp)
    {
        cout << "ERROR!!! FILE COULD NOT BE OPEN ";
        cin.get(); // Replacing getch() with cin.get()
        return;
    }

    cout << "\n\n\t\t Student List \n\n";
    cout << "==================================================================\n";
    cout << " Admission Number " << setw(20) << " Student Name " << setw(10) << " Book Issued " << endl;
    cout << "==================================================================\n";

    while (fp.read((char *)&objS, sizeof(StudentData)))
    {
        objS.report();
    }

    fp.close();
    cin.get(); // Replacing getch() with cin.get()
}

void bookIssue()
{
    char sn[12], bn[6];
    int found = 0, flag = 0;
    system("cls");
    cout << "\n\n BOOK ISSUE...";
    cout << "\n\n\tEnter the student's admission number here : ";
    cin >> sn;
    fp.open("student.dat", ios::in | ios::out);
    fp01.open("book.dat", ios::in | ios::out);

    while (fp.read((char *)&objS, sizeof(StudentData)) && found == 0)
    {
        if (strcmp(objS.retAdmissionNo(), sn) == 0)
        {
            found = 1;
            if (objS.retToken() == 0)
            {
                cout << "\n\n\tEnter the book number here :- ";
                cin >> bn;

                while (fp01.read((char *)&objB, sizeof(BookData)) && flag == 0)
                {
                    if (strcmp(objB.retBookNo(), bn) == 0)
                    {
                        objB.showBook();
                        flag = 1;
                        objS.createToken();
                        objS.getStudentBNumber(objB.retBookNo());
                        int pos = -1 * sizeof(objS);
                        fp.seekp(pos, ios::cur);
                        fp.write((char *)&objS, sizeof(StudentData));
                        cout << "\n\n\t Book Issued Successfully..\n\n";
                    }
                }

                if (flag == 0)
                {
                    cout << "Book does not exist ";
                }
            }
            else
            {
                cout << "You have not returned the last book ";
            }
        }
    }

    if (found == 0)
    {
        cout << "Student record does not exist...";
    }

    cin.get(); // Replacing getch() with cin.get()
    fp.close();
    fp01.close();
}

void bookDeposit()
{
    char sn[12], bn[6];
    int found = 0, flag = 0, day, fine;
    system("cls");
    cout << "\n\n BOOK DEPOSIT...";
    cout << "\n\n\tEnter the student's admission number here : ";
    cin >> sn;
    fp.open("student.dat", ios::in | ios::out);
    fp01.open("book.dat", ios::in | ios::out);

    while (fp.read((char *)&objS, sizeof(StudentData)) && found == 0)
    {
        if (strcmp(objS.retAdmissionNo(), sn) == 0)
        {
            found = 1;
            if (objS.retToken() == 1)
            {
                while (fp01.read((char *)&objB, sizeof(BookData)) && flag == 0)
                {
                    if (strcmp(objB.retBookNo(), objS.retstudentBookNo()) == 0)
                    {
                        objB.showBook();
                        flag = 1;
                        cout << "\n\n Book deposited in no. of days :- ";
                        cin >> day;

                        if (day > 15)
                        {
                            fine = (day - 15) * 1;
                            cout << "\n\n Fine is : " << fine;
                        }

                        objS.resetToken();
                        int pos = -1 * sizeof(objS);
                        fp.seekp(pos, ios::cur);
                        fp.write((char *)&objS, sizeof(StudentData));
                        cout << "\n\n\t Book deposited successfully..";
                    }
                }

                if (flag == 0)
                {
                    cout << "Book does not exist ";
                }
            }
            else
            {
                cout << "No book is issued.. please check!!";
            }
        }
    }

    if (found == 0)
    {
        cout << "Student record does not exist...";
    }

    cin.get(); // Replacing getch() with cin.get()
    fp.close();
    fp01.close();
}

void intro()
{
    system("cls");
    cout << "\n\n\n\t Library Management Project";
    cout << "\n\n\n\t MAHAKAL INSTITUTE OF TECHNOLOGY UJJAIN";
    cin.get(); // Replacing getch() with cin.get()
}

void adminMenu()
{
    system("cls");
    int ch2;
    cout << "\n\n\n\t ADMINISTRATOR MENU ";
    cout << "\n\n\t 1. Create Student Record";
    cout << "\n\n\t 2. Display all Student Record";
    cout << "\n\n\t 3. Display Specific Student Record";
    cout << "\n\n\t 4. Delete Student Record";
    cout << "\n\n\t 5. Modify Student Record";
    cout << "\n\n\t 6. Create Book Record";
    cout << "\n\n\t 7. Display all Book Record";
    cout << "\n\n\t 8. Display Specific Book Record";
    cout << "\n\n\t 9. Delete Book Record";
    cout << "\n\n\t 10. Modify Book Record";
    cout << "\n\n\t 11. Back to Main Menu";
    cout << "\n\n\t Please Enter Your Choice (1-11): ";
    cin >> ch2;
    cin.ignore();
    switch (ch2)
    {
    case 1:
        writeStudent();
        break;
    case 2:
        displayAllSStudents();
        break;
    case 3:
    {
        char num[6];
        system("cls");
        cout << "\n\n\tPlease Enter the Admission Number: ";
        cin >> num;
        displaySStudent(num);
        break;
    }
    case 4:
        deleteStudent();
        break;
    case 5:
        modifyStudent();
        break;
    case 6:
        writeBook();
        break;
    case 7:
        displayAllSBooks();
        break;
    case 8:
    {
        char num[6];
        system("cls");
        cout << "\n\n\tPlease Enter the Book No.: ";
        cin >> num;
        displaySBook(num);
        break;
    }
    case 9:
        deleteBook();
        break;
    case 10:
        modifyBook();
        break;
    case 11:
        return;
    default:
        cout << "\a";
    }
    adminMenu();
}

int main()
{
    char ch;
    intro();
    do
    {
        system("cls");
        cout << "\n\n\n\t MAIN MENU";
        cout << "\n\n\t 1. Book Issue";
        cout << "\n\n\t 2. Book Deposit";
        cout << "\n\n\t 3. Administrator Menu";
        cout << "\n\n\t 4. Exit";
        cout << "\n\n\t Please Select Your Option (1-4): ";
        ch = cin.get();
        switch (ch)
        {
        case '1':
            bookIssue();
            break;
        case '2':
            bookDeposit();
            break;
        case '3':
            adminMenu();
            break;
        case '4':
            exit(0);
        default:
            cout << "\a";
        }
    } while (ch != '4');
    return 0;
}
