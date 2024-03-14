#include <iostream>
#include <cstring>
#include <fstream>
#include <cmath>

using namespace std; 

/* heap creates a max heap data structure 
   Author: Rowan Miller
   03/14/24
*/

void add(int* &heap, int numCounter, int current);
void print(int numCounter, int* heap, int index, int end);
void remove(int* &heap, int numCounter);
void removeAll(int &numCounter, int* &heap); 

int main() {

  bool stillPlaying = true;
  int* heap = new int[101];
  char input[20];
  int numCounter = 0;
  int mannum = 0; 

  
  
  while(stillPlaying == true) {
    cout << "Enter ADD, PRINT, DELETE, REMOVEALL, or QUIT" << endl;
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
	while(fin >> input1) {
	  add(heap, numCounter, input1);
	  numCounter++;
	}

      }
      if(strcmp(input, "MANUAL")==0) {
	cout << "Type a number between 1 and 1000" << endl;
	cin >> mannum;
	add(heap, numCounter, mannum);
	numCounter++; 
      }

    }

    if(strcmp(input, "PRINT")==0) {
      cout << "nc:" << numCounter << endl;
      print(0, heap, 1, numCounter);

    }
    
    if(strcmp(input, "DELETE")==0) {
      remove(heap, numCounter);
    }
    if(strcmp(input, "REMOVEALL")==0) {
      removeAll(numCounter, heap);
    }
    if(strcmp(input, "QUIT")==0) {
      stillPlaying = false; 
    }
  }
  




}

//heap value to the heap - adds to the available spot in array or tree then check to see if parent is larger than it, if parent is, swap with parent
void add(int* &heap, int numCounter, int current) {

  //if there is nothing in the heap yet
  if(numCounter == 0) {
    heap[1] = current; 

  }
  //if there is stuff already in heap 
  else {
      int currentIndex = numCounter+1;

      heap[currentIndex] = current;

      int parentIndex = (floor(currentIndex/2));

      while(heap[parentIndex] < heap[currentIndex] && currentIndex != 1) {
	int temp = heap[parentIndex];
	heap[parentIndex] = heap[currentIndex];
	heap[currentIndex] = temp;

	currentIndex = parentIndex;
	parentIndex = (floor(currentIndex/2)); 
      }
   
   }
  

}
//prints out heap
void print(int depth, int* heap, int index, int end) {
  if(((index*2)+1) <= end) {
    print(depth+1, heap, ((index*2)+1), end);
  }
  for(int a = 0; a<depth; a++) {
    cout << "\t";
    
  }
  cout << heap[index] << endl;
  
  if((index*2) <= end) {
    print(depth+1, heap, (index*2), end); 

  }

}
//removes the root of the heap and replaces it with the most recently added in value, then iterates down the list so that value gets put in correct spot
void remove(int* &heap, int numCounter) {
  cout << heap[1] << endl; 
  heap[1] = heap[numCounter];
  numCounter-=1;
  int currentIndex = 1; 
  int leftChild = (currentIndex*2);
  int rightChild = ((currentIndex*2)+1); 
  while((heap[currentIndex] < heap[leftChild] && leftChild < numCounter) || (heap[rightChild] > heap[currentIndex] && rightChild < numCounter)){
    //if left child is greater than right child
    if(heap[rightChild] < heap[leftChild]) {
      int temp = heap[currentIndex];
      heap[currentIndex] = heap[leftChild];
      heap[leftChild] = temp;
      currentIndex = (currentIndex*2);
    }
    //if right child is greater than left child
    else if(heap[leftChild] < heap[rightChild]) {
      int temp = heap[currentIndex];
      heap[currentIndex] = heap[rightChild];
      heap[rightChild] = temp;
      currentIndex = ((currentIndex*2)+1); 
      
    }
    leftChild = (currentIndex*2);
    rightChild = ((currentIndex*2)+1);

  }
}
  //removes all values in the heap
void removeAll(int &numCounter, int* &heap) {
  int u = numCounter-1;
  for(int i = 0; i<u; i++) {
    remove(heap, numCounter);
    numCounter--;
  }
}
