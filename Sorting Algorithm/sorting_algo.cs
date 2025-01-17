using System;

namespace sorting_algo
{
  class Program
  { 

    static bool is_sorted(int[] array)
        {
            for (int i = 0; i < array.Length - 1; i++)
            {
                if (array[i] > array[i + 1])
                {
                    return false;
                }
            }
            return true;
        }

    static void Main(string[] args)
    {
        int[] array = {23, 5, 87, 12, 41, 3, 59, 74, 18, 62};
        while (!is_sorted(array))
        {
            for (int i = 0; i < length - 1; i++) {
            if (array[i] > array[i + 1]) {
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                }
            }
            Console.WriteLine("Sorted Array:");
            foreach (int num in array)
            {
                Console.Write(num + " ");
            }
            Console.WriteLine();
        }
    }
  }
}

