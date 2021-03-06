#include "Game.h"
#include <iostream>
#include <algorithm>

using namespace std;


Game::Game()
{
    //ctor
}

Game::~Game()
{
    //dtor
}
bool Game::checkChalice(){//true if player has completed room E for the first time
    return chalice;
}

bool Game::checkCrown(){//true if the player has completed room E and room C in order
    return crown;
}

void Game::setChalice(){//visited E for first time
    chalice = true;
}

void Game::setCrown(){//visited E and then visited C
    crown = true;
}

void Game::room1(){//Room A
    updateCurrentRoom("A");
    cout<<endl;
    if(currentRoom->visited == false){//If the player has not been to this room before, play the riddle
        cout<<"You walk through a narrow alley and emerge into the first chamber of the maze."<<endl;
        cout<<"Around you, the mossy granite walls loom ominously, dark presences just beyond"<<endl;
        cout<<"the meager, unsteady light of your torch."<<endl;
        cout<<"As you reach the center of the room, you notice three doors, labeled B, E, and I"<<endl;
        cout<<"The doors are locked. Carved on the dank wall in front of you are the words:"<<endl;
        cout<<endl;
        cout<<currentRoom->riddle<<endl;
        string x;
        getline(cin,x);
        transform(x.begin(), x.end(), x.begin(), ::tolower);
        while(x != currentRoom->answer1 and x != currentRoom->answer2 and x != currentRoom->answer3){
            cout<<"Your answer is incorrect. The doors remain locked. Try again."<<endl;
            getline(cin,x);
            transform(x.begin(), x.end(), x.begin(), ::tolower);
        }
        cout<<endl;
        cout<<"With a satisfying series of clicks, the doors swing open."<<endl;
        currentRoom->visited = true;
    }
    else{//the player has been to the room before, avoid playing through the riddle again
        cout<<"You re-enter room A."<<endl;
        cout<<endl;
    }
    cout<<"Choose an adjacent room to travel to:"<<endl;//find the next room to go to
    for(int i = 0; i < currentRoom->adj.size();i++){
        cout<<currentRoom->adj[i].v->name<<endl;
    }
    string a;
    getline(cin,a);
    transform(a.begin(), a.end(), a.begin(), ::toupper);
    while(a != "I" and a != "B" and a != "E"){//input verification
        cout<<"Please enter a valid room choice"<<endl;
        getline(cin,a);
        transform(a.begin(), a.end(), a.begin(), ::tolower);
    }
    updateCurrentRoom(a);//move to the selected room
}

void Game::room2(){//Room B
    cout<<endl;
    if(currentRoom->visited == false){
        cout<<"You pass through the doorway and enter a slightly smaller room. The ceiling"<<endl;
        cout<<"was once painted with murals, but time and the ever-present water running"<<endl;
        cout<<"down the walls have all but destroyed the ancient artwork. The northern"<<endl;
        cout<<"wall is solid rock, but each other wall has a doorway. A worn pedestal"<<endl;
        cout<<"against the north wall reads:"<<endl;
        cout<<endl;
        string x;
        cout<<currentRoom->riddle<<endl;
        getline(cin,x);
        transform(x.begin(), x.end(), x.begin(), ::tolower);
        while(x != currentRoom->answer1 and x != currentRoom->answer2 and x != currentRoom->answer3){
            cout<<"Your answer is incorrect. The doors remain locked. Try again."<<endl;
            getline(cin,x);
            transform(x.begin(), x.end(), x.begin(), ::tolower);
        }
        cout<<endl;
        cout<<"The doors swing open silently, revealing the blackness behind them."<<endl;
        currentRoom->visited = true;
    }
    else{
        cout<<"You return to room B."<<endl;
        cout<<endl;
    }
    cout<<"Choose an adjacent room to travel to:"<<endl;
    for(int i = 0; i < currentRoom->adj.size();i++){
        cout<<currentRoom->adj[i].v->name<<endl;
    }
    string a;
    getline(cin,a);
    transform(a.begin(), a.end(), a.begin(), ::toupper);
    while(a != "C" and a != "D" and a != "A"){
        cout<<"Please enter a valid room choice"<<endl;
        getline(cin,a);
        transform(a.begin(), a.end(), a.begin(), ::toupper);
    }
    updateCurrentRoom(a);
}
void Game::room3(){//Room C
    cout<<endl;
    if(currentRoom->visited == false and chalice == false){//if the player has not been to room E yet
        cout<<"You follow a gently sloping hallway for about 50 feet, then make a sharp"<<endl;
        cout<<"left turn into the room. As you enter, the door slams shut behind you."<<endl;
        cout<<"Inside the room, there is a small gold crown on an oak table."<<endl;
        cout<<"It may be important later."<<endl;
        cout<<endl;
        cout<<"The bones of another unfortunate adventurer lie rotting on the floor."<<endl;
        cout<<"The adventurer's skeletal hand clutches a note that reads:"<<endl;
        cout<<endl;
        string x;
        cout<<currentRoom->riddle<<endl;
        getline(cin,x);
        transform(x.begin(), x.end(), x.begin(), ::tolower);
        while(x != currentRoom->answer1 and x != currentRoom->answer2 and x != currentRoom->answer3){
            cout<<"Your answer is incorrect. The door remains locked. Try again."<<endl;
            getline(cin,x);
            transform(x.begin(), x.end(), x.begin(), ::tolower);
        }
        cout<<endl;
        cout<<"The door swings open silently, allowing you to pass."<<endl;
        currentRoom->visited = true;
    }
    else if(chalice == true and currentRoom->visited == false){//if the player has been to E but not C
        cout<<"You follow a gently sloping hallway for about 50 feet, then make a sharp"<<endl;
        cout<<"left turn into the room. As you enter, the door slams shut behind you."<<endl;
        cout<<"A small gold crown sits on the table at the center of the room."<<endl;
        cout<<"You move to pick it up, then notice a gruesome sight."<<endl;
        cout<<endl;
        cout<<"The bones of another unfortunate adventurer lie rotting on the floor."<<endl;
        cout<<"The adventurer's skeletal hand clutches a note that reads:"<<endl;
        cout<<endl;
        string x;
        cout<<currentRoom->riddle<<endl;
        getline(cin,x);
        transform(x.begin(), x.end(), x.begin(), ::tolower);
        while(x != currentRoom->answer1 and x != currentRoom->answer2 and x != currentRoom->answer3){
            cout<<"Your answer is incorrect. The door remains locked. Try again."<<endl;
            getline(cin,x);
            transform(x.begin(), x.end(), x.begin(), ::tolower);
        }
        cout<<endl;
        cout<<"The door swings open silently, allowing you to pass."<<endl;
        cout<<"You pick up the crown. Now you must reach room H to secure the final"<<endl;
        cout<<"treasure, a fist-sized ruby known as the Heartstone."<<endl;
        currentRoom->visited = true;
        setCrown();
    }
    else if(chalice == false and currentRoom->visited == true){//If the player has cleared the riddle but still does not have the chalice
        cout<<"You return to room C. The only door leads back to room B"<<endl;
        cout<<"You must collect the chalice before you can collect the crown,"<<endl;
        cout<<"Please proceed to room E to collect the chalice"<<endl;
        cout<<endl;
    }
    else if(chalice == true and currentRoom->visited == true and crown == false){//if the player has cleared C, then collected the chalice
        cout<<"You return to room C and retrieve the crown. Now you must"<<endl;
        cout<<"locate the final treasure, a fist sized ruby known as the"<<endl;
        cout<<"Heartstone, located in room H. "<<endl;
        setCrown();
    }
    else{
        cout<<"You return to room C. It is a dead end."<<endl;//C and E have both been fully cleared
        cout<<endl;
    }
    updateCurrentRoom("B");
    cout<<"Room C has no other doors. Press enter to continue to back to B."<<endl;
    string p;
    getline(cin,p);
}

void Game::room5(){//room E
    cout<<endl;
    if(currentRoom->visited == false){
        cout<<"This room has a distinctly magical aura about it. Strange azure lights"<<endl;
        cout<<"without an apparent source dance about the walls, creating a rough, haunting"<<endl;
        cout<<"image of a figure wearing a hood. The figure appears to start, then appears"<<endl;
        cout<<"to stare directly at you. A raspy voice cuts through the air. Answer correctly"<<endl;
        cout<<"and I shall let you pass. Fail and be stuck within these walls for a lifetime."<<endl;
        cout<<endl;
        string x;
        cout<<currentRoom->riddle<<endl;
        getline(cin,x);
        transform(x.begin(), x.end(), x.begin(), ::tolower);
        while(x != currentRoom->answer1 and x != currentRoom->answer2 and x != currentRoom->answer3){
            cout<<"Your answer is incorrect. The doors remain locked. Try again."<<endl;
            getline(cin,x);
            transform(x.begin(), x.end(), x.begin(), ::tolower);
        }
        cout<<endl;
        cout<<"The figure nods, then turns and slowly begins to fade until no lights"<<endl;
        cout<<"remain in the room, save that of your torch. The doors become increasingly"<<endl;
        cout<<"transparent and disappear completely after a few short seconds."<<endl;
        cout<<endl;
        cout<<"A small silver chalice suddenly appears on the stone floor in front of you."<<endl;
        cout<<"Your next mission is to retrieve the golden crown from room C. Best of luck."<<endl;
        currentRoom->visited = true;
    }
    else{
        cout<<"You return to room E. The lights have faded."<<endl;
        cout<<endl;
    }
    cout<<"Choose an adjacent room to travel to:"<<endl;
    for(int i = 0; i < currentRoom->adj.size();i++){
        cout<<currentRoom->adj[i].v->name<<endl;
    }
    string a;
    getline(cin,a);
    transform(a.begin(), a.end(), a.begin(), ::toupper);
    while(a != "A" and a != "G" and a != "D" and a != "F"){
        cout<<"Please enter a valid room choice"<<endl;
        getline(cin,a);
        transform(a.begin(), a.end(), a.begin(), ::toupper);
    }
    updateCurrentRoom(a);
}
void Game::room4(){//room D
    if(currentRoom->visited == false){
        cout<<"You enter a room that is small and circular, with a dank passageway"<<endl;
        cout<<"to your side. As you step forward, a pressure plate activates and"<<endl;
        cout<<"both doors slam shut. A large granite tile on the floor of the otherwise"<<endl;
        cout<<"empty room reads:"<<endl;
        cout<<endl;
        string x;
        cout<<currentRoom->riddle<<endl;
        getline(cin,x);
        transform(x.begin(), x.end(), x.begin(), ::tolower);
        while(x != currentRoom->answer1 and x != currentRoom->answer2 and x != currentRoom->answer3){
            cout<<"Your answer is incorrect. The doors remain locked. Try again."<<endl;
            getline(cin,x);
            transform(x.begin(), x.end(), x.begin(), ::tolower);
        }
        cout<<endl;
        cout<<"The doors slide sideways, opening their respective passageways."<<endl;
        currentRoom->visited = true;
    }
    else{
        cout<<"You re-enter the small circular room. Both doors are open."<<endl;
        cout<<endl;
    }
    cout<<"Choose an adjacent room to travel to:"<<endl;
    for(int i = 0; i < currentRoom->adj.size();i++){
        cout<<currentRoom->adj[i].v->name<<endl;
    }
    string a;
    getline(cin,a);
    transform(a.begin(), a.end(), a.begin(), ::toupper);
    while(a != "B" and a != "E"){
        cout<<"Please enter a valid room choice"<<endl;
        getline(cin,a);
        transform(a.begin(), a.end(), a.begin(), ::toupper);
    }
    updateCurrentRoom(a);
}
void Game::room6(){//room F
    if(currentRoom->visited == false){
        cout<<"Emerging from the dark passageway, you are momentarily blinded by"<<endl;
        cout<<"a harsh flash of light radiating from a crystal orb near the west"<<endl;
        cout<<"wall of the large, vacant room. The light quickly fades, leaving the"<<endl;
        cout<<"room as dark as the preceding passageway. On the door in front of you"<<endl;
        cout<<"is a stone sign which reads:"<<endl;
        cout<<endl;
        string x;
        cout<<currentRoom->riddle<<endl;
        getline(cin,x);
        transform(x.begin(), x.end(), x.begin(), ::tolower);
        while(x != currentRoom->answer1 and x != currentRoom->answer2 and x != currentRoom->answer3){
            cout<<"Your answer is incorrect. The doors remain locked. Try again."<<endl;
            getline(cin,x);
            transform(x.begin(), x.end(), x.begin(), ::tolower);
        }
        cout<<endl;
        cout<<"The door swings open with a shrill, grating shriek."<<endl;
        currentRoom->visited = true;
    }
    else{
        cout<<"You re-enter the empty room. Both doors are open."<<endl;
        cout<<endl;
    }
    cout<<"Choose an adjacent room to travel to:"<<endl;
    for(int i = 0; i < currentRoom->adj.size();i++){
        cout<<currentRoom->adj[i].v->name<<endl;
    }
    string a;
    getline(cin,a);
    transform(a.begin(), a.end(), a.begin(), ::toupper);
    while(a != "E" and a != "H"){
        cout<<"Please enter a valid room choice"<<endl;
        getline(cin,a);
        transform(a.begin(), a.end(), a.begin(), ::toupper);
    }
    updateCurrentRoom(a);
}

void Game::room7(){//room G
    if(currentRoom->visited == false){
        cout<<"Upon entering the cave-like room, you are struck by a pungent oder, as"<<endl;
        cout<<"though the room is directly under a swamp, which judging by the muddy walls"<<endl;
        cout<<"and constantly dripping water, may well be the case. A set of words on"<<endl;
        cout<<"the far wall pose the question:"<<endl;
        cout<<endl;
        string x;
        cout<<currentRoom->riddle<<endl;
        getline(cin,x);
        transform(x.begin(), x.end(), x.begin(), ::tolower);
        while(x != currentRoom->answer1 and x != currentRoom->answer2 and x != currentRoom->answer3){
            cout<<"Your answer is incorrect. Try again."<<endl;
            getline(cin,x);
            transform(x.begin(), x.end(), x.begin(), ::tolower);
        }
        cout<<endl;
        cout<<"The rooms ahead loom through the dark, foreboding doorways."<<endl;
        currentRoom->visited = true;
    }
    else{
        cout<<"You re-enter the dank cave."<<endl;
        cout<<endl;
    }
    cout<<"Choose an adjacent room to travel to:"<<endl;
    for(int i = 0; i < currentRoom->adj.size();i++){
        cout<<currentRoom->adj[i].v->name<<endl;
    }
    string a;
    getline(cin,a);
    transform(a.begin(), a.end(), a.begin(), ::toupper);
    while(a != "H" and a != "E"){
        cout<<"Please enter a valid room choice"<<endl;
        getline(cin,a);
        transform(a.begin(), a.end(), a.begin(), ::toupper);
    }
    updateCurrentRoom(a);
}

void Game::room8(){//Room H
    if(crown == false){//The player can only have the crown if they have fully cleared C, so no challenge if they have not
        cout<<"The room before you is empty and completely featureless."<<endl;
        cout<<"Doors on either side stand open."<<endl;
        cout<<"Choose an adjacent room to travel to:"<<endl;
        for(int i = 0; i < currentRoom->adj.size();i++){
            cout<<currentRoom->adj[i].v->name<<endl;
        }
        string a;
        getline(cin,a);
        transform(a.begin(), a.end(), a.begin(), ::toupper);
        while(a != "F" and a != "G"){
            cout<<"Please enter a valid room choice"<<endl;
            getline(cin,a);
            transform(a.begin(), a.end(), a.begin(), ::toupper);
        }
        updateCurrentRoom(a);
    }
    else{//this is the boss encounter, once the player has the first two treasures
        cout<<endl;
        cout<<"The same foreboding figure from the chalice room now stands before"<<endl;
        cout<< "you, no longer an image, but a being of flesh and blood. He turns"<<endl;
        cout<<"and lowers his hood."<<endl;
        cout<<endl;
        cout<<"You have come far to take my ruby, adventurer,"<<endl;
        cout<<"and you have passed many trials. You can have the ruby if you can"<<endl;
        cout<<"answer my final question:"<<endl;
        cout<<currentRoom->riddle<<endl;
        string x;
        getline(cin,x);
        transform(x.begin(), x.end(), x.begin(), ::tolower);
        while(x != currentRoom->answer1 and x != currentRoom->answer2 and x != currentRoom->answer3){
            cout<<"That is incorrect. How disappointing."<<endl;
            getline(cin,x);
            transform(x.begin(), x.end(), x.begin(), ::tolower);
        }
        cout<<endl;
        cout<<"That is correct. Take the Heartstone now with my blessing."<<endl;
        cout<<endl;
        cout<<"The figure hands you the magnificent stone, then fades once again into"<<endl;
        cout<<"thin air. You have collected all the treasures. Press enter to continue"<<endl;
        string w;
        getline(cin,w);
    }
}
void Game::room9(){//Room I
    if(currentRoom->visited == false){
        cout<<"Upon entering this room, you are immediately struck by the enormous"<<endl;
        cout<<"quantity of junk piled on the floor. Broken stones and debris are"<<endl;
        cout<<"complimented by  stacks of rotten books and old, threadbare rags."<<endl;
        cout<<"Unfortunately, you do not see any of the treasures lying about, though"<<endl;
        cout<<"there is an old stone tablet which reads:"<<endl;
        cout<<endl;
        string x;
        cout<<currentRoom->riddle<<endl;
        getline(cin,x);
        transform(x.begin(), x.end(), x.begin(), ::tolower);
        while(x != currentRoom->answer1 and x != currentRoom->answer2 and x != currentRoom->answer3){
            cout<<"Your answer is incorrect. Try again."<<endl;
            getline(cin,x);
            transform(x.begin(), x.end(), x.begin(), ::tolower);
        }
        cout<<endl;
        cout<<"You have successfully answered the riddle. Add one Easter Egg to"<<endl;
        cout<<"your basket."<<endl;
        currentRoom->visited = true;
    }
    else{
        cout<<"Nothing has changed. The room is still filled with junk."<<endl;
        cout<<endl;
    }

    cout<<"The only passageway leads back to room A"<<endl;
    cout<<"Press enter to continue."<<endl;
    string f;
    getline(cin,f);
    updateCurrentRoom("A");
}

void Game::addRoom(string n,string riddle, string answer1, string answer2, string answer3){
    room v;//this method adds a new room to the maze
    v.name = n;//name of the room, A-I in the main function
    v.riddle = riddle;//the question that will be asked the first time the player enters the room
    v.answer1 = answer1;//possible answeres
    v.answer2 = answer2;
    v.answer3 = answer3;
    rooms.push_back(v);//add the room to the vector of rooms
}

void Game::addHallway(string a, string b){//add a pointer between two rooms
    for(int i = 0; i < rooms.size(); i++){
        if(rooms[i].name == a){
            for(int j = 0; j < rooms.size(); j++){
                if(rooms[j].name == b && i != j){
                    adjRoom av;
                    av.v = &rooms[j];
                    rooms[i].adj.push_back(av);
                }
            }
        }
        if(rooms[i].name == b){
            for(int k = 0; k < rooms.size(); k++){
                if(rooms[k].name == a && i != k){
                    adjRoom bv;
                    bv.v = &rooms[k];
                    rooms[i].adj.push_back(bv);
                }
            }
        }
    }
}

room * Game::getCurrentRoom(){//return the room that the player is currently in, useful for accessing riddles and answers in game
    return currentRoom;
}

void Game::updateCurrentRoom(string n){//change the player's current room
    for (int i = 0; i < 9; i++){
        if(rooms[i].name == n){
            currentRoom = &rooms[i];
            break;
        }
    }
}
