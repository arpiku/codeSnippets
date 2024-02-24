#include"driver.h"

void stlHeapSort(std::vector<int>& vector) {
  std::make_heap(vector.begin(),vector.end());
  std::sort_heap(vector.begin(),vector.end());
}

//Construct a BT, and also rememebrer to include the rigth N, and if (
//

void heapify(std::vector<int>& vec, int N, int i) {
  int largest = i;
  int leftChild = 2*i + 1;
  int rightChild = 2*i + 2;

   if(leftChild < N && vec[largest] < vec[leftChild])
    largest = leftChild;
   if(rightChild < N && vec[largest] < vec[rightChild])
    largest = rightChild;
  
   if (largest != i) {
     std::swap(vec[largest],vec[i]);
     heapify(vec,N,largest);
   }
  
}

void heapSort(std::vector<int>& vec) {
  std::cout << "herere" << std::endl;
  for(int i = vec.size()/2-1;i>=0;i--) {
    heapify(vec,vec.size(),i);
  }

  for(int i = vec.size()-1; i>0;i--) {
    std::swap(vec[0],vec[i]);
    heapify(vec,i,0);
  }

}
  



int main() {
  std::vector<int> v = getRandomArray(10);
  printArray(v);

  heapSort(v);

  printArray(v);
 
  return 0;
}
