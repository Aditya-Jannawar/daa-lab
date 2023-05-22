void partition(int arr[], int low, int high, int comparisons)
{  
  int pivot = arr[low];
  
  int highS1 = low;
  int lowUnknown = low +1;
  
  for (; lowUnknown <= high; ++lowUnknown)
  {
    //comparisons++;
    if(arr[lowUnknown] < pivot)
    {
    ++highS1;
    swap(arr[lowUnknown], arr[highS1]);
    comparisons++;
    }  
  }
  swap(arr[low], arr[highS1]);
  pivot = highS1;

}