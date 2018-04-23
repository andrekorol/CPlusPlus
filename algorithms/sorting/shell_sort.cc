#include <iostream>
#include <vector>

std::vector<int> ShellSort(std::vector<int> &vec) {
    // Psuedocode found at https://en.wikipedia.org/wiki/Shellsort
    // Using Marcin Ciura's gap sequence, with an inner insertion sort.

    // Sort an array vec[0...n-1].
    std::vector<int> gaps { 701, 301, 132, 57, 23, 10, 4, 1 };
    int k;
    // Start with the largest gap and work down to a gap of 1
    for (auto&& gap : gaps) {
        // Do a gapped insertion sort for this gap size.
        // The first gap elements vec[0..gap-1] are already in gapped order
        // keep adding one more element until the entire array is gap sorted
        for (int i = gap; i < vec.size(); i++) {
            // add vec[i] to the elements that have been gap sorted
            // save vec[i] in temp and make a hole at position i
            int temp = vec[i];
            // shift earlier gap-sorted elements up until the correct location for vec[i] is found
            for (int j = i; j >= gap && vec[j - gap] > temp; j -= gap) {
                vec[j] = vec[j - gap];
                k = j;
            }
            // put temp (the original a[i]) in its correct location
            vec[k] = temp;
        }
    }
    return vec;
}

int main() {
    std::vector<int> vec  { 62,	83, 18,	53,	07,	17,	95,	86,	47,	69,	25,	28 };
    ShellSort(vec);

    // print the sorted vector
    std::cout << '[';
    for (auto&& num : vec) {
        std::cout << num << ", ";
    }
    std::cout << "]\n";

    return 0;
}