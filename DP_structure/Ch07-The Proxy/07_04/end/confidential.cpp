#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Storage
{
public:
    virtual const string getContents() = 0;
    virtual ~Storage() = default;
};

class SecureStorage : public Storage
{
public:
    explicit SecureStorage(const string &data) : m_Contents(data) {}

    const string getContents()
    {
        return m_Contents;
    }

private:
    const string m_Contents;
};

class ProtectedProxy : public Storage
{
public:
    explicit ProtectedProxy(const string m_Contens) : m_Contens(m_Contens), secureStorage(nullptr)
    {
        std::cout << "Create Proxy\n";
    }

    void setAuthor(string pAuthor)
    {
        m_Author = pAuthor;
    }

    const string getContents()
    {
        if(m_Author != "admin")
        {
            return "NULL";
        }

        if(secureStorage == nullptr)
        {
            secureStorage = std::make_unique<SecureStorage>(m_Contens);
        }
        return secureStorage->getContents();
    }

private:
    std::unique_ptr<SecureStorage> secureStorage;
    string m_Contens;
    string m_Author;
};

int main()
{
    ProtectedProxy protectedProxy("Top Secret Information");

    // Limit access to sensitive data
    protectedProxy.setAuthor("admin");
    cout << "Sensitive Data: " << protectedProxy.getContents() << endl;

    return 0;
}
