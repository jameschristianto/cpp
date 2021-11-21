#include <iostream>

using namespace std;

//simple method
/*class Singleton{
public:
    Singleton (const Singleton&) = delete;
    static Singleton& getInstance(){
        return instance;
    }
    
private:
    Singleton(); //constructor
    
    static Singleton instance;
}

Singleton::instance;

int main(){
    Singleton& instance = Singleton::getInstance();
}*/

class Singleton {
    private:
        /* Here will be the instance stored. */
        static Singleton *instance;

        /* Private constructor to prevent instancing. */
        Singleton();

    public:
        /* delete multiple consuctor */
        Singleton (const Singleton&) = delete;

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
