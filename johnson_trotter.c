#include <stdio.h>
#include <stdbool.h>
#define MAX_N 5
#define LEFT -1
#define RIGHT 1
int permutation[MAX_N];
int direction[MAX_N];
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int largest_mobile_element(int n) {
    int largest = -1;
    int largest_index = -1;
    for (int i = 0; i < n; i++) {
        if ((direction[i] == LEFT && i > 0 && permutation[i] > permutation[i-1]) ||
            (direction[i] == RIGHT && i < n-1 && permutation[i] > permutation[i+1])) {
            if (permutation[i] > largest) {
                largest = permutation[i];
                largest_index = i;
            }
        }
    }
    return largest_index;
}
void print_permutation_and_directions(int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", permutation[i]);
    }
    printf(" | Directions: ");
    for (int i = 0; i < n; i++) {
        printf("%s ", direction[i] == LEFT ? "L" : "R");
    }
    printf("\n");
}
void johnson_trotter(int n) {
    for (int i = 0; i < n; i++) {
        permutation[i] = i + 1;
        direction[i] = LEFT;
    }
    print_permutation_and_directions(n);
    while (true) {
        int largest_index = largest_mobile_element(n);
        if (largest_index == -1) {
            break;
        }
        int mobile_value = permutation[largest_index];
        int swap_index = (direction[largest_index] == LEFT) ? largest_index - 1 : largest_index + 1;
        swap(&permutation[largest_index], &permutation[swap_index]);
        swap(&direction[largest_index], &direction[swap_index]);
        print_permutation_and_directions(n);
        for (int i = 0; i < n; i++) {
            if (permutation[i] > mobile_value) {
                direction[i] = (direction[i] == LEFT) ? RIGHT : LEFT;
            }
        }
    }
}
int main() {
    int n;
    printf("Enter the value of n (number of elements): ");
    scanf("%d", &n);
    if (n > MAX_N) {
        printf("n is too large! Maximum is %d.\n", MAX_N);
        return 1;
    }
    johnson_trotter(n);
    return 0;
}

/* Output: 
Enter the value of n (number of elements): 3
1 2 3  | Directions: L L L
1 3 2  | Directions: L L L
3 1 2  | Directions: L L L
3 2 1  | Directions: L L L
2 3 1  | Directions: L R L
2 1 3  | Directions: L L R

*/
