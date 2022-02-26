//Game lobby main function file
#include <iostream>
#include "lobbyClass.cpp"

using namespace std;

int main()
{
    Lobby myLobby;
    int choice;

    do
    {
        cout << myLobby;
        cout << "\nGame Lobby\n";
        cout << "0 - Exit the program.\n";
        cout << "1 - Add a player to the lobby.\n";
        cout << "2 - Remove a player from the lobby.\n";
        cout << "3 - Clear the lobby.\n\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice)
        {
            case 0: cout << "Goodbye.\n"; break;
            case 1: myLobby.AddPlayer(); break;
            case 2: myLobby.RemovePlayer(); break;
            case 3: myLobby.Clear(); break;
            default: cout << "That was not a valid choice.\n";
        }
    } while (choice != 0);
    

    return 0;
}