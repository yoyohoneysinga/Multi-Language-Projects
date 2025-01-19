#include <stdio.h>

int len_array(int array[])
{
    return sizeof(array) / sizeof(array[0]);
}

int is_sorted(int array[], int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        if (array[i] > array[i + 1])
        {
            return 0;
        }
    }
    return 1;
}

void main()
{
    int array[] = {23, 5, 87, 12, 41, 3, 59, 74, 18, 62};
    int length = len_array(array);

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

    printf("[");
    for (int i = 0; i < length; i++)
    {
        printf("%d", array[i]);
        if (i < length - 1)
        {
            printf(", ");
        }
    }
    printf("]\n");
}
