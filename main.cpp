#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
//#include <sort>

using namespace std;

void printVector(vector<int> &v);
void getVector(vector<int> &v)
{
    v.clear();
    cout << "Enter number of elements in vector :" << std::endl;
    int count = 0 ;
    cin >>count;

    if(count<=0) cout<< "\npls enter valid number > 0";
    else {
        int number = 0 ;
        cout << "Enter "<<count<< " number of individual elements in vector :" << std::endl;
        while (count > 0) {
            cin >> number;
            v.push_back(number);
            count--;
        }
    }

    printVector(v);
    return;

}

void printVector(vector<int> &v)
{
    cout<<"\n Vector values are ";
    for( auto i = v.begin(); i!=v.end();i++)
        cout<<":"<<*i;

}

bool bSearch(vector<int> &v, int first, int last, int element)
{
    if(first > last )
        return false;

    int mid = (first+last )/2;

    if(v[mid] == element)
    {

        return true;
    }
    else
    {
        if(v[mid] > element)
            return bSearch(v,0,mid-1,element);
        else
            return bSearch(v,mid+1,last,element);
    }


}


bool mySearch(vector<int> &v,int element)
{
    return bSearch(v,0,v.size()-1,element);

}

int main() {

    int counter =1, element = -1;
    vector<int> vec;
    int number;
    char s;

    while(counter)
    {
        getVector(vec);
        sort(vec.begin(),vec.end());
        printVector(vec);
        cout<< "\n\n\nWhich element do you want to search :";
        cin>>element;
        if (mySearch(vec,element))
        { cout<< "\n "<< element << " is present in vector ";printVector(vec);}
        else
        { cout<< "\n "<< element << " is NOT present in vector ";printVector(vec);}

        cout<< "\n\nEnter 1 to try again or 0 to EXIT";
        cin>>counter;
    }
    return 0;
}

