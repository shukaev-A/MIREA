template<typename T>
bool contains(const T* arr, size_t length, const T& value) {
    for (size_t i = 0; i < length; ++i) {
        if (arr[i] == value) {
            return true;
        }
    }
    return false;
}
