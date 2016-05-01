#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <vector>

using namespace std;

struct room;

struct adjRoom{
    string name;
    room * v;
    bool visited;
    adjRoom(){
        visited = false;
    };
};

struct room{
    string name;
    string riddle;
    string answer1;
    string answer2;
    string answer3;
    bool visited;
    vector<adjRoom> adj;
    room * parent;
    room(){
        visited = false;
    }
};

class Game
{
    public:
        Game();
        virtual ~Game();
        void room1();
        void room2();
        void room3();
        void room4();
        void room5();
        void room6();
        void room7();
        void room8();
        void room9();
        room *getCurrentRoom();
        void updateCurrentRoom(string name);
        void addRoom(string name,string riddle,string answer1, string answer2, string answer3);
        void addHallway(string a, string b);
        bool checkChalice();
        bool checkCrown();
        void setChalice();
        void setCrown();
    protected:
    private:
        vector<room> rooms;
        room *currentRoom;
        int s = 9;
        bool chalice = false;
        bool crown = false;
};

#endif // GAME_H


