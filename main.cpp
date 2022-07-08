#include <iostream>
#include <random>
#include <time.h>
#include <fstream>
#include <string>

using namespace std;

struct students
{
    string FIO;//80-n
    unsigned int age; //4
    string sex;//n=40
    unsigned int course; //4
    unsigned int mark; //4
};

//PROTOTYPE
void create(students*, int);

//FILL 3 SLOTS WITH STUDENTS
students fill_(students* arr, int N)
{

    arr[0].FIO = "Ivanov I.I."; arr[1].FIO = "Abdul P.D."; arr[2].FIO = "Redy S.I.";
    arr[0].age = 18; arr[1].age = 19; arr[2].age = 20;
    arr[0].sex = "male"; arr[1].sex = "male"; arr[2].sex = "female";
    arr[0].course = 3; arr[1].course = 3; arr[2].course = 2;
    arr[0].mark = 6; arr[1].mark = 10; arr[2].mark = 9;
    return *arr;
}

//INDIVIDULA EX
void ind(students* arr, int N, int num)
{
    ofstream file("D:\\C\\inputIND.txt");
    file << "FIO" << '\t' << '\t' << '\t'<< '\t' << "age" << '\t' << "sex" << '\t' << "course" << '\t' << "mark" << '\n';
    for (int i = 0; i < N; i++)
    {
        if (arr[i].sex != "male" && arr[i].sex != "female") break;
        if(arr[i].course == num)
            file << arr[i].FIO << '\t' << '\t' << '\t'<< '\t' << arr[i].age << '\t' << arr[i].sex << '\t' << arr[i].course << '\t' << arr[i].mark << '\n';
    }
    file.close();
}

//OUTPUT DESK OF FILE
void output(students* arr, int N)
{
    create(arr, N);
    ifstream file("D:\\C\\input.txt");
    string stroka;
    while (!file.eof())
    {
        getline(file, stroka);
        cout << stroka << endl;;
    }
    file.close();
}

//DELETE NUM
void del_(students* arr, int N, int num)
{
    students* time_arr = new students[N - 1];
    for (int i = 0; i < N - 1; i++)
    {
        if (i < num - 1)
        {
            time_arr[i] = arr[i];
        }
        else
        {
            time_arr[i] = arr[i + 1];
        }
    }
    for (int i = 0; i < N - 1; i++)
    {
        arr[i] = time_arr[i];
    }
    delete[]time_arr;
}

//CREATE FILE
void create(students* arr, int N)
{
    ofstream file("D:\\C\\input.txt");
    file << "FIO" << '\t'  << '\t' << "age" << '\t' << "sex" << '\t' << "course" << '\t' << "mark" << '\n';
    for (int i = 0; i < N; i++)
    {
        if (arr[i].sex != "male" && arr[i].sex != "female") break;
        file << arr[i].FIO << '\t' << arr[i].age << '\t' << arr[i].sex << '\t' << arr[i].course << '\t' << arr[i].mark << '\n';
    }
    file.close();
}

//CREATE FILE IN BIN
void binIN(students* arr, int N)
{
    ofstream file("D:\\C\\inputBIN.txt", ios::binary);
    students a;
    for (int i = 0; i < N; i++)
    {
        if (arr[i].sex != "male" && arr[i].sex != "female") break;
        a = arr[i];
        file.write((char*)&a, sizeof(a));
    }
    file.close();
    ifstream file2("D:\\C\\inputBIN.txt", ios::binary);
    while (file2.read((char*)&a, sizeof(a))) {
        cout << a.FIO << '\t' << a.age << '\t' << a.sex << '\t' << a.course << '\t' << a.mark << '\n';
    }
    file2.close();

}

//ADD ELEMENT
void addic(students* arr, int N)
{
    for (int i = 0; i < N; i++)
    {
        if (arr[i].sex != "male" && arr[i].sex != "female")
        {
            string s; string str;
            cout<< "FIO" << '\t' << '\t' << '\t' << "age" << '\t' << "sex" << '\t' << "course" << '\t' << "mark" << '\n';
            cin >> str; getline(cin, s); arr[i].FIO = str+s; cout << '\t' << '\t' << '\t';
            cin >> arr[i].age; cout <<'\t' << '\t' << '\t' << '\t';
            cin >> arr[i].sex; cout <<'\t' << '\t' << '\t' << '\t' << '\t';
            cin >> arr[i].course; cout <<  '\t' << '\t' << '\t' << '\t' << '\t' << '\t';
            cin >> arr[i].mark; cout << '\n';
            break;
        }
    }
}

//CHANGE ELEMENT
void Reverse(students* arr, int N, int num)
{
    num -= 1; string s; string str;
    cout << "FIO" << '\t' << '\t' << '\t' << "age" << '\t' << "sex" << '\t' << "course" << '\t' << "mark" << '\n';
    cout << arr[num].FIO << '\t' << '\t' << arr[num].age << '\t' << arr[num].sex << '\t' << arr[num].course << '\t' << arr[num].mark << '\n';
    cin >> str; getline(cin, s); arr[num].FIO = str + s; cout << '\t' << '\t' << '\t';
    cin >> arr[num].age; cout << '\t' << '\t' << '\t' << '\t';
    cin >> arr[num].sex; cout << '\t' << '\t' << '\t' << '\t' << '\t';
    cin >> arr[num].course; cout << '\t' << '\t' << '\t' << '\t' << '\t' << '\t';
    cin >> arr[num].mark; cout << '\n';
}

int main()
{
    int N = 20;  students* arr = new students[N]; int num = NULL;
    //F.write((char*)&S,sizeof(S));
    srand(time(NULL));
    setlocale(LC_ALL, "RU");
    fill_(arr, N);
    int what = NULL;
    while (true) {
        cout << "1-output,2 - create file, 3 - del,4-add,5-change, 6-ind, 7-exit, 8 - bin: ";
        cin >> what;
        switch (what)
        {
            case(1):output(arr, N); break;
            case(2):create(arr, N); break;
            case(3):cout << "\nnum of an element: "; cin >> num; del_(arr, N, num); break;
            case(4):addic(arr, N); break;
            case(5):cout << "\nnum of an element: "; cin >> num; Reverse(arr, N, num); break;
            case(6):cout << "\nnum of a course: "; cin >> num; ind(arr, N, num); break;
            case(8):binIN(arr, N); break;
            default:delete [] arr; return 0;
        }
    }
}
