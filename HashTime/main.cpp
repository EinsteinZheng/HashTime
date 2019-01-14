//
//  main.cpp
//  HashTime
//
//  Created by Einstein Zheng on 1/13/19.
//  Copyright © 2019 Einstein Zheng. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <string>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout<<"HashTime v0.1 Powered by Mocoder Inc."<<std::endl;
    std::string plain,hash;
    std::getline(std::cin,plain);
    if(plain.size()%2!=0)
    {
        plain.push_back(0xEF);
    }
    for(int i=0;i<plain.size();i+=2)
    {
        double twocharsd;
        twocharsd=(double)plain[i]*0x100+(double)plain[i+1];
        twocharsd=sin(cos(cos(twocharsd)))*10000;
        if(twocharsd<0x1000)
        {
            twocharsd*=10;
        }
        int twocharsi=(int)twocharsd;
        int cha1=twocharsi>>8,cha2=twocharsi-(twocharsi>>8)*0x100;
        cha1=cha1%36;
        if(cha1>=10)
        {
            cha1=cha1-10+97;
        }
        else
        {
            cha1+=48;
        }
        cha2=cha2%36;
        if(cha2>=10)
        {
            cha2=cha2-10+97;
        }
        else
        {
            cha2+=48;
        }
        hash.push_back(cha1);
        hash.push_back(cha2);
    }
    std::cout<<hash<<std::endl;
    return 0;
}
