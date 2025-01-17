import java.util.Arrays;

public class sorting_algo {
    
    private static boolean is_sorted(int[] array){
        for (int i = 0; i < array.length - 1; i++){
            if (array[i] > array[i + 1]) {
                return false;
            }
        }
        return true;
    }

    public static void main(String args[]){
        int[] array = {23, 5, 87, 12, 41, 3, 59, 74, 18, 62};
        while (!is_sorted(array)) {
            for (int i = 0; i < array.length - 1; i++){
                if (array[i] > array[i + 1]) {
                    int temp = array[i];
                    array[i] = array[i + 1];
                    array[i + 1] = temp;
                }
            }
        }
        System.out.println(Arrays.toString(array));
    }

}
