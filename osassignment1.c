#include <math.h>
#include <stdio.h>

int main();
void print_arr(int arr[], int len);
void print_str(char arr[]);
int inflation(int current_price, int num_years, float rate);
float arr_average(int arr[], int len);
void arr_fill(int array[], int array_len, int begin, int end);
int uppercase_count(char word[]);
void string_concatenation(char a[], char b[], char c[]);

/**
 * @brief Main method to test assignment methods
 * 
 * @return int 
 */
int main() {
    //inflation test
    printf("1000 for 1 year 0.1 interest. Expected: 1100 Actual: %d", inflation(1000, 1, 0.1));
    printf("\n1000 for 2 year 0.1 interest. Expected: 1210 Actual: %d", inflation(1000, 2, 0.1));
    printf("\n1000 for 3 year 0.1 interest. Expected: 1331 Actual: %d", inflation(1000, 3, 0.1));

    //arr average test
    int test_arr[1];
    printf("\nArray average test. Expected: 0.0 Actual: %.1f", arr_average(test_arr, -1));
    int test_arr2[] = {2, 3, 4};
    printf("\nArray average test. Expected: 3.0 Actual: %.1f", arr_average(test_arr2, 3));
    int test_arr3[] = {1, 2, 3, 4, 5, 6, 7};
    printf("\nArray average test. Expected: 4.0 Actual %.1f", arr_average(test_arr3, 7));

    //print array test
    int a3[] = {1, 2, 3};
    printf("\nPrint array test. Expected {1, 2, 3} Actual: ");
    print_arr(a3, 3);
    int a4[] = {15, 32, -3, 2, 5};
    printf("\nPrint array test. Expected {15, 32, -3, 2, 5} Actual: ");
    print_arr(a4, 5);

    //array fill test
    int a1[4];
    arr_fill(a1, 4, 11, 12);
    printf("\nArray fill a1[4] with bounds (11, 12). Expected {11, 12} Actual: ");
    print_arr(a1, 2);
    int a2[15];
    arr_fill(a2, 6, 0, 5);
    printf("\nArray fill a2[6] with bounds (0, 5). Expected {0, 1, 2, 3, 4, 5} Actual: ");
    print_arr(a2, 6);

    //uppercase count test
    char s1[] = "THIS HAS 7 uppercase characters.";
    char s2[] = "THIS HAS 16 UPPERCASE characters.";
    char s3[] = "THIS HAS 26 UPPERCASE CHARACTERS.";
    printf("\nUppercase count s1. Expected: 7 Actual: %d", uppercase_count(s1));
    printf("\nUppercase count s2. Expected: 16 Actual: %d", uppercase_count(s2));
    printf("\nUppercase count s3. Expected: 26 Actual: %d", uppercase_count(s3));

    //print string test
    char s8[] = "s8 printed successfully";
    char s9[] = "s9 printed successfully";
    printf("\nPrint string test. Expected \"s8 printed successfully\" Actual: \"");
    print_str(s8);
    printf("\"");
    printf("\nPrint string test. Expected \"s9 printed successfully\" Actual: \"");
    print_str(s9);
    printf("\"");

    //string concatenation test
    char s4[] = "AAA";
    char s5[] = "BBB";
    char r1[10];
    //updates r1
    string_concatenation(s4, s5, r1);
    printf("\nString concatentation test. Expected: \"AAABBB\" Actual: \"");
    print_str(r1);
    printf("\"");
    char s6[] = "Test";
    char s7[] = "Words";
    char r2[20];
    string_concatenation(s6, s7, r2);
    printf("\nString concatentation test. Expected: \"TestWords\" Actual: \"");
    print_str(r2);
    printf("\"");


    

    //print string test

    


}

/**
 * @brief Prints out an integer array
 * 
 * @param arr 
 * @param len 
 */
void print_arr(int arr[], int len) {
    int i = 0;
    printf("{");
    while (i < len) {
        printf("%d", arr[i]);
        if (i + 1 < len) {
            printf(", ");
        }
        i++;
    }
    printf("}");
    return;
}

/**
 * @brief Print out a char array character by character
 * 
 * @param arr 
 */
void print_str(char arr[]) {
    int i = 0;
    while (arr[i] != '\0') {
        printf("%c", arr[i]);
        i++;
    }
    return;
}

/**
 * @brief Takes a price, numbers of years, and inflation rate, and returns the resulting inflation price
 * 
 * @param current_price 
 * @param num_years 
 * @param rate 
 * @return int 
 */
int inflation(int current_price, int num_years, float rate) {
    if (num_years < 0 || rate < 0 || current_price < 0) {
        return -1;
    }
    //printf("Current price %d", current_price);
    for (int i = 0; i < num_years; i++)
    {
        current_price += (int)((current_price * rate));
        //printf("Current price %d", current_price);
    }
    return current_price;
}


/**
 * @brief Takes an array of ints and returns a float of the average value
 * 
 * @param arr 
 * @param len 
 * @return float 
 */
float arr_average(int arr[], int len) {
    if (arr == NULL || len <= 0) {
        return 0.0;
    }

    int totalSum = 0;
    for (int i = 0; i < len; i++) {
        totalSum += arr[i];
    }

    return (double)(totalSum)/len;
}

/**
 * @brief Fills an array by incrementing numbers in input bounds
 * 
 * @param arr 
 * @param arr_len 
 * @param begin 
 * @param end 
 */
void arr_fill(int arr[], int arr_len, int begin, int end) {
    for (int i = 0; i < arr_len; i++) {
        if (i + begin > end) {
            arr[i] = '\0';
            return;
        }
        arr[i] = i + begin;
    }
}

/**
 * @brief Returns the number of uppercase characters in string
 * 
 * @param word 
 * @return int 
 */
int uppercase_count(char word[]) {
    int i = 0;
    int uppercase_amt = 0;
    while (word[i] != '\0') {
        if (word[i] >= 'A' && word[i] <= 'Z') {
            uppercase_amt++;
        }
        i++;
    }
    return uppercase_amt;
}

/**
 * @brief Appends string b to string a
 * 
 * @param a 
 * @param b 
 * @param c 
 */
void string_concatenation(char a[], char b[], char c[]) {
    int i = 0;
    while (a[i] != '\0') {
        c[i] = a[i];
        i++;
    }
    int j = 0;
    while (b[j] != '\0') {
        c[i] = b[j];
        i++;
        j++;
    }
    c[i] = '\0';
}