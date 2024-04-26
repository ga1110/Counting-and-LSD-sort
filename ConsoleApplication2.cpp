#include <iostream>
#include <vector>
#include <array> 
#include <algorithm>
using namespace std;
void print_arr(const vector<int>& arr)
{
    cout << endl;
    for (const auto& i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}

int get_max(const vector<int>& arr)
{
    return *max_element(arr.begin(), arr.end());
}

void counting_sort(vector<int>& arr)
{
    int arr_max = get_max(arr);
    vector<int> count_arr(arr_max + 1, 0);
    for (const auto& i : arr)
    {
        count_arr[i]++;
    }
    int tmp_i = 0;
    for (int i = 0; i <= arr_max; i++)
    {
        while (count_arr[i] > 0)
        {
            arr[tmp_i] = i;
            count_arr[i]--;
            tmp_i++;
        }
    }
}

void LSD_sort(vector<int>& arr) {
    int max = get_max(arr);
    for (int raz = 1; max / raz > 0; raz *= 10) {
        vector<int> output(arr.size());
        vector<int> count(10, 0);
        for (const auto& i : arr) {
            count[(i / raz) % 10]++;
        }
        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }
        for (int i = arr.size() - 1; i >= 0; i--) {
            output[count[(arr[i] / raz) % 10] - 1] = arr[i];
            count[(arr[i] / raz) % 10]--;
        }
        for (int i = 0; i < arr.size(); i++) {
            arr[i] = output[i];
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    vector<int> arr1 = { 5, 2, 9, 1, 3, 5, 2, 8 };
    cout << "Исходный массив\n";
    print_arr(arr1);
    cout << endl;
    counting_sort(arr1);
    cout << "Сортировка подсчетом\n";
    print_arr(arr1);
    cout << endl;
    vector<int> arr2 = { 170, 45, 75, 90, 802, 24, 2, 66 };
    cout << "Исходный массив\n";
    print_arr(arr2);
    cout << endl;
    cout << "Поразрядная сортировка\n";
    LSD_sort(arr2);
    print_arr(arr2);
}
