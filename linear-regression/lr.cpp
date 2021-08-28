#include<bits/stdc++.h>

bool custom_sort(double a, double b) 
{
    double  a1=abs(a-0);
    double  b1=abs(b-0);
    return a1<b1;
}
int main()
{
    double x[] = {1,2,3,4,5};
    double y[] = {1,2,3,2,5};

    std::vector<double>error; //untuk pennyimpanan nilai error
    double err;          //untuk menghitung error pada tiap level
    double b0 = 0;       //untuk initilisasi bo
    double b1 = 0;        //untuk initiliasasi b1
    double alpha = 0.01; //intiliasisi learning rate

    for(int i = 0; i<20; i++)
    {
        int idx = i%5;
        double p = b0 + b1 * x[idx];
        err = p - y[idx];
        b0 = b0 - alpha*err;
        b1 = b1 - alpha*err*x[idx];
        // std::cout<<"B0="<<b0<<" "<<"B1="<<b1<<" "<<"error="<<err<<std::endl;
        error.push_back(err);
        sort(error.begin(),error.end(),custom_sort);// sorting to get the minimum value
        //std::cout<<"Final Values are: "<<"B0="<<b0<<" "<<"B1="<<b1<<" "<<"error="<<error[0]<<std::endl;
    }
    std::cout<<"Enter a test x value"<<std::endl;   
    double test;
    std::cin>>test;
    double pred=b0+b1*test;
    std::cout<<std::endl;
    std::cout<<"The value predicted by the model= "<<pred<<std::endl;

    return 0;
}