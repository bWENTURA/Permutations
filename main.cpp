#include <iostream>
#include <vector>
#include <algorithm>

//Funkcja zwracająca wartość N!
int factorial(const int N){
    int temp = 1;
    for(int i = 2; i <= N; ++i)
        temp *= i;
    return temp;
}

//Funkcja tworząca vector o zawartości [1, 2, 3, ..., N]
std::vector<int> create_vector(const int N){
    std::vector<int> array(N);
    for(int i = 0; i < N; ++i)
        array[i] = i + 1;
    return array;
}

//Funkcja zwracająca tablicę tablic (macierz) permutacji
std::vector<std::vector<int>> create_array_of_permutations(const int N){
    std::vector<int> temp_array = create_vector(N);
    std::vector<std::vector<int>> matrix;
    matrix.reserve(factorial(N));
    while(next_permutation(temp_array.begin(), temp_array.end())){
        int j = 0;
        while((j != N - 1) && (temp_array[j] != temp_array[j + 1] + 1) && (temp_array[j] != temp_array[j + 1] - 1))
            ++j;
        if(j == N - 1) 
            matrix.push_back(temp_array);
    }
    return matrix;
}

int main(){
    int N;
    std::vector<std::vector<int>> matrix;
    std::cout << "Enter limit of the set [1..N]: " << std::endl;
    std::cin >> N;
    matrix = create_array_of_permutations(N);
    return 0;
}