//Lobby class for Game Lobby 
#include <iostream>
#include <string>
#include "playerClass.cpp"

class Lobby
{
    friend ostream& operator<<(ostream& os, const Lobby& aLobby);

public:
    Lobby();
    ~Lobby();
    void AddPlayer();
    void RemovePlayer();
    void DeletePlayer();
    void Clear();

private:
    Player* m_pHead;
    Player* m_pLast;
};

Lobby::Lobby():
    m_pHead(0),
    m_pLast(0)
{}

Lobby::~Lobby()
{
    Clear();
}

void Lobby::AddPlayer()
{
    //create a new player node
    cout << "Please enter the name of the new player: ";
    string name;
    cin >> name;
    Player* pNewPlayer = new Player(name);

    //if list is empty, make head of list this new player
    if(m_pHead == 0 && m_pLast == 0)
    {
        m_pHead = m_pLast = pNewPlayer;
    }
    //otherwise, find the end of the list and add the player there
    else     
    {
        m_pLast->SetNext(pNewPlayer);
        m_pLast = pNewPlayer;
    }
}

void Lobby::RemovePlayer()
{
    if(m_pHead == 0 && m_pLast == 0)
    {
        cout << "The game lobby is empty. No one to remove!\n";
    }
    else if (m_pHead == m_pLast)
    {
        m_pLast = 0;
        DeletePlayer();
    }
    else
    {
        DeletePlayer();
    }
}

void Lobby::DeletePlayer()
{
    Player* pTemp = m_pHead;
    m_pHead = m_pHead->GetNext();
    delete pTemp;
}

void Lobby::Clear()
{
    while(m_pHead != 0)
    {
        RemovePlayer();
    }
}

ostream& operator<<(ostream& os, const Lobby& aLobby)
{
    Player* pIter = aLobby.m_pHead, *pLastIter = aLobby.m_pLast;

    os << "\nHere's who's in the game lobby:\n";
    if(pIter == 0 && pLastIter == 0)
    {
        os << "The lobby is empty.\n";
    }
    else
    {
        while(pIter != 0)
        {
            os << pIter->GetName() << endl;
            pIter = pIter->GetNext();
        }
    }

    return os;
}