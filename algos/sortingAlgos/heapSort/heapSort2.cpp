#include"driver.h"

void heapify(std::vector<int>& vec, int N, int currNode) {
  int largest = currNode;
  int leftChild = 2*currNode + 1;
  int rightChild = 2*currNode + 2;
  
  if (currNode < N && vec[currNode] < vec[rightChild]) 
    largest = rightChild;
  if (currNode < N && vec[currNode] < vec[leftChild]) 
    largest = leftChild;

  if (currNode != largest) {
    std::swap(vec[currNode],vec[largest]);
    heapify(vec, N, largest);
  }
}

void heapSort(std::vector<int>& vec, int N) {
  for(int i = N/2 -1; i>=0; --i) {
    heapify(vec,N,i);
  }

  for(int i = N-1; i>0; --i) {
    std::swap(vec[0],vec[i]);
    heapify(vec,i,0);
  }

}

int main() {

  return 0;
}
