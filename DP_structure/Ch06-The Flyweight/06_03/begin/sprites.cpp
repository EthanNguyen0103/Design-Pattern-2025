#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>

using namespace std;

class Texture
{
public:
    explicit Texture(const string &fileName) : m_FileName(fileName), m_Id(arc4random_uniform(INT_MAX)) {}

    const string description() const
    {
        return "<" + m_FileName + " id" + to_string(m_Id) + ">";
    }
    ~Texture()
    {
        cout << "Destructing " << description() << endl;
    }
    // other texture manipulation methods
private:
    const string m_FileName;
    const int m_Id;
};

class Sprite
{
public:
    Sprite(const Texture *textTure) : m_Texture(textTure)
    {
        cout << "Creating sprite with texture file " << textTure->description() << std::endl;
    }


    void setPositionSize(int x, int y, int width, int height)
    {
        m_X = x;
        m_Y = y;
        m_Width = width;
        m_Height = height;
    }

    void render()
    {
        // draw sprite
        cout << "Rendering sprite with texture: " << m_Texture->description() << endl;
    }


private:
    int m_Width;
    int m_Height;
    int m_X;
    int m_Y;

    const Texture *m_Texture;
};

// class SpriteFactory
// {
//     public:
//         Sprite * makeSprite(const string &fileName)
//         {
//             auto it = m_SpritePool.find(fileName);

//             if(it != m_SpritePool.end())
//             {
//                 return it->second;
//             }
//             else
//             {
//                 const auto texture = getTexture(fileName);
//                 auto [newIt, _] = m_SpritePool.emplace(fileName, new Sprite(texture));
//                 return newIt->second;
//             }
//         }

//         ~SpriteFactory()
//         {
//             for(auto &[fileName, sprite] : m_SpritePool)
//             {
//                 delete sprite;
//             }
//             for(auto &[fileName, texture] : m_TexturePool)
//             {
//                 delete texture;
//             }
//         }
        
//     private:
//         std::unordered_map<string, Sprite*> m_SpritePool;
//         std::unordered_map<string, Texture*> m_TexturePool;

//         const Texture* getTexture(const string &fileName)
//         {
//             auto it = m_TexturePool.find(fileName);
//             if(it != m_TexturePool.end())
//             {
//                 return it->second;
//             }
//             else
//             {
//                 auto [newIT, _] = m_TexturePool.emplace(fileName, new Texture(fileName));
//                 return newIT->second;
//             }
//         }
// };









class SpriteFactory
{
    public:
        Sprite * makeSprite(const string &fileName)
        {
            Sprite* spire = new Sprite(getTexture(fileName));

            return spire;
        }

        ~SpriteFactory()
        {
            for (auto &[string, Texture] : m_TexturePool)
            {
                delete Texture;
            }
        }
    private:
        std::unordered_map<string, Texture*> m_TexturePool;

        const Texture* getTexture(const string &fileName)
        {
            auto it = m_TexturePool.find(fileName);
            if(it != m_TexturePool.end())
            {
                return it->second;
            }
            else
            {
                auto [it,_] = m_TexturePool.insert({fileName, new Texture(fileName)});
                return it->second;
            }
        }
};

int main()
{
    // create a list of sprite objects
    vector<Sprite*> sprites;
    const int numSprites = 10;
    const string textureFile = "spaceship.png";

    SpriteFactory factory;

    for (int i = 0; i < numSprites; ++i)
    {
        auto sprite = factory.makeSprite(textureFile);
        sprite->setPositionSize(10, 10, i*10, i*10);        
        sprites.push_back(sprite);
    }

    // draw all sprites
    for (auto &sprite : sprites)
    {
        sprite->render();
    }
    
    for (auto &sprite : sprites)
    {
        delete sprite;
    }

    return 0;
}
