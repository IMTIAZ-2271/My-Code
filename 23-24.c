/*
1.(a)
Necessity of null character in strings:

In C, strings are represented as arrays of
characters terminated by a null character ('\0').
This null character is crucial for several reasons:

1. String Termination: It indicates the end of the string,
   allowing functions to determine where the string ends.

2. Memory Management: It helps in managing memory by clearly
   defining the boundaries of the string.

3. Compatibility: Many C standard library functions rely on
   the null character to process strings correctly.
   Without the null character, string manipulation functions
   would not work as intended, leading to undefined behavior
   and potential security vulnerabilities.

(b)
#include <stdio.h>
#include <string.h>
void reverseString(char* str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

(c)
#include<stdio.h>
#include<string.h>
char* custom_strtok(char* str, const char* delim) {
    static char* last;
    if (str) last = str;
    if (!last) return NULL;
    char* start = last;
    while (*start && strchr(delim, *start)) start++;
    if (!*start) {
        last = NULL;
        return NULL;
    }
    char* end = start;
    while (*end && !strchr(delim, *end)) end++;
    if (*end) {
        *end = '\0';
        last = end + 1;
    } else {
        last = NULL;
    }
    return start;
}

(d)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<math.h>
int main(){
char str[101];
fgetd(str,101,stdin);
str[strcspn(str, "\n")] = 0;
int len = strlen(str);
int d= 0;
for(int i = 0 ; i < len ; i++){
    if(str[i] >= '0' && str[i] <= '9'){
        d+= (str[i]-'0')*pow(16,len-i-1);
    }
    else{
        d+= (str[i]-'A'+10)*pow(16,len-i-1);
    }
 }
    char octal[101];
    int index = 0;
    while(d > 0){
        octal[index++] = (d%8)+'0';
        d/=8;
    }
    // Reverse the octal representation
    for(int i = 0; i < index/2; i++){
        char temp = octal[i];
        octal[i] = octal[index-i-1];
        octal[index-i-1] = temp;
    }
    octal[index] = '\0';
    printf("%s\n", octal);
}
    
    2.
(a)A[i][j][k] ≡ A[i*m*n + j*n + k]
(b)r  ≡ opens file for reading
   w  ≡ opens or creates file for writing
   a  ≡ opens or creates file for appending
   r+ ≡ opens file for both reading and writing
   w+ ≡ opens or creates file for both reading and writing (truncates file)
   a+ ≡ opens or creates file for both reading and appending
(c)
#include <stdio.h>
int main() {
    int a[n][m];
    int total[n]={0};
    int max_marks[m]={-1};
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            printf("Enter marks for student %d in subject %d: ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
            total[i] += a[i][j];
        }
    }
    for(int j = 0; j < m; j++) {
        for(int i = 0; i < n; i++) {
            if(a[i][j] > max_marks[j]) {
                max_marks[j] = a[i][j];
            }
        }
    }
    printf("Total marks for each student:\n");
    for(int i = 0; i < n; i++) {
        printf("Student %d: %d\n", i + 1, total[i]);
    }
    printf("Maximum marks in each subject:\n");
    for(int j = 0; j < m; j++) {
        printf("Subject %d: %d\n", j + 1, max_marks[j]);
    }
    return 0;
}
(d)
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
FILE* fp = fopen("in.txt","w+");
if(!fp){
    return 1;}
int students;
scanf("%d",&students);
int m;
scanf("%d",&m);
for(int i=0;i<students;i++){
    fprintf(fp,"Student %d =>\n",i+1);
    for(int j=0;j<m;j++){
        int mark;
        scanf("%d",&mark);
        fprintf(fp,"Subject %d : %d\n",j+1,mark);
    }
}
    // make sure we read from the beginning of the file we just wrote 
    fflush(fp);
    fseek(fp, 0, SEEK_SET);
for(int i = 0 ; i < students ; i++){
    int id;
    fscanf(fp,"Student %d =>\n",&id);//Be careful when reading data from a text
                                     //file. Ensure the written format.
    printf("Student %d =>\n",id);
    for(int j = 0 ; j < m ; j++){
        int mark;
        int p;
        fscanf(fp,"Subject %d : %d\n",&p,&mark);
        printf("Subject %d : %d\n",p,mark);
    }
}

fclose(fp);
return 0;
}


  3.

(a)
Two different ways to implement the three-dimensional array using pointer:
 1. Using a single pointer with dynamic memory allocation:
   int ***A;
   A = (int ***)malloc(x * sizeof(int **));
   for (int i = 0; i < x; i++) {
       A[i] = (int **)malloc(y * sizeof(int *));
       for (int j = 0; j < y; j++) {
           A[i][j] = (int *)malloc(z * sizeof(int));
       }
   }
 2. Using a single contiguous block of memory:
    int *A=(int *)malloc(x * y * z * sizeof(int));
    //Access element A[i][j][k] as A[(i*y*z) + (j*z) + k];

(b)
I can do memory allocation in C by using pointer and the functions
malloc() or calloc().
Memory leakage: It occurs dynamically allocated memory is not freed.

Preventing Memory Leakage: Always free dynamically allocated memory using
 free() when it is no longer needed.

(c)
#include<stdio.h>
#include<stdlib.h>

int** allocate2DArray(int** arr, int rows, int cols) {
    int** arr = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        arr[i] = (int*)malloc(cols * sizeof(int));
    }
    return arr;
}
void getelements(int** array, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &array[i][j]);
        }
    }
}
void printelements(int** array, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}
int** addition(int** A, int** B, int rows, int cols) {
    int** C = allocate2DArray(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return C;
}

int** substraction(int** A, int** B, int rows, int cols) {
    int** C = allocate2DArray(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
    return C;
}
int** multiplication(int** A, int** B, int rowsA, int colsA, int colsB) {
    int** C = allocate2DArray(rowsA, colsB);
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            C[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}
void free2DArray(int** array, int rows) {
    for (int i = 0; i < rows; i++) {
        free(array[i]);
    }
    free(array);
}
int main() {
    int rowsA, colsA, rowsB, colsB;
    printf("Enter rows and columns for first matrix: ");
    scanf("%d %d", &rowsA, &colsA);
    printf("Enter rows and columns for second matrix: ");
    scanf("%d %d", &rowsB, &colsB);
    if (colsA != rowsB) {
        printf("Matrix multiplication not possible.\n");
        return 1;
    }
    int** A = allocate2DArray(rowsA, colsA);
    int** B = allocate2DArray(rowsB, colsB);
    printf("Enter elements of first matrix:\n");
    getelements(A, rowsA, colsA);
    printf("Enter elements of second matrix:\n");
    getelements(B, rowsB, colsB);
    int** sum = addition(A, B, rowsA, colsA);
    int** diff = substraction(A, B, rowsA, colsA);
    int** prod = multiplication(A, B, rowsA, colsA, colsB);
    printf("Sum of matrices:\n");
    printelements(sum, rowsA, colsA);
    }
    printf("Difference of matrices:\n");
    printelements(diff, rowsA, colsA);
    printf("Product of matrices:\n");
    printelements(prod, rowsA, colsB);
    free2DArray(A, rowsA);
    free2DArray(B, rowsB);
    free2DArray(sum, rowsA);
    free2DArray(diff, rowsA);
    free2DArray(prod, rowsA);
    return 0;
}


4.
(a)
When we try to copy a struct into other struct using assignment operator,
it perfoms a shallow copy. If the struct contains pointers,
both structs will point to the same memory location.So modifying one struct
will affect the other struct. Again, if we free the memory of one struct,
the other struct will have a dangling pointer, leading to undefined behavior.

To avoid this, we can perform a deep copy by manually copying each member
of the struct, including allocating new memory for any pointers.

(b)Enumeration is used to save computer memory.
   It is user-defined data type.
   It makes a program easy to read and maintain.
   example:
    enum Day { Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday };
    Day today = Wednesday;








    5.
(a)
Output:
    ABCDEF
    BCDEFA
    CDEFAB
    DEFABC
    EFABCD
    FABCDE
    ABCDEF
(b)
  #include<stdio.h>

int is_prime(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}
int main(){
    int k;
    scanf("%d",&k);
    if(k<=1){
    printf("None");
    return 1;
    }
    int i = 2;
    while(i<=k){
        if(is_prime(i) && is_prime(2*i+1)){
            printf("%d ",i);
        }
        if(i==2){
            i++;
        }
        else{
            i+=2;
        }
    }
    return 0;
}
(c)
#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    if((n%2) * (n%5)){
        printf("No\n");
    }
    else{
        printf("Yes\n");
    }
    return 0;
}
6.
(a)
#include<stdio.h>
int countMinBits(int n){
    if(n == 0) return 1; 
    int cnt = 0;
    while(n){
        n>>=1;
        cnt++;
    }
    return cnt;
}
(b)
int findTrailingZeros(int n){
    if(n == 0) return 1;
    int cnt = 0;
    while((n&1) == 0 && n){ // Aware of n=0 case
        cnt++;
        n>>=1;
    }
    return cnt;
}
7.
(a)

#include <stdio.h>
#include <limits.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int maximum = arr[0];
    int minimum = arr[0];
    int ascending = 1, descending = 1;
    int unique_sum = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] > maximum) maximum = arr[i];
        if (arr[i] < minimum) minimum = arr[i];
        if (arr[i] < arr[i - 1]) ascending = 0;
        if (arr[i] > arr[i - 1]) descending = 0;
    }
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (arr[i] == arr[j]) count++;
            if (count > 1) break;
        }
        if (count == 1) unique_sum += arr[i];
    }
    if (ascending) printf("A\n");
    else if (descending) printf("D\n");
    else printf("U\n");

    printf("%d\n", maximum - minimum);
    printf("%d\n", unique_sum);

    return 0;
}


(b)
int calculateHindex(int C[], int n) {
    int h_index=0;
    for(int i=0; i<n; i++){
        if(C[i]>=3){
            h_index++;
        }
        else{
            break;
        }    
    }
    return h_index;
}


(c)
int allRepeated(int x){
    if(x==0){return 0;}
    while(x){
        int s=x%100;
        if((s/10)^(s%10)){
            return 0;
        }
        x/=100;
    }
    return 1;
}

(d)
int strRlen(char s[]) {
    if (*s == '\0') return 0;     
    return 1 + strRlen(s + 1);  
}














































*/