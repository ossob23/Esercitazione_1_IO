
#include <fstream>
#include <iostream>
double mappa(double val)
{
    val = 3.0*val/4.0 -7.0/4.0;
    return val;
}
int main()
{
    std::ifstream file("data.txt");
    if(file.fail())
    {
        std::cerr<<"errore nell'apertura del file"<<std::endl;
        return 1;
    }
    std::ofstream fileout("result.txt");
    fileout<<"# N mean"<<std::endl;
    double val;
    int i=0;
    double media;
    while(file>>val)
    {
        if(i==0)
        {
            media = mappa(val);
            i = i+1;
        }
        else{
            media=(media*i+mappa(val))/(i+1);
            i=i+1;
        }
        fileout<<i<<" "<<media<<std::endl;
    }
    return 0;
}
