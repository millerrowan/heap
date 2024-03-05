#include <iostream>
#include <cstring>
#include <fstream>

/* heap creates a max heap data structure 
   Author: Rowan Miller
   2/22/24
*/

void add(int* heap[], int numCounter, int current);
void print();
void remove();
void removeAll(); 

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
	  add(heap, numCounter, input);
	  numberCounter++;
	}

      }
      fileName(strcmp(input, "MANUAL")==0) {
	cout << "Type a number between 1 and 1000" << endl;
	cin >> mannum;
	add(heap, numCounter, mannum);
	numCounter++; 
      }

    }

    if(strcmp(input, "PRINT")==0) {


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
void add(int* heap[], int numCounter, int current) {

  //if there is nothing in the heap yet
  if(numCounter == 0) {
    heap[1] = current; 

  }
  //if there is stuff already in heap 
  else() {
      int currentIndex = numAdded+1;

      heap[currentIndex] = current;

      int parentIndex = floor(currentIndex/2);

      while(parentIndex < currentIndex && currentIndex != 1) {
	int temp = heap[parentIndex];
	heap[parentIndex] = heap[currentIndex];
	heap[currentIndex] = temp;

	currentIndex = parentIndex;
	parentIndex = floor(currentIndex/2); 
      }
   
   }
  

}

void print(int count, int* heap[], int index, int end) {
  if((index*2) < end) {
    print((index*2)+1, count+1, end);
  }
  for(int a = 0; a<count; a++) {
    cout << "/t";
    
  }
  cout << heap[index] << endl;
  
  if((index*2) < end) {
    print((index*2), count+1, end); 

  }

}

void remove(int* heap[], int numAdded) {
  cout << heap[1] << endl; 
  delete heap[1];
  heap[1] = heap[numAdded];
  numAdded-1;
  int currentIndex = 1; 
  int leftChild = (currentIndex*2);
  int rightChild = ((currentIndex*2)+1); 
  while(heap[1] <
  

}

void removeAll() {


}
