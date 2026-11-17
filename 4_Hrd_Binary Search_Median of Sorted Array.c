double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int* newArray = (int *)malloc((nums1Size + nums2Size) * sizeof(int));
    //merge sort of two sorted array, time complexity of O(m + n)
    int totalSize = nums1Size + nums2Size;
    for(int i = 0; i < totalSize; i++)
    {
        if(nums2Size == 0 || (nums1Size != 0 && *nums1 <= *nums2))
        {
            nums1Size--;
            *(newArray + i) = *nums1++;
        }
        else if (nums1Size == 0 || (nums2Size != 0 && *nums2 < *nums1))
        {
            nums2Size--;
            *(newArray + i) = *nums2++;
        }
        printf("%d\n", *(newArray + i));
    }
    //Find the median by getting the index of the middle of the array
    if(totalSize % 2 == 0) //IF even size array
    {
        int middle = (totalSize / 2); //Integers will always round down, and index start at 0 
        double sum = (*(newArray + middle) + *(newArray + middle - 1)); //We have to do this way so we can do an double division, not an integer division.
        double total = sum / 2.0;
        return total;
    }
    else //else is odd
    {
        int middle = (totalSize / 2 ); //Integers will always round down, and index start at 0
        return *(newArray + middle);
    }
}