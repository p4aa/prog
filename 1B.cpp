//Implement application of array in polynomial expression.
#include <iostream>
using namespace std;

// Function to evaluate the polynomial
double evaluatePolynomial(double x, int degree, double coeffs[]) {
    double result = 0;
    for (int i = degree; i >= 0; i--) {
        result = result * x + coeffs[i];
    }
    return result;
}

int main() {
    int degree;
    double x, coeffs[50], result;

    cout << "Enter the degree of the polynomial: ";
    cin >> degree;
    cout << "Enter the value of x: ";
    cin >> x;

    cout << "Enter the coefficients of the polynomial in descending order: ";
    for (int i = 0; i <= degree; i++) {
        cin >> coeffs[i];
    }

    result = evaluatePolynomial(x, degree, coeffs);
    cout << "Result: " << result << endl;

    return 0;
}

//output:
//Enter the degree of the polynomial: 3
//Enter the value of x: 2
//Enter the coefficients of the polynomial in descending order: 1
//2
//3
//4
//Result: 49
