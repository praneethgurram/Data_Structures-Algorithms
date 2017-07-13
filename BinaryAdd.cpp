//C++ program  for Binary addition of two n-bit n-element arrays and stored in n+1 element array
#include<iostream>

using namespace std;
// class for binary add;
class BinaryAdd{

public:
     binaryadd(string a[], string b[], int k)
    {
        string *c = new string[k+1];
        string A , B, result;
        int sum, carry=0;
        for(int i =0;i<k;i++)
        {
            A = a[i];
            B = b[i];
            result="";
            carry =0;
            for(int j =k-1;j>=0;j--)
            {
               // carry =0;
                int abit = A.at(j)-'0';
                int bbit = B.at(j)-'0';
                sum = abit^bbit^carry+'0';
                result = (char)sum + result;
                carry = abit & bbit;
            }
            if(carry)
            {
                result = '1'+result;
            }
            c[i]=result;

        }
        c[k]="\0";
for(int i =0;i<=k;i++)
    {
        cout<<c[i]<<endl;
    }


    }
};

int main()
{
    string a[] = {"111","011","101"};
    string b[] = {"111","011","101"};
    int length = a[0].size();

    BinaryAdd bd;
     bd.binaryadd(a,b,length);

    return 0;
}
