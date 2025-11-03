#include <iostream>
#include <string>
#include <memory>
#include <ctime>

using namespace std;

class CloudStorage
{
public:
    virtual bool uploadContents(const string& content) = 0;
    virtual int getFreeSpace() = 0;
    virtual ~CloudStorage() = default;
};

class CloudDrive : public CloudStorage
{
public:
    bool uploadContents(const string& content) override
    {
        cout << "Uploading " << content.length() << " bytes to CloudDrive: " << endl;

        return true;
    }

    int getFreeSpace() override
    {
        // Implement the logic for getting the free space on CloudDrive here.
        const int size = arc4random_uniform(20);
        cout << "Available CloudDrive storage: " << size << "GB" << endl;
        return size;
    }
};

class FastShare : public CloudStorage
{
public:
    bool uploadContents(const string& content) override
    {
        cout << "Uploading " << content.length() << " bytes to FastShare: " << endl;
        return true;
    }

    int getFreeSpace() override
    {
        const int size = arc4random_uniform(10);
        cout << "Available FastShare storage: " << size << "GB" << endl;
        return size;
    }
};

// 3rd party service
class VirtualDrive
{
public:
    bool uploadData(const string& data, const int uniqueID)
    {
        cout << "Uploading to VirtualDrive: \"" << data << "\" ID: " << uniqueID << endl;
        return true;
    }
    int usedSpace()
    {
        return arc4random_uniform(10);
    }
    const int totalSpace = 15;
};

// class AdapterVirtualDrive : public CloudStorage 
// {
// private:
//     std::unique_ptr<VirtualDrive> virtualDrive;
// public:
//     AdapterVirtualDrive() : virtualDrive(make_unique<VirtualDrive>()) {};
//     bool uploadContents(const string& content) override
//     {
//         virtualDrive->uploadData(content, 2);
//         return true;
//     }
//     int getFreeSpace() override
//     {
//         int size = virtualDrive->usedSpace();
//         cout << "Available VirtualDrive storage: " << size << "GB" << endl;
//         return size;
//     }
// };


class AdapterVirtualDrive : public CloudStorage, private VirtualDrive
{
    public:
        bool uploadContents(const string& content) override
        {
            uploadData(content, 2);
            return true;
        }
        int getFreeSpace() override
        {
            int size = usedSpace();
            cout << "Available VirtualDrive storage: " << size << "GB" << endl;
            return size;
        }
};

int main()
{
    // Create an array of pointers to CloudStorage objects.
    const std::unique_ptr<CloudStorage> cloudServices[]
    {
        std::make_unique<CloudDrive>(),
        std::make_unique<FastShare>(),
        std::make_unique<AdapterVirtualDrive>()
    };

    // Iterate through the array and invoke the uploadContents and getFreeSpace
    // methods on each object.
    const string content = "Beam me up, Scotty!";
    for (const auto &service : cloudServices)
    {        
        service->uploadContents(content);
        service->getFreeSpace();
        cout << endl;
    }

    return 0;
}
