// You are given an array arr[] of integers, where each element arr[i] represents the number of pages in the ith book. You also have an integer k representing the number of students. The task is to allocate books to each student such that:

// Each student receives atleast one book.
// Each student is assigned a contiguous sequence of books.
// No book is assigned to more than one student.
// The objective is to minimize the maximum number of pages assigned to any student. In other words, out of all possible allocations, find the arrangement where the student who receives the most pages still has the smallest possible maximum.

// Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see the explanation for better understanding).

// Examples:

// Input: arr[] = [12, 34, 67, 90], k = 2
// Output: 113
// Explanation: Allocation can be done in following ways:
// [12] and [34, 67, 90] Maximum Pages = 191
// [12, 34] and [67, 90] Maximum Pages = 157
// [12, 34, 67] and [90] Maximum Pages = 113.
// Therefore, the minimum of these cases is 113, which is selected as the output.
// Input: arr[] = [15, 17, 20], k = 5
// Output: -1
// Explanation: Allocation can not be done.
// Input: arr[] = [22, 23, 67], k = 1
// Output: 112


class Solution {
public:
    bool isPossible(const vector<int>& arr, int k, int maxPages) {
        int studentCount = 1; // Start with one student
        int currentPages = 0;
        
        for (int pages : arr) {
            // If adding this book exceeds the maxPages, we need to allocate to the next student
            if (currentPages + pages > maxPages) {
                studentCount++; // Assign to a new student
                currentPages = pages; // Start with this book for the new student
                
                // If we exceed the student count, return false
                if (studentCount > k) {
                    return false;
                }
            } else {
                currentPages += pages; // Otherwise, continue adding pages to the current student
            }
        }
        
        return true; // All books have been assigned within the constraints
    }
    
    int findPages(vector<int>& arr, int k) {
        int n = arr.size();
        
        // If there are fewer books than students, it's impossible to assign
        if (n < k) {
            return -1;
        }
        
        // Set the search boundaries
        int low = *max_element(arr.begin(), arr.end()); // at least the largest book
        int high = accumulate(arr.begin(), arr.end(), 0); // sum of all pages
        
        int result = high;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (isPossible(arr, k, mid)) {
                result = mid;
                high = mid - 1; // Try for a smaller maximum
            } else {
                low = mid + 1; // Increase the maximum as this allocation isn't possible
            }
        }
        
        return result;
    }
};
