//
// Created by ilya on 19.05.21.
//

#ifndef UNTITLED_VECTOR_OUT_H
#define UNTITLED_VECTOR_OUT_H

template<class T>
void write_vector(const std::vector<T>& vector) {
    std::cout << "Numbers you entered: ";
    std::copy(vector.begin(), vector.end(),
              std::ostream_iterator<T>(std::cout, " "));
    std::cout << '\n';
}

//int main():{
//write_vector(arraynum);
// instead loop entering:
// std::copy(std::istream_iterator<int>(stream),
//        std::istream_iterator<int>(),
//        std::back_inserter(numbers)
//}


//    try
//    {

//    }
//    catch (const std::exception & ex)
//    {
//        std::cout << "out_of_range Exception Caught :: " << ex.what() << std::endl;
//    }

#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

#define s short
#define us unsigned short


int main() {
    int N;
    int number;
    std::vector<int> ArrayNum;
    std::string line;
    bool n;

    while (true) {
        n = false;
        //std::cout << "Введите N: " << std::endl;
        std::getline(std::cin, line);
        std::istringstream stream(line);

        stream >> N;
        if (!(100000 >= N && N > 2)) {
            n = true;
        }
        //std::cout << "Введите числа: "<< std::endl;
        std::getline(std::cin, line);
        std::istringstream streams(line);
        ArrayNum.clear();
        while (streams >> number) {
            if (!(abs(number) <= 1000000000))
                n = true;
            ArrayNum.push_back(number);
        }

        if (N != ArrayNum.size())
            n =true;

        N = ArrayNum.size();
        sort(ArrayNum.begin(), ArrayNum.end());

        if(!(ArrayNum[N - 2] * ArrayNum[N - 1] <= 1000000000))
            n=true;

        if (!n) {
            break;
        }
    }
    std::cout << ArrayNum[N - 2] * ArrayNum[N - 1];
    return 0;
}

#endif //UNTITLED_VECTOR_OUT_H
