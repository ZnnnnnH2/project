#include <iostream>
using namespace std;
// 类Account声明，全局
class Account
{
public:
    Account(double InitialBalance)
    {
        balance = InitialBalance;
    }
    double GetBalance()
    {
        return balance;
    }

private:
    double balance;
};
double Account = 15.37; // 隐藏类名Account
int main()
{
    //Account Checking(Account); error : for Account(double) hide Account(<class>) 
    class Account Checking(15.37);
    cout << "Opening account with balance of: "
         << Checking.GetBalance() << "\n";

    return 0;
}
