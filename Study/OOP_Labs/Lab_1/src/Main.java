/**
 * Laboratory work No. 1
 * @author Sergey Nischeglov 3312
 * @version 1.0
 *
 *
 *This is the Main class, I`d written my code here.
 */
public class Main {
    /**
     *
     * @param args - launch parameter
     */
    public static void main(String[] args) {

        int[] arr = {353, 345, 74, 2, 864, 234};

        // Calling the bubble sorting function.
        sortArr(arr);

        //Output of elements of a sorted array.
        System.out.println("An array sorted in descending order:");
        for (int i = 0; i < arr.length; i++) {
            System.out.println("arr[" + i + "] = " + arr[i]);
        }
    }

    /**
     *
     * @param arr - the array to be passed for sorting
     */
    public static void sortArr(int[] arr){
        for (int i = 0; i < arr.length - 1; i++){
            for (int j = 0; j < arr.length - i - 1; j++){
                if (arr[j] < arr[j+1]){
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
    }
}