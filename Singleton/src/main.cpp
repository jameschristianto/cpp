#include <iostream>

using namespace std;

class Singleton {
    private:
        /* Here will be the instance stored. */
        static Singleton *instance;

        /* Private constructor to prevent instancing. */
        Singleton();

    public:
        /* Static access method. */
        static Singleton* getInstance();
};

/* Null, because instance will be initialized on demand. */
Singleton *Singleton::instance = NULL;

/* Getter */
Singleton *Singleton::getInstance() {
    if (instance == NULL) instance = new Singleton();

    return instance;
}

/* Private constructor */
Singleton::Singleton() {

}

int main()
{
    //new Singleton(); // Won't work
    Singleton *p = Singleton::getInstance(); // Ok
    Singleton *q = Singleton::getInstance();

    //another method for create object
    Singleton *r = r->getInstance(); // Ok
    Singleton *s = s->getInstance();

    /* The addresses will be the same. */
    std::cout << p << std::endl;
    std::cout << q << std::endl;
    std::cout << r << std::endl;
    std::cout << s << std::endl;

    cin.get();
    return 0;
}
