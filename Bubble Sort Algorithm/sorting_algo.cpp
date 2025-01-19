#include <iostream>
using namespace std;

bool is_sorted(int array[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (array[i] > array[i + 1])
        {
            return false;
        }
    }
    return true;
}

void print_array(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main()
{
    int array[] = {23, 5, 87, 12, 41, 3, 59, 74, 18, 62};
    int length = sizeof(array) / sizeof(array[0]);

    while (!is_sorted(array, length))
    {
        for (int i = 0; i < length - 1; i++)
        {
            if (array[i] > array[i + 1])
            {
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
    }

    cout << "Sorted Array: ";
    print_array(array, length);

    return 0;
}
