#include <iostream>
#include<algorithm>
using namespace std;

template<typename T, size_t size>
class fixed_vector
{
public:
    typedef T* iterator;
    typedef const T* const_iterator;
    iterator begin() { return v_; }
    iterator end() { return v_+size; }
    const_iterator begin() const { return v_; }
    const_iterator end() const { return v_+size; }
    fixed_vector(){}
    fixed_vector(const fixed_vector& v)
    {
        cout << "in copy constructor"<< endl;;
        copy(v.begin(), v.end(), begin());
    }
    fixed_vector&  operator = (const fixed_vector& v)
    {
        cout<< "in assingment" << endl;
        copy(v.begin(), v.end(), begin());
        return *this;
    }
    T& operator[](unsigned int i)
    {
        return v_[i];
    }

private:
    T v_[size];
};

void print(auto& v)
{
    for(auto& item:v)
        cout << item << endl;
    return;
}

int main()
{
//    cout << "Hello World!" << endl;
    fixed_vector<int, 5> v, z;
    auto i= 0;
    for(auto&item:v)
        item = i++;

    auto w(v);
    z = w;
    w[3] = 42;


    print(v);
    print(w);
    print(z);

    return 0;
}
