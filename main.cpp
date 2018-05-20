#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

int factorial(const int N){
    int temp = 0;
    for(int i = 0; i < N; ++i)
        temp *= i + 1;
    return temp;
}

std::vector<int> create_vector(const int N){
    std::vector<int> array(N);
    for(int i = 0; i < N; ++i)
        array[i] = i + 1;
    return array;
}

std::list<std::vector<int>> create_array_of_perm(const int N){
    const int arr_length = factorial(N);
    std::vector<int> temp_array = create_vector(N);
    std::list<std::vector<int>> matrix;  
    while(next_permutation(temp_array.begin(), temp_array.end())){
        int j = 0;
        while((j != N - 1) && (temp_array[j] != temp_array[j + 1] + 1) && (temp_array[j] != temp_array[j + 1] - 1))
            ++j;
        if(j == N - 1) matrix.push_back(temp_array);
    }
    return matrix;
}



int main(){
    int N;
    std::list<std::vector<int>> matrix;
    std::cout << "Enter limit of the set [1..N]: " << std::endl;
    std::cin >> N;
    matrix = create_array_of_perm(N);
    for(std::list<std::vector<int>>::iterator it = matrix.begin() ; it != matrix.end(); ++it){
        for(auto range_it: *it) std::cout << range_it << " ";
        std::cout << std::endl;
    }
    system("pause");
    return 0;
}