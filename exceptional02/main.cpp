#include <iostream>
#include <string>
#include <cassert>
using namespace std;

class ci_string:public string
{
public:
    bool operator ==( string& b)
    {
        if (this->size() != b.size())
            return false;
        iterator this_itr=this->begin();
        iterator itr=b.begin();
        for(; itr != b.end(); this_itr++, itr++)
            if( toupper(*this_itr) != toupper(*itr) )
                return false;
        return true;
    }
};

int main()
{
    ci_string p=string("this");
    ci_string q=string("This");
    assert(p == q);

    return 0;
}
