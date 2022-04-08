#include <string>

using namespace std;

#define SALE 1
#define MINI_ATM 2
#define SETTING 3

#define INSTALLMENT 11
#define CARD_VERIFICATION 12
#define ON_US 13
#define OFF_US 14
#define PAYMENT 15
#define TOP_UP 16

struct Data
{
    int menuId;
    int rootMenuId;
};

void InitMenuId();
int getMenuId(string menuName);
int getRootMenuId(string menuName);