#include <iostream>
#include <random>
#include <vector>
#define NRandom 1000000
#define NTosses 3
bool coin_toss();
void test_exp(double &counter, double &total);
void progress_bar(int itr);
int main()
{
    double counter {0.0};
    double total {0.0};
    test_exp(counter, total);
    double p_heads_MC =  counter / NRandom  ;
    double avg = total / NRandom;
    std::cout<<"Probablility is "<<p_heads_MC<<std::endl;
    std::cout<<"Average is "<<avg<<std::endl;

}
// Generate unifrom number between 0.0, 1.0 which indicates head or tail using uniform real distribution to simulate coin toss.
bool coin_toss()
{
    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::uniform_real_distribution<double> dist(0.0,1.0);
    double num = dist(generator);
    if(num < 0.5) return true;  //head
    return false;   //tail
}
// Random Experiment thourgh 1000000 experiments.
void test_exp(double &counter, double &total)
{
    double n_heads;
    bool toss_result;
    double p_heads;
    const double epsilon {0.00001};
    std::cout<<"[";
    for(int i=0;i<NRandom;i++)
    {
        progress_bar(i);
        n_heads=0.0;
        for(int j=0;j<NTosses;j++)
        {
            toss_result = coin_toss();
            if(toss_result) n_heads++;
        }
        p_heads = n_heads/NTosses;
        if(fabs(p_heads-0.66666)< epsilon) counter+=1.0;
        total += n_heads;
    }
    std::cout<<"]\n";
}
// Generate progress bar (10000 iterations = 1%).
void progress_bar(int itr)
{
    if(itr%10000==0)
    {   
            std::cout<<"#";
            std::cout.flush();  
    }
}