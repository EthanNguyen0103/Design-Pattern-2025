#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class Character
{
public:
    explicit Character(char c) : m_Char(c) {
        std::cout << "Create char:" << c << std::endl;
    }
    char getChar() const { return m_Char; }

private:
    const char m_Char;
};

class CharacterFactory
{
    public:
    Character* createCharacter(const char c)
    {
        auto it = m_CharacterPool.find(c);
        if(it != m_CharacterPool.end())
        {
            return it->second;
        }
        else
        {
            std::pair<std::unordered_map<char, Character*>::iterator, bool> m_character = m_CharacterPool.emplace(c, new Character(c));
            return m_character.first->second;
        }
        
    }
    ~CharacterFactory() {
    for (auto& [k, ch] : m_CharacterPool) delete ch;}
    private:
        std::unordered_map<char, Character*> m_CharacterPool;
    
};

class Document
{
public:
    Document(CharacterFactory *cfa) : cfact(cfa) {};
    void insert(char c)
    {
        auto charc = cfact->createCharacter(c);
        m_Chars.push_back(charc);
    }

    void print() const
    {
        for (const auto &c : m_Chars)
        {
            std::cout << c->getChar();
        }
    }

private:
    vector<Character*> m_Chars;
    CharacterFactory *cfact;
};

int main()
{
    // vector<Document*> document;
    CharacterFactory *cfact = new CharacterFactory();
    Document document(cfact);
    document.insert('H');
    document.insert('e');
    document.insert('l');
    document.insert('l');
    document.insert('o');
    document.insert(',');
    document.insert(' ');
    document.insert('w');
    document.insert('o');
    document.insert('r');
    document.insert('l');
    document.insert('d');
    document.insert('!');

    Document document2(cfact);
    document2.insert('H');
    document2.insert('e');
    document2.insert('l');
    document2.insert('l');
    document2.insert('o');
    document2.insert(',');
    document2.insert(' ');
    document2.insert('w');
    document2.insert('o');
    document2.insert('r');
    document2.insert('l');
    document2.insert('d');
    document2.insert('!');


    document.print();
    std::cout << std::endl;
    document2.print();
    std::cout << std::endl;

    return 0;
}