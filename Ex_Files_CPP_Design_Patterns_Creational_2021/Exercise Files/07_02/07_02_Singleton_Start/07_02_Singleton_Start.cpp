// 07_02_Singleton_Start.cpp

#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

class Leader
{
    private:
        Leader()
        {
            cout << "New Leader elected" << std::endl;
        }
        // Leader& operator=(const Leader&) = delete;
        // Leader(const Leader&) = delete;

        Leader(const Leader&) = delete;
        Leader& operator=(const Leader&) =delete;
    public:
        static Leader& getInstance()
        {
            static Leader _instance;
            return _instance;
        }
        void giveSpeech()
        {
            cout << "Adress the public" << endl;
        }
};

// Leader* Leader::_instance = nullptr;

int main()
{
    Leader::getInstance().giveSpeech();
}

