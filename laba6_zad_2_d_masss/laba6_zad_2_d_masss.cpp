//поменять местами левую и правую части матрицы. Динаический
#include <iostream>
#include <clocale>

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    int N, M;

    cout << "Введите размер матрицы M*N:\n";
    cin >> M;
    if (M <= 0 || M > 10) {
        cerr << "Ошибка: количество должно находиться в диапазоне [1;10]" << endl;
        return 1;
    }

    cin >> N;
    if (N <= 0 || N > 10) {
        cerr << "Ошибка: количество должно находиться в диапазоне [1;10]" << endl;
        return 1;
    }
    int** array;
    array = new int* [M];
    for (size_t i = 0; i < M; i++) {
        // Выделение памяти под строки матрицы
        // последний элемент массива - сумма оценок
        array[i] = new int[N];
    }

    cout << "Введите набор из " << N << " чисел: ";
    // выводим
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> array[i][j];
        }
    }


    // меняем местами
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N / 2; j++)
        {
            int temp = array[i][j];//сщхраняем изначальное значение
            array[i][j] = array[i][j + N / 2];
            array[i][j + N / 2] = temp;
        }
    }
    // опять выводим
    cout << endl;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << array[i][j];
        }
        cout << endl;
    }
    for (size_t i = 0; i < M; i++) {
        delete[] array[i];
    }
    delete[] array;

}