#include <iostream>
#include <cstring>
#include <fstream>
#include <conio.h>
#include <iomanip>
#include <windows.h>
#include <cstdlib>
#include <string>
#include <unistd.h>
#include<istream>

using namespace std;
#define total_vaccine 1000;

class vaccine_management
{
protected:
    // user details

    string username;
    string password;
    string usn;
    char name[100];
    char gender[100];
    int age;
    string adhaar;
    int c;
    string phone_no, profession, address, vaccine_name;
    int dose = 0;

    // for vaccine center

    string center1 = "1.Purulia, Block -I";
    string center2 = "2.Purulia, Block -II";
    string center3 = "3.Purulia, Jhalda Block";

    int sum_vaccine_c1 = 0;
    int sum_vaccine_c2 = 0;
    int sum_vaccine_c3 = 0;

    // For Admin Section
    // For doctor details
    char d_name[100];
    int d_age;
    string med_reg;
    char specialiazation[100];
    string center;
    string d_govt_id;
    string d_gender;
    string d_phoneno;

    // user section

public:
    void menu();
    void admin();
    void admin_password();
    void user();
    void user_password();

    // admin section
    void add_vaccine();
    void show_center();
    void add_doctor();
    void show_doctor();
    void show_doctor_list();
    void show_patient_data();
    void search_by_aadhar();
    void  search_by_age();
    void  search_by_profession();
    void search_by_gender();


    // user section
    void add_patient_data();
    void show_data();
    void patient_show_data();
    void second_dose_update();
};
//---------------------------------------------------------------------------------------------------------------------------------------------
// MAIN MENU
//---------------------------------------------------------------------------------------------------------------------------------------------
void vaccine_management ::menu()
{
    system("cls"); // to clear the screen
    int choice;

    cout << "\n\t\t\t\t ----------------------------------";
    cout << "\n\t\t\t\t  *      Vaccine Management       *";
    cout << "\n\t\t\t\t ----------------------------------";

    // main menu
    cout << "\n\n\t\t\t\t --------->> MAIN MENU <<--------";
    cout << "\n\n\t\t  1. ADMIN";
    cout << "\n\n\t\t  2. USER";
    cout << "\n\n\t\t  3. EXIT";

    cout << "\n\n\t\tEnter your choice: ";
    cin >> choice;

    // calling as per choice
    switch (choice)
    {
    case 1:
        admin();
        break;
    case 2:
        user();
        break;
    case 3:
        system("cls");
        cout << "Thank You for visiting";
        Sleep(10); // acts like a delay
        exit(0);
    default:
        cout << "\n\n\t\tInvalid choice please try again........";
        cout << "\n\nPress any key to continue....";
        getch();
        system("cls");
        menu();
    }
}

//---------------------------------------------------------------------------------------------------------------------------------------------
// ADMIN SECTION
//---------------------------------------------------------------------------------------------------------------------------------------------
/*                            ===========================================================
                                                     ADMIN MENU
                              ===========================================================*/
void vaccine_management ::admin()
{
    admin_password();
    system("cls");
    int admin_choice;
    cout << "\n\t\t\t\t ----------------------------------";
    cout << "\n\t\t\t\t  *      Vaccine Management       *";
    cout << "\n\t\t\t\t ----------------------------------";

    // ADMIN MENU
    cout << "\n\n\t\t\t\t --------->> ADMIN MENU <<--------";
    cout << "\n\n\t\t 1.Add Vaccine Stock";
    cout << "\n\n\t\t 2.Search vaccine center and availability";
    cout << "\n\n\t\t 3.Add new Doctor Data";
    cout << "\n\n\t\t 4.Show doctor data";
    cout << "\n\n\t\t 5.Show Patient Data";
    cout << "\n\n\t\t 6.LOG OUT";

    cout << "\n\n\t\t Enter Choice";
    cin >> admin_choice;
    switch (admin_choice)
    {
    case 1:
        add_vaccine();
        break;
    case 2:
        show_center();
        break;
    case 3:
        add_doctor();
        break;
    case 4:
        show_doctor();
        break;
    case 5:
        show_patient_data();
        break;
    case 6:
        system("cls");
        menu();
    default:
        cout << "\n\n\t You are successfully login.";
        cout << "\n\n\t Press any key to continue...";

        getch();
        admin();
    }
}
/*                            ===========================================================
                                                     ADMIN VERIFICATION
                              ===========================================================*/
void vaccine_management::admin_password()
{
    system("cls");
    char a_name[20];
    char a_password[20];
    int ch, i = 0, capt = 0, capta = 0;
    cout << "\n\t\t\t\t ----------------------------------";
    cout << "\n\t\t\t\t  *      Vaccine Management       *";
    cout << "\n\t\t\t\t ----------------------------------";

    cout << "\n\n\t\t -->> LOGIN ADMIN <<--";
    cout << "\n\n\t\t Enter Your Name : ";
    cin >> a_name;
    cout << "\n\t\t Enter your Password: ";
    while ((ch = getch()) != 13)
    {
        cout << "*";
        a_password[i] = ch;
        i++;
    }
    a_password[i] = '\0';
    srand(time(0)); // use current time as random genertaor
    capt = rand();
    cout << "\n\t\t Captcha: " << capt;
    cout << "\n\t\t Enter Valid Captcha: ";
    cin >> capta;
    if ((strcmp(a_name, "snigdha") == 0) && (capt == capta) && (strcmp(a_password, "vaccine") == 0))
    {
        cout << "\n\n\n\t\t -----|Verifying admin|----- \n\n\t\t\t";
        for (int a = 1; a < 8; a++)
        {
            Sleep(500);
            cout << "...";
        }
        cout << "\n\n Access Granted...";
        system("PAUSE");
        system("cls");
    }
    else
    {
        cout << "\n\n\n\t\t -----|Verifying admin|----- \n\n\t\t\t";
        for (int a = 1; a < 8; a++)
        {
            Sleep(500);
            cout << "....";
        }
        cout << "\n\n Invaild Details...";
        cout << "\n\n Press any key to go back to the main menu";
        getch();
        system("PAUSE");
        system("cls");
        menu();
    }
}
/*                            ===========================================================
                                                     VACCINE DETAILS
                              ===========================================================*/
void vaccine_management ::add_vaccine()
{
A:
    fstream file1;
    system("cls");
    cout << "\n\t\t\t\t ----------------------------------";
    cout << "\n\t\t\t\t  *      Vaccine Management       *";
    cout << "\n\t\t\t\t ----------------------------------";
    cout << "\n\n\t\t\t\t --------->> ADD VACCINE IN CENTER <<--------";
    cout << "\n\n\t\t" << center1 << "\t\t" << center2;
    cout << "\n\n\t\t" << center3 << "\t\t 4."
         << "BACK";
    cout << "\n\n\t\t Enter the choice";
    int cen_choice;
    cin >> cen_choice;
    switch (cen_choice)
    {
    case 1:
    {
        int add;
        file1.open("center1.txt", ios::app);
        cout << "\n\t\t --> For Center 1<<<---";

        cout << "\n\t\tEnter the number of vaccine to be added : ";
        cin >> add;
        sum_vaccine_c1 = sum_vaccine_c1 + add;
        file1 << sum_vaccine_c1;
        file1.close();
        cout << "\n\n\t Vaccine in Center :" << sum_vaccine_c1;
        cout << "\n\n\tSUCCESSFULLY ADDED VACCINES TO THE CENTER";
        cout << "\n\n\t Press any key to continue...";
        getch();
        goto A;
        break;
    }
    case 2:
    {
        int add;
        file1.open("center2.txt", ios::app);
        cout << "\n\t\t --> For Center 2<<<---";

        cout << "\n\t\tEnter the number of vaccine to be added : ";
        cin >> add;
        sum_vaccine_c2 = sum_vaccine_c2 + add;
        file1 << sum_vaccine_c2;
        file1.close();
        cout << "\n\n\t Vaccine in Center :" << sum_vaccine_c2;
        cout << "\n\n\tSUCCESSFULLY ADDED VACCINES TO THE CENTER";
        cout << "\n\n\t Press any key to continue...";
        getch();
        goto A;
        break;
    }
    case 3:
    {
        int add;
        file1.open("center3.txt", ios::app);
        cout << "\n\t\t --> For Center 3<<<---";

        cout << "\n\t\tEnter the number of vaccine to be added : ";
        cin >> add;
        sum_vaccine_c3 = sum_vaccine_c3 + add;
        file1 << sum_vaccine_c3;
        file1.close();
        cout << "\n\n\t Vaccine in Center :" << sum_vaccine_c3;
        cout << "\n\n\tSUCCESSFULLY ADDED VACCINES TO THE CENTER";
        cout << "\n\n\t Press any key to continue...";
        getch();
        goto A;
        break;
    }
    case 4:
        break;
    default:
        cout << "\n\n\t\t\t Invalid Choice... Please Try Again....";
        cout << "\n\n Press Any Key To Continue: ";
        getch();
        add_vaccine();
        break;
    }
}
/*                            ===========================================================
                                                    CENTER DETAILS
                              ===========================================================*/
void vaccine_management ::show_center()
{
    fstream file;

    system("cls");

    cout << "\n\t\t\t\t ----------------------------------";
    cout << "\n\t\t\t\t  *      Vaccine Management       *";
    cout << "\n\t\t\t\t ----------------------------------";

    file.open("center1.txt");
    if (!file)
    {
        cout << "\n\n\t File doesn't exist";
    }
    else
    {
        file >> sum_vaccine_c1;
        cout << "\n\n\tThe Nmae of the center- " << center1;
        cout << "\n\n\t Total no of vaccine- " << sum_vaccine_c1;
    }
    file.close();
    file.open("center2.txt");
    if (!file)
    {
        cout << "\n\n\t File doesn't exist";
    }
    else
    {
        file >> sum_vaccine_c2;
        cout << "\n\n\tThe Nmae of the center- " << center2;
        cout << "\n\n\t Total no of vaccine- " << sum_vaccine_c2;
    }
    file.close();
    file.open("center3.txt");
    if (!file)
    {
        cout << "\n\n\t File doesn't exist";
    }
    else
    {
        file >> sum_vaccine_c3;
        cout << "\n\n\tThe Nmae of the center- " << center3;
        cout << "\n\n\t Total no of vaccine- " << sum_vaccine_c3;
    }
    file.close();
}
/*                            ===========================================================
                                                  DOCTOR DETAILS
                              ===========================================================*/
void vaccine_management ::add_doctor()
{
    system("cls");
    cout << "\n\t\t\t\t ----------------------------------";
    cout << "\n\t\t\t\t  *      Vaccine Management       *";
    cout << "\n\t\t\t\t ----------------------------------";
    cout << "\n\n\t\t\t\t --------->>ADD DOCTOR DETAILS <<--------";
    fstream file; // fstream works as a sum up of ostream and istream
    cout << "\n\t\t Enter Doctor Name: ";
    fflush(stdin); // erase the output buffer to take the new input
    cin.getline(d_name, 100);

    cout << "\n\t\tEnter The Gender(male/female/other): ";
    cin >> d_gender;
    fflush(stdin);
    cout << "\n\t\tEnter the specialization: ";
    cin >> specialiazation;

    cout << "\n\t\t Enter The Medical Registration: ";
    cin >> med_reg;
C:
    cout << "\n\t\tEnter the Govt Id (Aadhar No.): ";
    cin >> d_govt_id;

    if (d_govt_id.length() != 12)
    {
        cout << "\n\t\t Invalid Number.... Please Enter a Valid a Id No....";
        goto C;
    }
    else
    {
        if (d_govt_id[0] == 0 && d_govt_id[0] == 1)
        {
            cout << "\n\t\t Invalid Number.... Please Enter a Valid a Id No....";
            goto C;
        }
        else
        {
            cout << "\n\t\tValid Aadhar Card Number.";
        }
    }
D:
    cout << "\n\t\tEnter the Phone number: ";
    cin >> d_phoneno;
    if (d_phoneno.length() != 10)
    {
        cout << "\n\t\t Invalid Number.... Please Enter a Valid a Id No....";
        goto D;
    }
    else
    {
        if (d_phoneno[0] == 0 && d_phoneno[0] == 1)
        {
            cout << "\n\t\t Invalid Number.... Please Enter a Valid a Id No....";
            goto D;
        }
    }
    cout << "\n\t\tEnter the Clinic / Hospital Address: ";
    cin >> center;
    file.open("Doctor_Data.dat", ios::app | ios::binary);

    // ios::binary It is a file that contains information in the same format as it isheld in memory.
    //  ios::app	All output operations are performed at the end of the file, appending the content to the current content of the file.

    file.write((char *)this, sizeof(vaccine_management));
    /*write a block of binary data or writes fixed number of bytes froma specific
            memory location to the specified stream*/
    /*The first is the address of variable, and the second is the length of that variable in bytes.
    The address of variable must be type cast to type char*(pointer to character type)*/

    cout << "\n\t\tYOUR DATA HAS BEEN SUCCESSFULLY INSERTED" << endl;
    cout << "\n\t\tPress Any Key To Continue..";
    file.close();
    getch();
}
/*                            ===========================================================
                                                    DISPLAY DOCTOR DATA
                              ===========================================================*/
void vaccine_management ::show_doctor()
{
    system("cls");
    cout << "\n\t\t\t\t ----------------------------------";
    cout << "\n\t\t\t\t  *      Vaccine Management       *";
    cout << "\n\t\t\t\t ----------------------------------";
    cout << "\n\n\t\t\t\t --------->> Display Doctor Data<<--------";
    ifstream file;
    file.open("Doctor_Data.dat", ios::in | ios::binary);
    if (!file)
    {
        cout << "\n\t\tFile Doesn't Exist";
    }
    else
    {
        file.read((char *)this, sizeof(*this));
        while (!file.eof())
        {
            cout << "\n";
            show_doctor_list();
            file.read((char *)this, sizeof(*this));
        }
        file.close();
        cout << "\n\nPress Any Key To Continue..";
        getch();
    }
}

void vaccine_management ::show_doctor_list()
{
    cout.setf(ios::left, ios::adjustfield);
    cout.width(20);
    cout << endl
         << "Name: ";
    cout.setf(ios::right, ios::adjustfield);
    cout.width(25);
    cout << setfill(' ') << d_name;
    cout.setf(ios::left, ios::adjustfield);
    cout.width(20);
    cout << endl
         << "Gender: ";
    cout.setf(ios::right, ios::adjustfield);
    cout.width(25);
    cout << setfill(' ') << d_gender;
    cout.setf(ios::left, ios::adjustfield);
    cout.width(20);
    cout << endl
         << "Specialization: ";
    cout.setf(ios::right, ios::adjustfield);
    cout.width(25);
    cout << setfill(' ') << specialiazation;
    cout.setf(ios::left, ios::adjustfield);
    cout.width(20);
    cout << endl
         << "Medical registration no: ";
    cout.setf(ios::right, ios::adjustfield);
    cout.width(25);
    cout << setfill(' ') << med_reg;
    cout.setf(ios::left, ios::adjustfield);
    cout.width(20);
    cout << endl
         << "Goverment Id(Aadhar No.)";
    cout.setf(ios::right, ios::adjustfield);
    cout.width(25);
    cout << setfill(' ') << d_govt_id;
    cout.setf(ios::left, ios::adjustfield);
    cout.width(20);
    cout << endl
         << "Phone No.: ";
    cout.setf(ios::right, ios::adjustfield);
    cout.width(25);
    cout << setfill(' ') << d_phoneno;
    cout.setf(ios::left, ios::adjustfield);
    cout.width(20);
    cout << endl
         << "Center: ";
    cout.setf(ios::right, ios::adjustfield);
    cout.width(25);
    cout << setfill(' ') << center;
}
void vaccine_management :: show_patient_data()
{
B:
    cout << "\n\t\t\t\t ----------------------------------";
    cout << "\n\t\t\t\t  *      Vaccine Management       *";
    cout << "\n\t\t\t\t ----------------------------------";
    cout << "\n\n\t\t\t\t --------->> SEARCH THE PATIENT DETAILS <<--------";
    cout << "\n\t\t1. Search Data By Aadhar \t\t\t2. Search Data BY  AGE" << endl;
    cout << "\n\t\t3. Search Data By Profession \t\t\t4. Search Data By Gender" << endl;
    cout << "\n\t\t5. EXIT";
    int search_choice;
    cout << "\n\t\tEnter Your choice: ";
    cin >> search_choice;
    switch (search_choice)
    {
    case 1:
        search_by_aadhar();
        goto B;
    case 2:
        search_by_age();
        goto B;
    case 3:
        search_by_profession();
        goto B;
    case 4:
        search_by_gender();
        goto B;
    case 5:
        break;
    default:
        cout << "\n\n\t\tInvalid Choice.. Please Try Again..";
        getch();
        goto B;
    }
}
void vaccine_management ::search_by_aadhar(){
    int count = 0;
    string sadhaar;
    ifstream file;
    file.open("Patient_Data.dat", ios::in | ios::binary);
    system("cls");
     cout << "\n\t\t\t\t ----------------------------------";
    cout << "\n\t\t\t\t  *      Vaccine Management       *";
    cout << "\n\t\t\t\t ----------------------------------";
    cout << "\n\n\t\t-->> SEARCH PATIENT DATA BY AADHAR <<--";
    cout << "\n\n\t\tEnter Aadhar No.: ";
    cin >> sadhaar;
    if (!file)
    {
        cout << "\nFile Not Found!";
    }
    else
    {
        file.read((char *)this, sizeof(vaccine_management));
    }
    while (!file.eof())
    {
        if (sadhaar.compare(adhaar) == 0)
        {
            count++;
            show_data();
        }
        file.read((char *)this, sizeof(vaccine_management));
    }
    if (count == 0)
    {
        cout << "\nRecord Not Found!";
    }
    file.close();
    cout << "\n\nPress Any Key To Continue..";
    getch();
}
void vaccine_management::search_by_age()
{
    int count = 0;
    int sage;
    ifstream file;
    file.open("Patient_Data.dat", ios::in | ios::binary);
    system("cls");
      cout << "\n\t\t\t\t ----------------------------------";
    cout << "\n\t\t\t\t  *      Vaccine Management       *";
    cout << "\n\t\t\t\t ----------------------------------";
    cout << "\n\n\t\t-->> SEARCH PATIENT DATA BY AGE <<--";
    cout << "\n\n\t\tEnter Your Age: ";
    cin >> sage;
    if (!file)
    {
        cout << "\nFile Not Found!";
    }
    else
    {
        file.read((char *)this, sizeof(vaccine_management));
    }
    while (!file.eof())
    {
        if (sage == age)
        {
            count++;
            show_data();
        }
        file.read((char *)this, sizeof(vaccine_management));
    }
    if (count == 0)
    {
        cout << "\nRecord Not Found!";
    }
    file.close();
    cout << "\n\nPress Any Key To Continue..";
    getch();
}

void vaccine_management::search_by_profession()
{
    int count = 0;
    string sprofession;
    ifstream file;
    file.open("Patient_Data.dat", ios::in | ios::binary);
    system("cls");
      cout << "\n\t\t\t\t ----------------------------------";
    cout << "\n\t\t\t\t  *      Vaccine Management       *";
    cout << "\n\t\t\t\t ----------------------------------";
    cout << "\n\n\t\t-->> SEARCH PATIENT DATA BY PROFESSION <<--";
    cout << "\n\n\t\tEnter Your Profession: ";
    cin >> sprofession;
    if (!file)
    {
        cout << "\nFile Not Found!";
    }
    else
    {
        file.read((char *)this, sizeof(vaccine_management));
    }
    while (!file.eof())
    {
        if (sprofession.compare(profession) == 0)
        {
            count++;
            show_data();
        }
        file.read((char *)this, sizeof(vaccine_management));
    }
    if (count == 0)
    {
        cout << "\nRecord Not Found!";
    }
    file.close();
    cout << "\n\nPress Any Key To Continue..";
    getch();
}

void vaccine_management::search_by_gender()
{
    int count = 0;
    char sgender[10];
    ifstream file;
    file.open("Patient_Data.dat", ios::in | ios::binary);
    system("cls");
      cout << "\n\t\t\t\t ----------------------------------";
    cout << "\n\t\t\t\t  *      Vaccine Management       *";
    cout << "\n\t\t\t\t ----------------------------------";
    cout << "\n\n\t\t-->> SEARCH PATIENT DATA BY GENDER <<--";
    cout << "\n\n\t\tEnter Your Gender: ";
    cin >> sgender;
    if (!file)
    {
        cout << "\nFile Not Found!";
    }
    else
    {
        file.read((char *)this, sizeof(vaccine_management));
    }
    while (!file.eof())
    {
        if (strcmp(sgender, gender) == 0)
        {
            count++;
            show_data();
        }
        file.read((char *)this, sizeof(vaccine_management));
    }
    if (count == 0)
    {
        cout << "\nRecord Not Found!";
    }
    file.close();
    cout << "\n\nPress Any Key To Continue..";
    getch();
}


//---------------------------------------------------------------------------------------------------------------------------------------------
// USER SECTION
//---------------------------------------------------------------------------------------------------------------------------------------------
/*                            ===========================================================
                                                     USER MENU
                              ===========================================================*/
void vaccine_management ::user()
{
    user_password();
    system("cls");
    int user_choice;

    cout << "\n\t\t\t\t ----------------------------------";
    cout << "\n\t\t\t\t  *      Vaccine Management       *";
    cout << "\n\t\t\t\t ----------------------------------";

    // USER MENU
    cout << "\n\n\t\t\t\t --------->> USER MENU <<--------";
    cout << "\n\n\t\t 1. Apply for first dose";
    cout << "\n\n\t\t 2. Apply for second dose";
    cout << "\n\n\t\t 3. Search for vaccine center";
    cout << "\n\n\t\t 4.LOG OUT";

    cout << "\n\n\t\t Enter Choice";
    cin >> user_choice;
    switch (user_choice)
    {
    case 1:
        add_patient_data();
        break;
    case 2:
        second_dose_update();
        break;
    case 3:
        patient_show_data();
        break;

    default:
        cout << "\n\n\t\t\t Invalid Choice... Please Try Again....";
        cout << "\n\n Press Any Key To Continue: ";
        getch();
        user();
        break;
    }
}
/*                            ===========================================================
                                                     USER VERIFICATION
                              ===========================================================*/
void vaccine_management::user_password()
{
    system("cls");

    int user_choice;
    string fname, usern;
    string pswd, pswd2;
    string GOVT_Id;
    ofstream fileo;
    ifstream filei;

    // ofstream- This class describes an output stream. It is used to create files and to write data to files.
    // ifstream- This class describes an input stream. It's a program that reads data from files and displays it.

    cout << "\n\t\t\t\t ----------------------------------";
    cout << "\n\t\t\t\t  *      Vaccine Management       *";
    cout << "\n\t\t\t\t ----------------------------------";
    cout << "\n\n\t\t\t\t --------->> USER MENU <<--------";
    cout << "\n\n\t\t 1.Create Account";
    cout << "\n\n\t\t 2.Login";
    cout << "\n\n\t\t 3.Back";
    cout << "\n\n\t\tEnter Your Choice: ";
    cin >> user_choice;
    if (user_choice == 1)
    {
        system("cls");
        cout << "\n\n\t\t--------->> REGISTRATION <<--------";
        cout << "\n\n\t\t Enter Your Name: ";
        cin.ignore();
        getline(cin, username);
        cout << "\n\n\t\tEnter your user id : ";
        cin >> usn;
        cout << "\n\n\t\tEnter your Goverment id(Aadhar No.) : ";
        cin >> GOVT_Id;
        do
        { // Password validation
            cout << "\n\t Set your password: ";
            cin >> pswd;
            cout << "\n\t Confirm password: ";
            cin >> pswd2;
            if (pswd != pswd2)
                cout << "\n\t Password does not match! Set up your password again!";
        } while (pswd != pswd2);
        fname = usn + ".txt";
        fileo.open(fname.c_str());
        fileo << usn << endl
              << username << endl
              << GOVT_Id << endl
              << pswd << endl;
        cout << "\n\n\t You are successfully registered.";
        cout << "\n \n \tpress any key to continue...";
        Sleep(50);
        getch();
        fileo.close();
        user();
    }
    else if (user_choice == 2)
    {
        system("cls");
        string u_name, u_pass;
        cout << "\n\t\t\t\t ----------------------------------";
        cout << "\n\t\t\t\t  *      Vaccine Management       *";
        cout << "\n\t\t\t\t ----------------------------------";
        cout << "\n\n\t\t--------->> LOG IN <<--------";
        cout << "\n\t\tEnter your User Name: ";
        cin >> u_name;
        cout << "\n\t\t Enter your Password: ";
        cin >> u_pass;
        fname = u_name + ".txt";
        filei.open(fname.c_str());
        if (!filei.is_open() && filei.fail())
        {
            cout << "You are not Registered, Please registered First.";
            cout << "\n\n\t Press any key to continue...";
            filei.close();
            getch();
            user_password();
        }
        getline(filei, usern);
        getline(filei, u_pass);
        if (u_name == usn && u_pass == pswd)
        {
            cout << "\n\n\t You are successfully login.";
            cout << "\n\n\t Press any key to continue...";
            Sleep(500);
            getch();
            user();
        }

        else if (u_name == usn && u_pass != pswd)
        {

            cout << "\n\n\t Please enter correct password.... Try Again...";
            cout << "\n\n\t Press any key to continue...";
            Sleep(500);
            getch();
            user_password();
        }
    }
    else if (user_choice == 3)
    {
        system("cls");

        menu();
    }
    else
    {
        cout << "Invaild choice....";
        cout << "\n\n Press Any Key To Continue: ";

        getch();

        user_password();
    }
}
/*                            ===========================================================
                                                     APPLY FOR FIRST DOSE
                              ===========================================================*/
void vaccine_management::add_patient_data()
{
    fstream file;
    system("cls");
    cout << "\n\t\t\t\t ----------------------------------";
    cout << "\n\t\t\t\t  *      Vaccine Management       *";
    cout << "\n\t\t\t\t ----------------------------------";
    cout << "\n\n\t\t-->> APPLY FOR VACCINE FIRST DOSE <<--";
    cout << "\n\n\t\tEnter Name: ";
    fflush(stdin);
    cin.getline(name, 100);
C:
    cout << "\n\n\t\tEnter Aadhar No.: ";
    cin >> adhaar;
    if (adhaar.length() != 12)
    {
        cout << "\nInvalid Aadhar Card Number";
        goto C;
    }
    else
    {
        // The first letter should not start with 0 or 1
        if (adhaar[0] == '0' || adhaar[0] == '1')
        {
            cout << "\nInvalid Aadhar Card Number";
            goto C;
        }
        else
        {
            cout << "\nValid Aadhar Card Number";
        }
    }
B:
    cout << "\n\n\t\tEnter Your Mobile Number: ";
    cin >> phone_no;
    if (phone_no.length() != 10)
    {
        cout << "\nInvalid Phone Number";
        goto B;
    }
    else
    {
        // The First letter should not start with 0 or 1
        if (phone_no[0] == '0' || phone_no[0] == '1')
        {
            cout << "\nInvalid Phone Number";
            goto B;
        }
        else
        {
            cout << "\nValid Phone Number";
        }
    }
    cout << "\n\n\t\tEnter Gender (M/F): ";
    cin >> gender;
    cout << "\n\n\t\tEnter Age: ";
    cin >> age;
    cout << "\n\n\t\tEnter Profession: ";
    cin.ignore();
    getline(cin, profession);
    cout << "\n\n\t\tEnter Permanent Address: ";
    cin >> address;
    cout << "\n\n\t\tEnter Vaccine Name [Covishield & Covaxin]: ";
    cin >> vaccine_name;
    cout << "\n\n\t\tEnter Dose: ";
    cin >> dose;
    cout << "\n\n\t\tEnter Center Allotted: ";
    cin >> center;
    file.open("Patient_Data.dat", ios::app | ios::binary);
    file.write((char *)this, sizeof(vaccine_management));
    cout << "\n\nYOU HAVE SUCCESSFULLY VACCINATED :)";
    cout << "\n\nPress Any Key To Continue..";
    file.close();
    getch();
}
/*                            ===========================================================
                                                     APLLY FOR SECOND DATA
                              ===========================================================*/
void vaccine_management::second_dose_update()
{
    fstream file;
    int count = 0;

    system("cls");
    cout << "\n\t\t\t\t ----------------------------------";
    cout << "\n\t\t\t\t  *      Vaccine Management       *";
    cout << "\n\t\t\t\t ----------------------------------";
    cout << "\n\n\t\t-->> Apply for Second Vaccine <<--";
    string uaadhar;
    cout << "\n\t\t Enter Your Aadhar details: ";
    cin >> uaadhar;
    file.open("Patient_Data.dat", ios::binary | ios::in | ios::out | ios::ate);
    file.seekg(0);
    file.read((char *)this, sizeof(*this));
    dose = 1;
    while (!file.eof())
    {
        if (uaadhar.compare(adhaar) == 0)
        {
            count++;
            dose++;
            cout << "\nDose: " << dose;
            file.seekp(file.tellp() - sizeof(*this));
            // seekp() moves put pointer (output) to a specified location
            // tellp() gives the current position of the put pointer
            file.write((char *)this, sizeof(*this));
            cout << "\n\nYou are Vaccinated :)";
        }
        file.read((char *)this, sizeof(*this));
    }
    if (count == 0)
    {
        cout << "\n\tRecord not Found!";
        cout << "\n\t Apply for First Vaccine";
    }
    file.close();
    cout << "\n\nPress Any Key To Continue..";
    getch();
}
/*                            ===========================================================
                                                    DISPLAY PATIENT DATA
                              ===========================================================*/
void vaccine_management::patient_show_data()
{
    int count = 0;
    string vadhaar;
    ifstream file;
    file.open("Patient_Data.dat", ios::in | ios::binary);
    system("cls");
    cout << "\n\t\t\t\t ----------------------------------";
    cout << "\n\t\t\t\t  *      Vaccine Management       *";
    cout << "\n\t\t\t\t ----------------------------------";
    cout << "\n\n\t\t-->> SEARCH DATA BY AADHAR <<--";
    cout << "\n\n\t\tEnter Aadhar No.: ";
    cin >> vadhaar;
    if (!file)
    {
        cout << "\nFile Not Found!";
    }
    else
    {
        file.read((char *)this, sizeof(vaccine_management));
    }
    while (!file.eof())
    {
        if (vadhaar.compare(adhaar) == 0)
        {
            count++;
            show_data();
        }
        file.read((char *)this, sizeof(vaccine_management));
    }
    if (count == 0)
    {
        cout << "\nRecord Not Found!";
    }
    file.close();
    cout << "\n\nPress Any Key To Continue..";
    getch();
}

void vaccine_management::show_data()
{
    cout.setf(ios::left, ios::adjustfield);
    cout.width(20);
    cout << endl
         << "Name: ";
    cout.setf(ios::right, ios::adjustfield);
    cout.width(25);
    cout << setfill(' ') << name;
    cout.setf(ios::left, ios::adjustfield);
    cout.width(20);
    cout << endl
         << "Aadhar No.: ";
    cout.setf(ios::right, ios::adjustfield);
    cout.width(25);
    cout << setfill(' ') << adhaar;
    cout.setf(ios::left, ios::adjustfield);
    cout.width(20);
    cout << endl
         << "Mobile No.: ";
    cout.setf(ios::right, ios::adjustfield);
    cout.width(25);
    cout << setfill(' ') << phone_no;
    cout.setf(ios::left, ios::adjustfield);
    cout.width(20);
    cout << endl
         << "Gender: ";
    cout.setf(ios::right, ios::adjustfield);
    cout.width(25);
    cout << setfill(' ') << gender;
    cout.setf(ios::left, ios::adjustfield);
    cout.width(20);
    cout << endl
         << "Age: ";
    cout.setf(ios::right, ios::adjustfield);
    cout.width(25);
    cout << setfill(' ') << age;
    cout.setf(ios::left, ios::adjustfield);
    cout.width(20);
    cout << endl
         << "Profession: ";
    cout.setf(ios::right, ios::adjustfield);
    cout.width(25);
    cout << setfill(' ') << profession;
    cout.setf(ios::left, ios::adjustfield);
    cout.width(20);
    cout << endl
         << "Vaccine Name: ";
    cout.setf(ios::right, ios::adjustfield);
    cout.width(25);
    cout << setfill(' ') << vaccine_name;
    cout.setf(ios::left, ios::adjustfield);
    cout.width(20);
    cout << endl
         << "Dose: ";
    cout.setf(ios::right, ios::adjustfield);
    cout.width(25);
    cout << setfill(' ') << dose;
    cout.setf(ios::left, ios::adjustfield);
    cout.width(20);
    cout << endl
         << "Center Allotted: ";
    cout.setf(ios::right, ios::adjustfield);
    cout.width(25);
    cout << setfill(' ') << center;
}
/*                            ===========================================================
                                                    MAIN FUNCTION
                              ===========================================================*/

int main()
{
    system("color B");
    vaccine_management system;
    system.menu();
}
