template<typename T>
T sumArray(const T* arr, size_t length) {
    T sum = T{}; 
    for (size_t i = 0; i < length; ++i) {
        sum += arr[i];
    }
    return sum;
}
