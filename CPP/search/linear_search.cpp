/*
 * C++ Program to Implement Linear Search Algorithm
 */
#include <iostream>
#include <vector>
 
/* Function to fill Vector */
void make_vector(std::vector<int>& v)
{
    int num, val;
 
    std::cout << "Enter the number of elements in vector ";
    std::cin >> num;
    for (int i = 0; i < num; i++)
    {
        std::cin >> val;
        v.push_back(val);
    }
}
 
/* Linear Search Function */
int lin_search(std::vector<int> v, int val)
{
    int key = -1;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == val)
        {
            key = i;
            break;
        }
    }
    return key;
}
 
int main()
{
    int key, val;
    std::vector<int> v;
 
    make_vector(v);
    std::cout << "Enter the number : ";
    std::cin >> val;
    key = lin_search(v, val);
    if (key != -1)
        std::cout << "\nElement " << val
                  << " is at position " << ++key;
    else
        std::cout << "\nElement " << val
                  << " is not present";
}
