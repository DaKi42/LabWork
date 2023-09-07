#include<iostream>
using namespace std;

class Student
{
    char* name;
    int age;
    char* email;
public:
    Student()
    {
        cout << "Constructor\n";
        name = nullptr;
        age = 0;
        email = nullptr;
    }

    Student(const char* n, int a, const char* e)
    {
        name = new char[strlen(n) + 1];
        strcpy_s(name, strlen(n) + 1, n);
        age = a;

        email = new char[strlen(e) + 1];
        strcpy_s(email, strlen(e) + 1, e);

        cout << "Constructor 3 params\n";
    }

    const char* GetName() const
    {
        return name;
    }

    void SetName(const char* n)
    {
        if (name != nullptr)
        {
            delete[] name;
        }
        name = new char[strlen(n) + 1];
        strcpy_s(name, strlen(n) + 1, n);
    }

    int GetAge() const
    {
        return age;
    }

    void SetAge(int a)
    {
        age = a;
    }


    const char* GetEmail() const
    {
        return email;
    }

    void SetEmail(const char* e)
    {
        if (email != nullptr)
        {
            delete[] email;
        }
        email = new char[strlen(e) + 1];
        strcpy_s(email, strlen(e) + 1, e);
    }

    void Input()
    {
        char buff[20];
        cout << "Enter name: ";
        cin >> buff;
        SetName(buff);

        cout << "Enter age: ";
        cin >> age;

        char emailBuff[50];
        cout << "Enter email: ";
        cin >> emailBuff;
        SetEmail(emailBuff);
    }

    void Print()
    {
        cout << "Name: " << GetName() << "\tAge: " << GetAge() << "\tEmail: " << (GetEmail() ? GetEmail() : "Error") << endl;
    }

    ~Student()
    {
        delete[] name;
        delete[] email;
        cout << "Destructor\n";
    }
};

int main()
{
    Student obj1("Oleg", 20, "oleg@example.com");
    obj1.Print();
    obj1.Input();

    obj1.Print();
}
/* добавить:
   * поле емайл(char*)
   * конструктор  с 3я параметрами
   * методы аксессоры
   * удаление выделенной динамической памяти в деструкторе.
*/