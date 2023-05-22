#include <iostream>
#include <cstdlib>


using namespace std;


int number_of_comparisons = 0;
int *comp_ptr = &number_of_comparisons;

void display(int A[], int number_of_elements) {
    cout << "Array after sorted: ";

    for(int i = 0; i < number_of_elements; ++i) {
        cout << A[i] << " ";
    }
    cout << "\n";
}

//Partition Algorithm
int partition(int A[], int start, int end) {
    //Swapping random element
    int r = start + std::rand() % (end - start);
    std::swap(A[r], A[end]);

    int pivot = A[end];

    int i = start - 1;

    for(int j = start; j < end; ++j) {
        if(A[j] < pivot) {
            i += 1;
            std::swap(A[j], A[i]);
        }
        *comp_ptr += 1;
    }
    std::swap(A[i + 1], A[end]);

    return (i + 1);
}

//Quicksort Algorithm
void quicksort(int A[], int start, int end) {
    if(start < end) {
        int partition_index = partition(A, start, end);
        quicksort(A, start, partition_index - 1);
        quicksort(A, partition_index + 1, end);
    }
}

int main() {
    int number_of_elements;

    cout << "Enter number of elements in the array\n";
    cin >> number_of_elements;

    int a[number_of_elements] = {};

    cout << "Enter " << number_of_elements << " elements\n";
    for(int i = 0; i < number_of_elements; ++i) {
        cin >> a[i];
    }
  //  cout << "Array before Sorting: ";
    //display(a, number_of_elements);
    quicksort(a, 0, number_of_elements - 1);
    
    display(a, number_of_elements);

    cout << "\nNumber of comparisons: " << number_of_comparisons << "\n";
    return 0;
}