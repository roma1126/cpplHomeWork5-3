#include <iostream>
#include <algorithm>

class sum_func {
private:
    int summ;
    int counter;

public:
    sum_func() : counter(0), summ(0) {}

    void operator()(int x) 
    {
        if (x % 3 == 0) 
        {
            counter++;
            summ += x;
        }
    }

    int get_sum() const 
    {
        return summ; 
    }
    int get_count() const 
    { 
        return counter;
    }
};

int main() 
{
    setlocale(LC_ALL, "Rus");

    sum_func sf;

    int arr[] = { 4, 1, 3, 6, 25, 54 };
    std::cout << "[IN]: ";
    for (int value : arr) std::cout << value << ' ';
    std::cout << std::endl;

    sf = std::for_each(arr, arr + sizeof(arr) / sizeof(arr[0]), sf);

    std::cout << "[OUT]: get_sum() = " << sf.get_sum() << std::endl;
    std::cout << "[OUT]: get_count() = " << sf.get_count();

    return 0;
}