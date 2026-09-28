#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

void TextFileEaxample();

struct Employee
{
    char name[20];
    int age;
    float salary;
    bool admin;
};

Employee CreateEmployee(
    const char* name,
    int age,
    float salary,
    bool admin);

int main()
{
    //Employee bob = CreateEmployee("Bobby", 28, 120000.00, true);
    
    //FILE* file = fopen("fileEmployee.dat", "rb+");

    //fwrite(&bob, sizeof(bob), 1, file);

    //Employee empl;
    //
    //fread(&empl, sizeof(empl), 1, file);
    //std::cout << empl.name << " " <<
    //    empl.age << " " <<
    //    empl.salary << " " <<
    //    empl.admin << "\n";

    //fclose(file);

    //int n{ 123 };
    //void* buffer{ &n };
    //float* x = (float*)buffer;
    //std::cout << *x << "\n";

    //float y{ 123.0 };
    //buffer = &y;
    //int* iptr = (int*)buffer;
    //std::cout << *iptr << "\n";
}

void TextFileEaxample()
{
    char fileName[] = "file01.dat";

    FILE* file = fopen(fileName, "r+");

    //
    int position{ 5 };
    char dollars[] = "$$$";

    fseek(file, position, SEEK_SET);
    char* save = new char;

    while (!feof(file))
    {
        char buffer[10]{};
        fgets(buffer, 10, file);
        strcat(save, buffer);
    }

    fseek(file, position, SEEK_SET);
    fputs(dollars, file);
    fputs(save, file);

    fclose(file);
}

Employee CreateEmployee(const char* name, int age, float salary, bool admin)
{
    Employee employee;
    
    strcpy_s(employee.name, name);
    employee.age = age;
    employee.salary = salary;
    employee.admin = admin;

    return employee;
}
