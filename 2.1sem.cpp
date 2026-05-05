// 2.1sem.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <fstream>
#include <string.h>
#include "Student.h"
#include <iostream>
#include <cstdlib>
#include "sort.h"

using namespace std;

bool compStudent(Student a, Student b) {
    return a.getAverage() > b.getAverage();

}

int main()
{
    const int max_Student = 20;
    Student gr[max_Student];
    ifstream in("text.txt");
    int n = 0;
    while (in >> gr[n] && n < 10) {
        n++;
    }
    in.close();
  

    Student copy[max_Student];


    //пузырьковая
    for (int i = 0; i < n; i++) copy[i] = gr[i];
    booblesort(copy, n);
    cout << "\n after booblesort:\n";
    for (int i = 0; i < n; i++)
        cout << copy[i];

    //вставками
    for (int i = 0; i < n; i++) copy[i] = gr[i];
    insert(copy, n);
    cout << "\n after insert:\n";
    for (int i = 0; i < n; i++)
        cout << copy[i];

    //выбором
    for (int i = 0; i < n; i++) copy[i] = gr[i];
    select(copy, n);
    cout << "\n after select:\n";
    for (int i = 0; i < n; i++)
        cout << copy[i];

    /*шелла*/
   for (int i = 0; i < n; i++) copy[i] = gr[i];
    shell(copy, n);
    cout << "\n after shell:\n";
    for (int i = 0; i < n; i++)
        cout << copy[i];

    /*Быстрая qsort*/
    for (int i = 0; i < n; i++) copy[i] = gr[i];
    qsort(copy, 0,n-1);
    cout << "\n after qsort:\n";
    for (int i = 0; i < n; i++)
        cout << copy[i];




    ofstream of = ofstream("student.bin");
    of.write((char*)gr, n * sizeof(Student));
    of.close();
    ifstream in1 = ifstream("student.bin");
    //длина файла
    in1.seekg(0, in1.end);//устанавливает указатель файла в конец
    int dl_fila = in1.tellg();
    //кол-во записей
    int nZ = dl_fila / sizeof(Student);
    Student* arr = new Student[nZ];
    in1.seekg(0, ios::beg);
    in1.read((char*)arr, dl_fila);;
    /*for (int i = 0; i < nZ; i++)
        cout << arr[i].fullName << "" << arr[i].groupNumber << endl;*/
    bool a = gr[1] > gr[0];
    std::cout << "\n" << a << "\n";

    std::cout << "\nStudents with avarage > 4.0:" << std::endl;
    for (int i = 0; i < n; i++) {
        if (gr[i].getAverage() > 4.0) {
            std::cout << gr[i].fullName << " " << gr[i].groupNumber << std::endl;
        }
    }

    return 0;
}
   


 
//template <class T>
//void boobleSort(T* a, int n) {
//    int flag = 1;
//    T h;
//    while (flag) {
//        flag = 0;
//        for (int i = 1; i < n; i++) {
//            if (a[i - 1] > a[i]) {
//                h = a[i - 1];
//                a[i - 1] = a[i];
//                a[i] = h;
//                flag = 1;
//            }
//        }
//    }
//}

//int compQsortInt(const void* a, const void* b) {
//    int* pa = (int*)a;
//    int* pb = (int*)b;
//    int r = *pa - *pb;
//    //return *((int*)a) - *((int*)b);
//    return r;
//}
//int main() {
//    int arr[8] = { 12,42,18,44,55,67,94,6 };
//    qsort(arr, 8, sizeof(int), compQsortInt);
//
//}
