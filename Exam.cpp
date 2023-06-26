
#include <iostream>
#include<ctime>
using namespace std;
void copyArr(int** originalArr, int** copiedArr, int size1, int size2) {
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            copiedArr[i][j] = originalArr[i][j];
        }
    }
}
void pop(int*& arr, int index) {
    int size = _msize(arr) / sizeof(arr[0]);
    int *newArr = new int[size - 1];
    int count = 0;
    for (int i = 0; i < size;i++) {
        if (i != index) {
            newArr[count] = arr[i];
            count++;
        }
    }
    delete[] arr;
    arr = newArr;

}
void add1dto2d(int**& arr, int* arr2, int index,int size) {
    int** newArr = new int*[size+1];
    for (int i = 0; i < size + 1; i++) {
        newArr[i] = new int[size];
    }
    int count = 0;
    bool flag = false;
    for (int i = 0; i < size + 1; i++) {
        if(flag) {
            for (int j = 0; j < size; j++) {
                newArr[count][j] = arr[i - 1][j];
            }
        }
        else if (i != index) {
            for (int j = 0; j < size; j++) {
                newArr[count][j] = arr[i][j];
            }
        }
        else {
            for (int j = 0; j < size; j++) {
                newArr[count][j] = arr2[j];
                flag = true;
            }
        }
        count++;
    }

    for (int i = 0; i < size; i++) {
        delete[] arr[i];
    }
    delete arr;
    arr = newArr;
}


void deleteRow(int**& arr, int index, int size) {
    int** newArr = new int*[size - 1];
    for (int i = 0; i < size - 1; i++) {
        newArr[i] = new int[size];
    }
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (i != index) {
            for (int j = 0; j < size; j++) {
                newArr[count][j] = arr[i][j]; 
                
            }
            count++;
        }
    }
    for (int i = 0; i < size; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    arr = newArr;
}

int countNum(char* stroka) {
    int count = 0;
    int size = strlen(stroka);
    for (int i = 0; i < size; i++) {
        if (isdigit(stroka[i])) {
            count++;
        }
    }
    return count;
}

void DeleteMin(int**& arr, int size) {
    int** newArr = new int* [size - 1];
    for (int i = 0; i < size - 1; i++) {
        newArr[i] = new int[size];
    }
    int count = 0;
    int index = 0;
    int min = arr[0][0];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (min > arr[i][j]) {
                min = arr[i][j];
                index = i;
            }
        }
    }

    for (int i = 0; i < size; i++) {
        if (i != index) {
            for (int j = 0; j < size; j++) {
                newArr[count][j] = arr[i][j];

            }
            count++;
        }
    }
    for (int i = 0; i < size; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    arr = newArr;

}
int main()
{
    setlocale(LC_ALL, "RU");
    int max1;
    int num1 = 0;
    //first task
    cin >> max1;
    for (int i = 0; i < 3; i++) {
        cin >> num1;
        if (num1 > max1) {
            max1 = num1;
        }
    }
    cout << "Max is : " << max1 << endl;
    //end of first task

    //second task
    for (int i = 0; i < 41; i += 2) {
        cout << i << ' ';
    }
    cout << endl;
    // end of second task

    //thirtd task
    // 
    //end of third task


    //four task
    int number4;
    cin >> number4;
    int counter4 = 0;
    while (number4 > 0) {
        number4 /= 10;
        ++counter4;
    }
    cout << "Число имеет " << counter4 << " разярдов" << endl;
    //end of four task

    srand(time(NULL));
    //five task
    const int size = 10;
    int arr[size];
    int start, end;
    cin >> start >> end;
    if (start > end) {
        swap(start, end);
    }
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % ((end - start) + 1) + start;
    }
    for (int i = 0; i < size; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
    // end five stask

    //six task
    cout << endl;
    int size6 = 3;
    int** arr5 = new int* [size6];
    for (int i = 0; i < size6; i++) {
        arr5[i] = new int[size6];
        for (int j = 0; j < size6; j++) {
            arr5[i][j] = rand() % 11 + 1; //случайые жэлементы от 1 до 10
        }
    }
    int count6 = 0;
    int row6;
    for (int i = 0; i < size6; i++) { //Счет + вывод
        int counthelper6 = 0;
        for (int j = 0; j < size6; j++) {
            counthelper6 += arr5[i][j];
            cout << arr5[i][j] << ' ';
        }
        if (counthelper6 > count6) {
            count6 = counthelper6;
            row6 = i;
        }
        cout << endl;
    }
    cout << "Самая большая строчка " << row6 << endl;
    //six task end

    //seven task
    cout << endl;
    int size7 = 3;
    int** arr7first = new int* [size7];
    int** arr7two = new int* [size7];
    for (int i = 0; i < size7; i++) {
        arr7first[i] = new int[size7];
        for (int j = 0; j < size7; j++) {
            arr7first[i][j] = rand() % 11 + 1; //случайые жэлементы от 1 до 10
        }
    }
    for (int i = 0; i < size7; i++) {
        arr7two[i] = new int[size7];
    }

    for (int i = 0; i < size7; i++) { //вывод первого 
        for (int j = 0; j < size7; j++) {
            cout << arr7first[i][j] << ' ';

        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < size7; i++) { //вывод 2
        for (int j = 0; j < size7; j++) {
            cout << arr7two[i][j] << ' ';

        }
        cout << endl;
    }
    cout << endl << "ДО (сверху), ПОСЛЕ (снизу)" << endl;
    copyArr(arr7first, arr7two, size7, size7);
    for (int i = 0; i < size7; i++) { //вывод первого 
        for (int j = 0; j < size7; j++) {
            cout << arr7first[i][j] << ' ';

        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < size7; i++) { //вывод 2
        for (int j = 0; j < size7; j++) {
            cout << arr7two[i][j] << ' ';

        }
        cout << endl;
    }
    //seven task end

    //eight task
    cout << endl;
    int size8 = 10;
    int* arr8 = new int[size8];
    for (int i = 0; i < size8; i++) {
        arr8[i] = rand() % 11 + 1;
    }
    for (int i = 0; i < size8; i++) {
        cout << arr8[i] << ' ';
    }
    cout << endl;
    pop(arr8, 3);
    cout << "deletting elem at index 3:" << endl;
    for (int i = 0; i < size8-1; i++) {
        cout << arr8[i] << ' ';
    }
    //end of eight task

   // nine task

    cout << endl;
    cout << "task 9" << endl;
    int size9 = 3;
    int** arr9first = new int* [size9];
    int* arr9second = new int[size9];
    for (int i = 0; i < size9; i++) {
        arr9first[i] = new int[size9];
        for (int j = 0; j < size9; j++) {
            arr9first[i][j] = rand() % 11 + 1;
            cout << arr9first[i][j] << ' ';
        }
        cout << endl;
        
    }
    cout << endl << "second massive " << endl << endl;
    for (int i = 0; i < size9; i++) {
        arr9second[i] = rand() % 11 + 1;
        cout << arr9second[i] << ' ';
    }
    cout << endl << endl;

    add1dto2d(arr9first, arr9second, 1, size9);
    cout << "ДО (сверху) и После (снизу)" << endl;
    for (int i = 0; i < size9+1; i++) {
        for (int j = 0; j < size9; j++) {
            cout << arr9first[i][j] << ' ';
        }
        cout << endl;

    }
    cout << endl;

    // end nine task

   // ten task
    cout << endl << "10 zadanie" << endl;
    int size10 = 3;
    int** arr10first = new int* [size10];

    for (int i = 0; i < size10; i++) {
        arr10first[i] = new int[size10];
        for (int j = 0; j < size10; j++) {
            arr10first[i][j] = rand() % 11 + 1;
            cout << arr10first[i][j] << ' ';
        }
        cout << endl;

    }
    cout << endl << "ДО (СВЕРХУ) И ПОСЛЕ (СНИЗУ)" << endl;
    deleteRow(arr10first, 1, size10);
    for (int i = 0; i < size10 - 1; i++) {
        for (int j = 0; j < size10; j++) {
            cout << arr10first[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
    //ten end

    //11 zadanie
    int size11 = 3;
    int** arr11first = new int* [size11];

    for (int i = 0; i < size11; i++) {
        arr11first[i] = new int[size11];
        for (int j = 0; j < size11; j++) {
            arr11first[i][j] = rand() % 11 + 1;
            cout << arr11first[i][j] << ' ';
        }
        cout << endl;

    }
    DeleteMin(arr11first, size11);
    cout << endl << "ДО (СВЕРХУ) И ПОСЛЕ (СНИЗУ) 11" << endl;
    for (int i = 0; i < size11-1; i++) {
        for (int j = 0; j < size11; j++) {
            cout << arr11first[i][j] << ' ';
        }
        cout << endl;

    }
    cout << endl;
    //13 zadanie
    char stroka[8] = "25sg5ga";
    cout << "there is " << countNum(stroka) << " numbers" << endl;
    //end 13
}
