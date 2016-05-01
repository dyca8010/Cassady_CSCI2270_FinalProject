#include <iostream>
#include "Game.h"
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    bool run = true;
    while (run){
        cout<<"======Main Menu======"<<endl;
        cout<<"1. Tutorial"<<endl;
        cout<<"2. Enter the Maze!"<<endl;
        cout<<"3. Quit"<<endl;
        string a;
        getline(cin,a);
        if(a == "1"){
            string answer;
            bool go = true;
            cout<<"Welcome to RiddleQuest, traveler."<<endl;
            cout<<endl;
            cout<<"Prepare yourself for a night of navigation and puzzles as you try to"<<endl;
            cout<<"successfully traverse the dungeon and escape with the treasures"<<endl;
            cout<<endl;
            cout<<"Throughout the course of the dungeon, you will be prompted to answer numerous"<<endl;
            cout<<"riddles in order to advance. As you progress, you will collect the three"<<endl;
            cout<<"rare treasures hidden within the maze. Once you clear a room, the doors will"<<endl;
            cout<<"remain open. Let's practice a riddle:"<<endl;
            cout<<endl;
            while(go){
                cout<<"What word contains all 26 letters?"<<endl;
                getline(cin,answer);
                transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
                if(answer == "the alphabet" or answer == "alphabet"){
                    cout<<"Congratulations. You are ready for the challenge. Enter the maze."<<endl;
                    go = false;
                }
                else if(answer == "hint"){
                    cout << "The spelling of the word does not literally contain all 26 letters" << endl;
                }
                else{
                    cout<<"Incorrect. Try again."<<endl;
                }
            }
        }
        else if(a == "2"){
            Game g;
            g.addRoom("A","Poor people have it, rich people need it, and if you eat it you die. What is it?","nothing","nada","it's nothing");
            g.addRoom("B", "Paul is six feet tall, works at a butcher's shop, and wears size 9 shoes. What  does he weigh?","animal meat","meat","he weighs meat");
            g.addRoom("C","What has many keys but cannot open a single door?","computer","piano","keyboard");
            g.addRoom("D","What relation would your father's sister's sister-in-law be to you?","mother","your mother","my mother");;
            g.addRoom("E","No sooner spoken than broken. What is it?","silence","the silence","it's silence");
            g.addRoom("F","What is it that you ought to keep after giving it to someone else?","my word","your word","a promise");
            g.addRoom("G","What English word becomes shorter when it is lengthened?","short","short, of course","it's short");
            g.addRoom("H","I happen once in a day, twice in a decade, but never in a lifetime. What am I?","the letter d","letter d","d");
            g.addRoom("I","David's father has three sons: Snap, Crackle, and who?","david, duh","david","david, of course");
            g.addHallway("A","B");
            g.addHallway("A","I");
            g.addHallway("A","E");
            g.addHallway("B","C");
            g.addHallway("B","D");
            g.addHallway("D","E");
            g.addHallway("E","F");
            g.addHallway("E","G");
            g.addHallway("G","H");
            g.addHallway("F","H");
            g.updateCurrentRoom("A");
            cout<<"Welcome, adventurer. Contained within the maze are three treasures which"<<endl;
            cout<<"you must secure by successfully navigating the maze, a chalice, a crown."<<endl;
            cout<<"and the fabled Heartstone, a magnificent ruby the size of a fist."<<endl;
            cout<<endl;
            cout<<"Your first task is to retrieve the silver chalice from room E"<<endl;
            cout<<"May you find luck in your travels, adventurer."<<endl;
            cout<<endl;
            cout<<"Press enter to continue"<<endl;
            string anything;
            getline(cin,anything);
            cout<<endl;
            cout<<"You begin in room A"<<endl;
            cout<<endl;
            while(g.getCurrentRoom()->name != "E"){
                if(g.getCurrentRoom()->name == "A"){
                    g.room1();
                }
                else if(g.getCurrentRoom()->name == "B"){
                    g.room2();
                }
                else if(g.getCurrentRoom()->name == "C"){
                    g.room3();
                }
                else if(g.getCurrentRoom()->name == "D"){
                    g.room4();
                }
                else if(g.getCurrentRoom()->name == "F"){
                    g.room6();
                }
                else if(g.getCurrentRoom()->name == "G"){
                    g.room7();
                }
                else if(g.getCurrentRoom()->name == "H"){
                    g.room8();
                }
                else if(g.getCurrentRoom()->name == "I"){
                    g.room9();
                }
            }
            cout<<"You enter room E. "<<endl;
            g.room5();
            g.setChalice();
        while(g.getCurrentRoom()->name != "C"){
                if(g.getCurrentRoom()->name == "A"){
                    g.room1();
                }
                else if(g.getCurrentRoom()->name == "B"){
                    g.room2();
                }
                else if(g.getCurrentRoom()->name == "E"){
                    g.room5();
                }
                else if(g.getCurrentRoom()->name == "D"){
                    g.room4();
                }
                else if(g.getCurrentRoom()->name == "F"){
                    g.room6();
                }
                else if(g.getCurrentRoom()->name == "G"){
                    g.room7();
                }
                else if(g.getCurrentRoom()->name == "H"){
                    g.room8();
                }
                else if(g.getCurrentRoom()->name == "I"){
                    g.room9();
                }
            }
            g.room3();
            g.setCrown();
            g.updateCurrentRoom("B");
            while(g.getCurrentRoom()->name != "H" or g.checkCrown() == false){
                    if(g.getCurrentRoom()->name == "A"){
                        g.room1();
                    }
                    else if(g.getCurrentRoom()->name == "B"){
                        g.room2();
                    }
                    else if(g.getCurrentRoom()->name == "C"){
                        g.room3();
                    }
                    else if(g.getCurrentRoom()->name == "D"){
                        g.room4();
                    }
                    else if(g.getCurrentRoom()->name == "F"){
                        g.room6();
                    }
                    else if(g.getCurrentRoom()->name == "G"){
                        g.room7();
                    }
                    else if(g.getCurrentRoom()->name == "E"){
                        g.room5();
                    }
                    else if(g.getCurrentRoom()->name == "I"){
                        g.room9();
                    }
                }
                cout<<"You enter the final room. "<<endl;
                g.room8();
                cout<<endl;
                cout<<endl;
                cout<<endl;
                cout<<"Congratulations!!! You Win!!!"<<endl;
                cout<<endl;
                cout<<"Type 'yes' to play again"<<endl;
                string go;
                getline(cin,go);
                transform(go.begin(), go.end(), go.begin(), ::tolower);
                if(go != "yes"){
                    run = false;
                }
        }
        else if(a == "3"){
            run = false;
        }
        else{
            cout<<"please enter a valid choice"<<endl;
        }
    }
    cout<<endl;
    cout<<"Thanks for playing my game."<<endl;

    return 0;
}

