#include <stdio.h>
#include <stdlib.h>	
#include <ctype.h>
#include <stdbool.h>

/*
Program 2: Wumpus, version 2 (dynamically allocated array with superbats and arrows)
  CS 211, UIC, Fall 2022
  System: Replit
	Author: Sohaib Ghani
  Date: 10/8/2022


This is version 2 of the wumpus game. In this version there are new obstacle the user has to face such as bats, but the user also has a new way of wining the game, through the use of arrows.
The objecive of this game is to guesss the position of the wumpus or shoot it with an arrow. While playing the player has to be mindful og pits bats the wumpus and where they shoot that arrow!
*/


/*
After looking over the differences and similarities between my code and the solution code, I gained some valuable insight on how I should compose my future projects. A few main differences I noticed were the overall organization of the project, the readability, and simplicity. All of these were categories that my code was lacking in compared to the solution code. One of the main differences between my code and the solution code that contributed to the overall organization was the function decomposition. The solution code had a function to assign all the positions to different objects in the game, the way I did it was that I coded the randomizer into my main, then I sent the last two objects, which were duplicating rooms of previous objects,into a function to get a unique room number for those objects. Though, I did notice that assigning the variables the way I did used a few lesser amounts of code as compared to the solution. Another major difference was the solution code’s use of structs. When I started this program I thought about using a struct but shied away due to my lack of familiarity with them. After looking at the solution code I realized that structs provide a lot of benefits, some of which include better readability and cleaner code. Also, the calls to some values held by objects in the structs were overall easier to understand. The 2D array was also slightly different. Instead of sending the array that was being built into the 2D array, as a parameter, I had an int function that returned the 2D array. I set the returned value equal to another int **array and used that within my program. Aside from that slight difference, the allocation of memory and the assignment of rooms and values were the same. The initialization of the game was also very different. This is where the solution code has an upper hand on my own. My initialization of the game overall was very different from the solution code’s. My initialization was very cluttered and with everything in main it made it really hard to read and keep track of what was going on. In the future, I will consider breaking the funcion down even further to make the main look cleaner. Another difference I noticed was that in the solution code, there was a function to assign adjacent rooms. This would have been very helpful if I had taken such an approach because I had many instances where I was repeating the same lines of code. Aside from that, checking for hazards and checking what happens when the user enters a room with a hazard was the same. Another thing I didn't consider while coding was the random room the bats could drop you in could also be the room that you were currently in. The solution code accounted for this edge case by regenerating the random variable to make sure the room the user was being dropped in wasn’t the same the user was already in. Overall, analyzing and comparing the solution code to my code served very beneficial. I was able to acknowledge faults in my own method as well as realize a new perspective on breaking down my projects.

*/

  
int **populateArray() {//returns populated array

  int **movesArray = malloc(sizeof(int *) * 20);// assigns the necassary ammount of rows

  for (int i = 0; i < 20;i++) {
    movesArray[i] = malloc(3 * sizeof(int));// assigns the memory necassary for the columns
  }
  
  movesArray[0][0] = 2; movesArray[0][1] = 5; movesArray[0][2] = 8; //populting the dynamic array
  movesArray[1][0] = 1; movesArray[1][1] = 3; movesArray[1][2] = 10; 
  movesArray[2][0] = 2; movesArray[2][1] = 4; movesArray[2][2] = 12; 
  movesArray[3][0] = 3; movesArray[3][1] = 5; movesArray[3][2] = 14; 
  movesArray[4][0] = 1; movesArray[4][1] = 4; movesArray[4][2] = 6; 
  movesArray[5][0] = 5; movesArray[5][1] = 7; movesArray[5][2] = 15; 
  movesArray[6][0] = 6; movesArray[6][1] = 8; movesArray[6][2] = 17; 
  movesArray[7][0] = 1; movesArray[7][1] = 7; movesArray[7][2] = 9; 
  movesArray[8][0] = 8; movesArray[8][1] = 10; movesArray[8][2] = 18; 
  movesArray[9][0] = 2; movesArray[9][1] = 9; movesArray[9][2] = 11; 
  movesArray[10][0] = 10; movesArray[10][1] = 12; movesArray[10][2] = 19; 
  movesArray[11][0] = 3; movesArray[11][1] = 11; movesArray[11][2] = 13; 
  movesArray[12][0] = 12; movesArray[12][1] = 14; movesArray[12][2] = 20; 
  movesArray[13][0] = 4; movesArray[13][1] = 13; movesArray[13][2] = 15; 
  movesArray[14][0] = 6; movesArray[14][1] = 14; movesArray[14][2] = 16; 
  movesArray[15][0] = 15; movesArray[15][1] = 17; movesArray[15][2] = 20; 
  movesArray[16][0] = 7; movesArray[16][1] = 16; movesArray[16][2] = 18; 
  movesArray[17][0] = 9; movesArray[17][1] = 17; movesArray[17][2] = 19;
  movesArray[18][0] = 11; movesArray[18][1] = 18; movesArray[18][2] = 20;
  movesArray[19][0] = 13; movesArray[19][1] = 16; movesArray[19][2] = 19;
  return movesArray;//returnign the dynamic array
}

void displayCave(){
    printf( "       ______18______             \n"
    		"      /      |       \\           \n"
    		"     /      _9__      \\          \n"
    		"    /      /    \\      \\        \n"
    		"   /      /      \\      \\       \n"
    		"  17     8        10     19       \n"
    		"  | \\   / \\      /  \\   / |    \n"
    		"  |  \\ /   \\    /    \\ /  |    \n"
    		"  |   7     1---2     11  |       \n"
    		"  |   |    /     \\    |   |      \n"
    		"  |   6----5     3---12   |       \n"
    		"  |   |     \\   /     |   |      \n"
    		"  |   \\       4      /    |      \n"
    		"  |    \\      |     /     |      \n"
    		"  \\     15---14---13     /       \n"
    		"   \\   /            \\   /       \n"
    		"    \\ /              \\ /        \n"
    		"    16---------------20           \n"
    		"\n");
}

void displayInstructions(){
    printf( "Hunt the Wumpus:                                             \n"
    		"The Wumpus lives in a completely dark cave of 20 rooms. Each \n"
    		"room has 3 tunnels leading to other rooms.                   \n"
    		"                                                             \n"
    		"Hazards:                                                     \n"
    		"1. Two rooms have bottomless pits in them.  If you go there you fall and die.   \n"
    		"2. The Wumpus is not bothered by the pits, as he has sucker feet. Usually he is \n"
			"   asleep. He will wake up if you enter his room. When you move into the Wumpus'\n"
			"   room, then he wakes and moves if he is in an odd-numbered room, but stays    \n"
			"   still otherwise.  After that, if he is in your room, he snaps your neck and  \n"
			"   you die!                                                                     \n"
    		"                                                                                \n"
    		"Moves:                                                                          \n"
    		"On each move you can do the following, where input can be upper or lower-case:  \n"
    		"1. Move into an adjacent room.  To move enter 'M' followed by a space and       \n"
    		"   then a room number.                                                          \n"
    		"2. Enter 'R' to reset the person and hazard locations, useful for testing.      \n"
    		"3. Enter 'C' to cheat and display current board positions.                      \n"
    		"4. Enter 'D' to display this set of instructions.                               \n"
    		"5. Enter 'P' to print the maze room layout.                                     \n"
    		"6. Enter 'X' to exit the game.                                                  \n"
    		"                                                                                \n"
    		"Good luck!                                                                      \n"
    		" \n\n");
}//end displayInstructions()

/*
this function is used for when the wumpus is used. it compares all adjacent sides to see which one is smallest

*/
void wumpusMove (int*wumpusPos, int **movesArray){
  int adj1 = movesArray[*wumpusPos-1][0];
  int adj2 = movesArray[*wumpusPos-1][1];
  int adj3 = movesArray[*wumpusPos-1][2];

  int lowestAdj = adj1;
    
  if (lowestAdj>adj2){
    *wumpusPos = adj2;
  }else if(lowestAdj>adj3){
    *wumpusPos = adj3;       
  }else{
    *wumpusPos = lowestAdj;
  }
}





/*
if the user enters a room that isnt adjacent then it ricochets to the lowest adjacent room*/
void richochetArrow(int *userPos, int *wumpusPos, int*arrow, int *gameOn,int **movesArray, bool *deathByArrow){
        
  int adj1 = movesArray[*arrow-1][0];
  int adj2 = movesArray[*arrow-1][1];    
  int adj3 = movesArray[*arrow-1][2];
   
  int lowestAdj = adj1;//finds the lowest adjacent room
    
  if (lowestAdj>adj2){
    *arrow = adj2;
  }else if(lowestAdj>adj3){
    *arrow = adj3;       
  }else{
    *arrow = lowestAdj;
  }

  if (*arrow ==*wumpusPos){//if the lowest adjacent room is wumpus, wumpus is killed and player wins
    printf("Your arrow ricochet killed the Wumpus, you lucky dog!\nAccidental victory, but still you win!\n");
    *gameOn = 1;
  }
  if (*arrow ==*userPos){  //if the lowest adjacent room is player, player is killed and player loses
    printf("You just shot yourself, and are dying.\nIt didn't take long, you're dead.\n");
    *gameOn = 1;
    *deathByArrow = true;
  }
  if(*deathByArrow ==false && *gameOn==0){
    printf("You are in room %d.\n", *userPos);
}

  
}

/*this fnuction checks to see if the rooms entered by the user are adjacent*/
void adjArrow(int *userPos, int *wumpusPos, int *numOfRooms,int array[100], int**movesArray, bool *arrowMove, int *arrow, int*gameOn){
  
  int arrowPos = *userPos;
  for(int i = 0; i<*numOfRooms;i++){
    
    int aAdj1 = movesArray [arrowPos-1][0];//gets all the adjacent position to the arrow 
    int aAdj2 = movesArray [arrowPos-1][1];
    int aAdj3 = movesArray [arrowPos-1][2];
    

    if (array[i] == aAdj1){//checks to see if the position entered is adj
      arrowPos = aAdj1;// if true then arrow switches to that position
      *arrowMove = true;//updates a truth value to see if it'll rricochet's
      
      
    }else if(array[i] == aAdj2){//checks to see if the position entered is adj
      arrowPos = aAdj2;
      *arrowMove = true;
      
    }else if(array[i]== aAdj3){//checks to see if the position entered is adj
      arrowPos = aAdj3;
      *arrowMove = true;
      
    }else{
      *arrowMove = false;
      printf("Room %d is not adjacent.  Arrow ricochets...\n",array[i] );//error when the value isn't adjacent
    *arrow = arrowPos;      
      break;
    }
    *arrow = arrowPos;

    if (*arrow == *wumpusPos){
      printf("Wumpus has just been pierced by your deadly arrow!\nCongratulations on your victory, you awesome hunter you.\n");// when you hit the wumpus with the entered rooms
      *gameOn=1;//quites game
      break;
      
    }
    if(*arrow == *userPos){
      printf("You just shot yourself.\nMaybe Darwin was right. You're dead.\n");//when you hit yourself
      *gameOn = 1;
      break;
      
    }
    
  }
  
}

void shootingArrow(int *userPos, int*wumpusPos, int* numOfRooms, int shootingArray[100],int**movesArray){// gets the users input for the shooting menu option

  int roomNum, arrowAdj1, arrowAdj2,arrowAdj3;
  scanf("%d",&*numOfRooms);

  if(*numOfRooms>3){
    printf("Sorry, the max number of rooms is 3.  Setting that value to 3.");//if the user enters a number of roos grater than the number allowed, itll automatically set it to 3
    *numOfRooms = 3;
  }

  for(int i = 0; i<*numOfRooms;i++){
    scanf("%d",&roomNum); //stores the number of rooms user enters into an array 
    shootingArray [i]= roomNum;
    }
        
}

/*this function takes in all th hazards, userposition and the dynamically allocated array to see if there are any
hazards present in adjacent rooms
*/
void hazardAdj(int *userPos,int *wumpusPos,int *pit1,int *pit2,int *bat1, int *bat2, int *arrow, int **movesArray){ 

  int uAdj1 = movesArray[*userPos -1][0];//gets the adjacent rooms to the user
  int uAdj2 = movesArray[*userPos -1][1];
  int uAdj3 = movesArray[*userPos -1][2];
  
    if(*userPos==*arrow){//if the user is in the same room as the arrow
      *arrow = -1;
      printf("Congratulations, you found the arrow and can once again shoot.\n");
      printf("You are in room %d. ", *userPos);      
      
      
    }else if(*userPos != *arrow){
      printf("You are in room %d. ", *userPos);     
    
    if(*wumpusPos == uAdj1 || *wumpusPos == uAdj2 || *wumpusPos == uAdj3 ){//if the user is by the wumps
      printf("You smell a stench. ");
    }
    if(*pit1 == uAdj1 || *pit1 == uAdj2 || *pit1 == uAdj3 ){//if user is adj to pit
      printf("You feel a draft. ");
    }
    if(*pit2 == uAdj1 || *pit2 == uAdj2 || *pit2 == uAdj3 ){
      printf("You feel a draft. ");
    }
    if(*bat1 == uAdj1 || *bat1 == uAdj2 || *bat1 == uAdj3 ){//if user is adjacent to bat
      printf("You hear rustling of bat wings.");
    }
    if(*bat2 == uAdj1 || *bat2 == uAdj2 || *bat2 == uAdj3 ){
      
      printf("You hear rustling of bat wings. ");
    }
  }
  printf("\n");
  
}


/*
thisfunction takes in all hazards and the moves array to see if the user has entered those rooms

*/
bool enteringHazard(int *wumpusPos, int *userPos, int *pit1, int *pit2, int *bat1, int *bat2, int **movesArray, bool *forBats){
  /* gets the adjacent rooms for wumpus and movs to the lowest one if the user enters the wumpus room and its an odd room*/
  if (*userPos == *wumpusPos && *wumpusPos%2 != 0){// if odd then it leaves
    int wAdj1 = movesArray[*wumpusPos-1][0];
    int wAdj2 = movesArray[*wumpusPos-1][1];
    int wAdj3 = movesArray[*wumpusPos-1][2];
    int lowestAdj = wAdj1;
    
    if (lowestAdj>wAdj2){
      *wumpusPos = wAdj2;
    }else if(lowestAdj>wAdj3){
      *wumpusPos = wAdj3;
    }else{
      *wumpusPos = lowestAdj;
    }
    printf( "You hear a slithering sound, as the Wumpus slips away.\nWhew, that was close! \n");  
  }
  int newPos= 0;
  
   if (*userPos == *wumpusPos && *wumpusPos%2 == 0){ //if the user enters the wumppus room and its even, wumpus kills the player 
    printf("You briefly feel a slimy tentacled arm as your neck is snapped.\nIt is over.\n");
    return true;
  }
  
  if (*userPos == *pit1 || *userPos == *pit2){//if user enters put
    printf("Aaaaaaaaahhhhhh....\n     You fall into a pit and die.\n");
    return true;
  }
  
  if (*userPos == *bat1 || *userPos == *bat2){//if user enters bats, bats will reallocate player to a random position
    printf("Woah... you're flying!\n");
    do{
       newPos =rand() % 20 + 1;
      }while(*userPos == newPos );
    *userPos = newPos;
    printf("You've just been transported by bats to room %d.\n",*userPos);
    *forBats = true;  
  }
  return false;
}


/*
checks if user inputs a room and its adjacent to the players starting position
*/
void movesChecker(int *userPos,int *wumpusPos,int *pit1,int *pit2, int **movesArray, int *movesCounter){

  int newPos, adj1,adj2,adj3;
  
  scanf(" %d",&newPos); //gets new position
  
  adj1 = movesArray[ *userPos -1][0];// gets adjacent rooms to current position
  adj2 = movesArray[ *userPos- 1][1];
  adj3 = movesArray[ *userPos- 1][2];
  

  if (newPos == adj1 || newPos==adj2 || newPos==adj3){// if entered position is adj then the user's position is moved
    
    *userPos = newPos;
    *movesCounter = *movesCounter + 1;
    }else{
    
      printf("Invalid move.  Please retry. \n");//if the user enters a room not adjacent to current position
  }
}



void optionG (int *wumpusPos){// function for whent he user wants to guess the position of the wumpu

  int userGuess;
  printf("Enter room (1..20) you think Wumpus is in: ");
  scanf(" %d", &userGuess);
  if (userGuess == *wumpusPos){
    printf("You won!\n");//if correct then player wins
    
  }else{
    printf("You lost.\n");//if wrong player loses
    }
  
  
}


void optionR(int *userPos, int *wumpusPos, int *pit1, int *pit2, int *bat1, int *bat2, int *arrow){
  
printf("Enter the room locations (1..20) for player, wumpus, pit1, pit2, bats1, bats2, and arrow: \n\n");
  int nUser, nWump, nPit1, nPit2,nBat1,nBat2,nArrow;
  
  scanf("%d %d %d %d %d %d %d", &nUser, &nWump, &nPit1, &nPit2, &nBat1, &nBat2, &nArrow);
  *userPos = nUser;
  *wumpusPos = nWump;
  *pit1 = nPit1;
  *pit2 = nPit2;
  *bat1 = nBat1;
  *bat2 = nBat2;
  *arrow = nArrow;
}


void batArrows(int *userPos, int *wumpusPos, int *pit1, int *pit2, int *bat1, int *bat2, int *arrow){
  
  while(*bat2 ==*wumpusPos||  *bat2 ==*userPos || *bat2  == *pit1 || *bat2==  *pit2){
    
    *bat2 = rand() % 20 + 1;
   
  }
  while(*arrow==*wumpusPos|| *arrow==*userPos ||*arrow  == *pit1 ||*arrow==  *pit2){
    
    *arrow = rand() % 20 + 1;
    
  }
}



int main(void) {

  char inpChoice;
  srand(0);

  int k = 0;
  int userPos = rand() % 20 + 1;//randomly assigning positions
  int wumpusPos = rand() % 20 + 1;
  int pit1 = rand() % 20 + 1;
  int pit2 = rand() % 20 + 1;
  int bat1 = rand() % 20 + 1;
  int bat2 = rand() % 20 + 1;
  int arrow = rand() % 20 + 1;
  
  batArrows(&userPos, &wumpusPos, &pit1, &pit2, &bat1,&bat2, &arrow);
  
  int gameOn = 0;
  int numOfRooms = 0;
  bool arrowMove = false;
  bool deathByArrow = false;
  int movesCounter = 1;
  int**oneArray = populateArray();//variabe inherets 2d array
  
  hazardAdj(&userPos, &wumpusPos, &pit1, &pit2, &bat1,&bat2, &arrow ,oneArray);//checks to see if initial poisition has a hazard adj to it
  
  while (gameOn == 0) {//to keep game going
    bool deathByArrow = false;
    int shootingArray[100];//used for shooting
    int **movesArray = populateArray(); //populates array again so for the rest of the funcionalities

    printf("\n%d. Enter your move (or 'D' for directions): ",movesCounter); // prompt for user to enter their move
    scanf(" %s", &inpChoice);
    char userChoice = toupper(inpChoice);
  
    switch (userChoice) {
    case 'M'://menu option to move around 
      movesChecker(&userPos, &wumpusPos, &pit1, &pit2, movesArray,&movesCounter);
      bool forBats = false;
      
      if (enteringHazard(&wumpusPos, &userPos, &pit1, &pit2, &bat1, &bat2 ,movesArray, &forBats) == 1) {//checks to see if entering hazard
        gameOn = 1;
        break;
      }
      if (forBats == false){// if its not in bats then the hazard adj messages will play
        hazardAdj(&userPos, &wumpusPos, &pit1, &pit2, &bat1,&bat2, &arrow ,movesArray);
        
      }else if (forBats==true){
      printf("You are in room %d. ", userPos);//if enter bats then will display new position
      }
      forBats = false;
      if (enteringHazard(&wumpusPos, &userPos, &pit1, &pit2, &bat1, &bat2 ,movesArray,&forBats) == 1) {
        gameOn = 1;
        break;
      }
      break;

    case 'R'://to reset positions
      optionR(&userPos, &wumpusPos, &pit1, &pit2, &bat1, &bat2, &arrow);
    hazardAdj(&userPos, &wumpusPos, &pit1, &pit2, &bat1,&bat2, &arrow ,movesArray);
      
      break;

    case 'C':// to see all positions for hazards
     printf(  "Cheating! Game elements are in the following rooms: \n"
    		"Player Wumpus Pit1 Pit2 Bats1 Bats2 Arrow  \n"
    		"%4d %5d %6d %5d %5d %5d %5d \n\n", userPos,wumpusPos,pit1,pit2,bat1,bat2,arrow);
      
      hazardAdj(&userPos, &wumpusPos, &pit1, &pit2, &bat1,&bat2, &arrow ,movesArray);//checks if new positions are by any hazards
      

      break;

    case 'D'://displays instructions
      displayInstructions();
      break;
    
    case 'P'://displays cave
      displayCave();
      break;

    case 'G'://guess for wumpus
      optionG(&wumpusPos);
      gameOn++;
      break;

    case 'X'://exit
      gameOn = 1;
      break;
    case 'S':
      
      if (arrow != -1){//-1 indicates user has arrow
        printf("Sorry, you can't shoot an arrow you don't have.  Go find it.\n");//error for if user shoots arrow and user doesnt have error
      printf("You are in room %d. ", userPos);        
      }else if(arrow == -1){//if user has arrow
        printf("Enter the number of rooms (1..3) into which you want to shoot, followed by the rooms themselves: ");
        
        shootingArrow(&userPos, &wumpusPos,&numOfRooms, shootingArray ,movesArray);//shooting arrow functions
        adjArrow(&userPos,&wumpusPos, &numOfRooms, shootingArray, movesArray, &arrowMove, &arrow, &gameOn);//checks to see if the arros is going in an andjacent path
        
      if (arrowMove == false){// if the arrow hits a room that isnt adjacent itll richochet
          richochetArrow(&userPos, &wumpusPos, &arrow, &gameOn, movesArray, &deathByArrow);
      }
        
      wumpusMove(&wumpusPos, movesArray);//wumpus moves after every time user shoots
      if(gameOn == 0 && arrowMove == true && deathByArrow == false){
        printf("You are in room %d.\n\n", userPos);
        }
      }
      movesCounter= movesCounter +1;// the count of moves increases
      break;
    }
  }
  printf("\nExiting Program ...\n");//exit message

  return 0;
}

