#include "complex_num.h"

complex_num::complex_num(double r, double i){
     // Write your code here
    real = r;
    imaginary = i;
}

complex_num complex_num::operator +(complex_num w){
    complex_num z;
    // Write your code here
    // z+w = (a+ib)+(c+id) = (a+c) + i(b+d)
    z.real = real + w.real;
    z.imaginary = imaginary + w.imaginary;
    return z;
}

complex_num complex_num::operator -(complex_num w){
    complex_num z;
    // Write your code here
    // z-w = (a+ib)-(c+id) = (a-c) + i(b-d)
    z.real = real - w.real;
    z.imaginary = imaginary - w.imaginary;
    return z;
}

complex_num complex_num::operator *(complex_num w){
    complex_num z;
    // Write your code here
    // z*w = (a+ib)*(c+id) = (ac-bd) + i(ad+bc)
    z.real = (real * w.real) - (imaginary * w.imaginary);
    z.imaginary = (real * w.imaginary) + (imaginary * w.real);
    return z;
}

complex_num complex_num::operator /(complex_num w){
    complex_num z;
    // Write your code here
    // z/w = (a+ib)/(c+id) = 
    //   ((ac+bd)/(c^2+d^2)) + i((bc-ad)/(c^2+d^2))
    double cSq = w.real * w.real;
    double dSq = w.imaginary * w.imaginary;
    z.real = (real * w.real) + (imaginary * w.imaginary);
    z.imaginary = (imaginary * w.real) - (real * w.imaginary);
    z.real = z.real / (cSq + dSq);
    z.imaginary = z.imaginary / (cSq + dSq);
    return z;
}

void complex_num::print(std::ostream &os){
    std::cout << real;
    if (imaginary != 0) {
        std::cout << " + " << imaginary << + "i";
        std::cout << std::flush;
    }
}

// Answers
// z + w = 8 + 5i
// z - w = 12 + 5i
// z * w = -20 - 10i
// z / w = -5 - 2.5i