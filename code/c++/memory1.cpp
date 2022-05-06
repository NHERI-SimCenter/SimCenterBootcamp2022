#include <iostream>

int main(int argc, char **argv) {
  int n;
  double *array1, *array2, *array3;

  std::cout << "enter n: ";
  std::cin >> n;

  // allocate memory & set the data
  array1 = new double[n];
  for (int i=0; i<n; i++) {
    array1[i] = 0.5*i;
  }
  
  array2 = array1;
  array3 = &array1[0];
  
  for (int i=0; i<n; i++, array3++) {
    double value1 = array1[i];
    double value2 = *array2++;
    double value3 = *array3;
    printf("%.4f %.4f %.4f\n", value1, value2, value3);
  }

  // free the array
  delete array1;
}
