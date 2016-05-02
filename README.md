# Cassady_CSCI2270_FinalProject

Summary:
My final project is a variation on the classic text-based adventure games. RiddleQuest places the user in the first room of a maze. They are tasked with finding three artifacts, a silver chalice, a gold crown, and a magnificent ruby. The treasures must be acquired in order and cannot be picked up ahead of time. Each room in the dungeon has a unique riddle which the user must solve to pass through it, and once a room has been solved, the user may pass through it again without having to resolve the riddle. The game also includes a small tutorial to help the player acclimate to the interface for inputting answers to the riddles. The maze is coded as a graph, with each room as a vertex. Each room vertex stores the room name, A-I, that room's riddle, and possible answers to that riddle. Within the class file for the game, Game.cpp, each room also has its own method, which is called when the room is entered and reads the riddle to the player. The room method is satisfied when the correct answer is given and the player may choose any adjacent room to travel to.

How to Run:
First, clone the project. Then use an IDE such as Code::Blocks to open the files. My recommendation is to create your own project and copy the code in from the cloned files. When you are finished editing or playing the game, re-upload the files to github using the methods outlined in recitation 9. 
To play the game, compile the code and run it. You will see a main menu appear inside the terminal. Enter 1 to run the tutorial, which outlines the format for answering riddles. Press 2 to run the game itself and 3 to quit. If you enter 2 and proceed into the maze, you will be given the intro screen. Upon pressing enter, you are given the riddle for the first room. There are three variations of the correct answer that the program will accept. Once one of these is entered, you can continue out of room A. The game will inform you that you can choose to travel to rooms B, E, and I. When you enter one of these (it is case-sensitive) you will be taken to that room and presented with another puzzle. Whenever you enter a room for the first time you will be given the puzzle to solve but upon returning later, you can simply pass through the room.

Dependencies:
This program is not dependent on any outside libraries or APIs. I typically run it in Code::Blocks under the default settings.

System Requirements:
This program is not dependent on any specific operating system.

Group Member:
Dylan Cassady

Contributors:


Issues/bugs:
The code is not currently commented. I will aim to add comments to help those editing it later today (4/27/16).

