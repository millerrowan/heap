#include <iostream>
#include <cstring>
#include <fstream>

/* heap creates a max heap data structure 
   Author: Rowan Miller
   2/22/24
*/



int main() {

  bool stillPlaying = true;
  int* heap = new int[101];
  char input[20];
  int numberCounter = 0;
  int mannum = 0; 

  
  
  while(stillPlaying == true) {
    cout << "Enter ADD, DELETE, REMOVEALL, or QUIT" << endl;
    cin >> input; 
    
    if(strcmp(input, "ADD")==0) {
      char input2[20]; 
      cout << "input from file or manual?";
      cout << "Enter 'FILE' or 'MANUAL'" << endl;
      cin >> input;
      
      if(strcmp(input, "FILE")==0){
	cout << "what is the file name and include .txt at end" << endl;
	char fileName[30];
	cin >> fileName;

	ifstream fin;
	fin.open(fileName);
	int input1;
	while(fin >> input) {
	  add();
	  numberCounter++;
	}

      }
      fileName(strcmp(input, "MANUAL")==0) {
	cout << "Type a number between 1 and 1000" << endl;
	cin >> mannum;
	numberCounter++;
	add();
	
      }

    }

    if(strcmp(input, "DELETE")==0) {

    }
    if(strcmp(input, "REMOVEALL")==0) {

    }
    if(strcmp(input, "QUIT")==0) {
      stillPlaying = false; 
    }
  }
  




}

//heap value to the heap - adds to the available spot in array or tree then check to see if parent is larger than it, if parent is, swap with parent
void add() {
  
  

}

void remove() {


}

void removeAll() {


}
