/*                                                         LINKED LIST
1.   find Middle Node
 Node* findMiddleNode() {
            if (head == nullptr) return nullptr;

            Node* slow = head;
            Node* fast = head;

            while (fast != nullptr && fast->next != nullptr) {
                slow = slow->next;
                fast = fast->next->next;
            }

            return slow;
        }*/
//2.       has Loop
/*
 bool hasLoop() {
    if (head == nullptr || head->next == nullptr) {
        return false; // No loop if there are 0 or 1 nodes
    }

    Node* slow = head;
    Node* fast = head->next;

    while (fast != nullptr && fast->next != nullptr) {
        if (slow == fast) {
            return true; // Cycle detected
        }
        slow = slow->next;
        fast = fast->next->next;
    }

    return false; // No cycle found
}*/
//3.  find Kth From End
/*
//Node* findKthFromEnd(int k) {
    Node* slow = head;
    Node* fast = head;

    // Move the fast pointer k nodes ahead of the slow pointer
    for (int i = 0; i < k; ++i) {
        if (fast == nullptr) {
            return nullptr; // If k is greater than the length of the list
        }
        fast = fast->next;
    }

    // Move both pointers simultaneously until fast reaches the end
    while (fast != nullptr) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow; // Return the slow pointer, which is now at the k-th node from the end
}
*/

//4.   partition List
/*
  void partitionList(int x) {
    if (head == nullptr) return; // Handle edge case: empty list

    // Create two dummy nodes to hold the smaller and greater/equal partitions
    Node dummy1(0); // Dummy node for nodes < x
    Node dummy2(0); // Dummy node for nodes >= x
    Node* prev1 = &dummy1; // Pointer to the tail of the smaller partition
    Node* prev2 = &dummy2; // Pointer to the tail of the greater/equal partition
    Node* current = head; // Pointer to traverse the original list

    // Traverse through the original list
    while (current != nullptr) {
        if (current->value < x) {
            // Append current node to the smaller partition
            prev1->next = current;
            prev1 = current;
        } else {
            // Append current node to the greater/equal partition
            prev2->next = current;
            prev2 = current;
        }
        current = current->next; // Move to the next node
    }

    // Terminate the end of the greater/equal partition
    prev2->next = nullptr;

    // Connect the end of the smaller partition to the beginning of the greater/equal partition
    prev1->next = dummy2.next;

    // Update head to point to the beginning of the partitioned list
    head = dummy1.next;
}*/
//5.   remove Duplicates
/*
void removeDuplicates() {
            unordered_set<int> values;
            Node* previous = nullptr;
            Node* current = head;
            while (current != nullptr) {
                if (values.find(current->value) != values.end()) {
                    previous->next = current->next;
                    delete current;
                    current = previous->next;
                    length -= 1;
                } else {
                    values.insert(current->value);
                    previous = current;
                    current = current->next;
                }
            }
        }*/
//6.   binary To Decimal
/*
 int binaryToDecimal() {
    if (head == nullptr) {
        // If the linked list is empty, return 0
        return 0;
    }

    int num = 0;
    Node* current = head;

    while (current != nullptr) {
        // Multiply num by 2 and add the current binary digit
        num = num * 2 + current->value;
        current = current->next;
    }

    return num;
}*/
//7.    reverse Between
/*
void reverseBetween(int m, int n) {
            if (head == nullptr) return;
    
            Node* dummy = new Node(0);
            dummy->next = head;
            Node* prev = dummy;
    
            for (int i = 0; i < m; i++) {
                prev = prev->next;
            }
    
            Node* current = prev->next;
            for (int i = 0; i < n - m; i++) {
                Node* temp = current->next;
                current->next = temp->next;
                temp->next = prev->next;
                prev->next = temp;
            }
    
            head = dummy->next;
            delete dummy;
        }*/
//********************************************************************************************* 
/*
//                                                       DOUBLY LINKED LIST      
1.  swap First Last
void swapFirstLast() {
    if (length < 2) return;
    int temp = head->value;
    head->value = tail->value;
    tail->value = temp;
}

2.   reverse
void reverse() {
    if (length < 2) return;

    Node* current = head;
    Node* temp = nullptr;

    // Swap next and prev for each node
    while (current != nullptr) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    // Swap head and tail pointers
    if (temp != nullptr) {
        temp = head;
        head = tail;
        tail = temp;
    }
}


3.    is Palindrome

bool isPalindrome() {
    if (length < 2) return true;  // A list with 0 or 1 node is a palindrome.

    Node* forwardNode = head;
    Node* backwardNode = tail;

    while (forwardNode != nullptr && backwardNode != nullptr && forwardNode != backwardNode && forwardNode->prev != backwardNode) {
        if (forwardNode->value != backwardNode->value) {
            return false;
        }
        forwardNode = forwardNode->next;
        backwardNode = backwardNode->prev;
    }

    return true;
}


4.   swap Pairs
void swapPairs() {
    if (length < 2) return;

    Node* current = head;

    while (current != nullptr && current->next != nullptr) {
        Node* nextNode = current->next;
        Node* prevNode = current->prev;
        Node* nextNextNode = nextNode->next;

        if (prevNode != nullptr) {
            prevNode->next = nextNode;
        } else {
            head = nextNode;
        }

        nextNode->prev = prevNode;
        nextNode->next = current;
        current->prev = nextNode;
        current->next = nextNextNode;

        if (nextNextNode != nullptr) {
            nextNextNode->prev = current;
        } else {
            tail = current;
        }

        current = nextNextNode;
    }
}

*/

//********************************************************************************************* 
//                                                        STACKS
/*
1.    push
void push(int value) {
            stackVector.push_back(value);
        }
2.    pop
void pop() {
            if (!isEmpty()) {
                stackVector.pop_back();
            }
        }
3.    reverse String
string reverseString(const string& str) {
    stack<char> charStack;
    string reversedStr;
    
    // Push all characters of the input string onto the stack
    for (char ch : str) {
        charStack.push(ch);
    }
    
    // Pop characters from the stack and append to the reversed string
    while (!charStack.empty()) {
        reversedStr += charStack.top();
        charStack.pop();
    }
    
    return reversedStr;
}
4.
    is Balanced Parentheses
bool isBalancedParentheses(const string& parentheses) {
     stack<char> charStack;
    
    for (char ch : parentheses) {
        if (ch == '(') {
            charStack.push(ch);
        } else if (ch == ')') {
            if (charStack.empty() || charStack.top() != '(') {
                return false;
            }
            charStack.pop();
        }
    }
    
    return charStack.empty();
}
5.   Sort Stack
 void sortStack(stack<int>& inputStack) {
    stack<int> tempStack;
    
    while (!inputStack.empty()) {
        int current = inputStack.top();
        inputStack.pop();
        
        // Move elements from tempStack back to inputStack if they are greater than current
        while (!tempStack.empty() && tempStack.top() > current) {
            inputStack.push(tempStack.top());
            tempStack.pop();
        }
        
        // Push the current element into the correct position in tempStack
        tempStack.push(current);
    }
    
    // Transfer sorted elements back to inputStack
    while (!tempStack.empty()) {
        inputStack.push(tempStack.top());
        tempStack.pop();
    }
}

//********************************************************************************************* 
//                                                       QUEUES
1.    enqueue
void enqueue(int value) {
        stack1.push(value);
    }
2.    dequeue
// Method to remove the front element of the queue
    int dequeue() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }

        if (stack2.empty()) {
            return INT_MIN; // Return a special value to indicate the queue is empty
        }

        int frontValue = stack2.top();
        stack2.pop();
        return frontValue;
    }*/
//********************************************************************************************* 
//                                                        HASH TABLES
//1.   item In Common
/*
   bool itemInCommon(vector<int> vect1, vector<int> vect2) {
    for (auto i : vect1) {
        for (auto j : vect2) {
            if (i == j) return true;
        }
    }
    return false;
}
2.   find Duplicates
vector<int> findDuplicates(const vector<int>& nums) {
    unordered_map<int, int> numCounts;
    vector<int> duplicates;

    // Count occurrences of each number in nums
    for (int num : nums) {
        numCounts[num]++;
    }

    // Find duplicates (numbers with count > 1)
    for (auto& pair : numCounts) {
        if (pair.second > 1) {
            duplicates.push_back(pair.first);
        }
    }

    return duplicates;
}

3.   first Non Repeating Char
char firstNonRepeatingChar(const string& input_string) {
	   unordered_map<char, int> charCounts;

    // Count occurrences of each character in input_string
    for (char ch : input_string) {
        charCounts[ch]++;
    }

    // Find first non-repeating character
    for (char ch : input_string) {
        if (charCounts[ch] == 1) {
            return ch;
        }
    }

    // Return null character if no non-repeating character found
    return '\0';

}
4.    group  Anagrams
vector<vector<string>> groupAnagrams(const vector<string>& strings) {
    unordered_map<string, vector<string>> anagramGroups;

    // Group strings by their canonical form (sorted characters)
    for (const string& str : strings) {
        string canonical = str;
        sort(canonical.begin(), canonical.end());
        anagramGroups[canonical].push_back(str);
    }

    // Collect groups into result vector
    vector<vector<string>> result;
    for (auto& pair : anagramGroups) {
        result.push_back(pair.second);
    }

    return result;
}
5.    two Sum
vector<int> twoSum(const vector<int>& nums, int target) {
    unordered_map<int, int> numMap;

    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];
        if (numMap.find(complement) != numMap.end()) {
            return {numMap[complement], i};
        }
        numMap[nums[i]] = i;
    }

    return {}; // Return empty vector if no solution found
}
6.   sub array Sum

vector<int> subarraySum(const vector<int>& nums, int target) {
    unordered_map<int, int> sumIndex;
    sumIndex[0] = -1; // Handle the case where the subarray starts from the beginning

    int currentSum = 0;
    for (int i = 0; i < nums.size(); ++i) {
        currentSum += nums[i];
        int desiredSum = currentSum - target;
        
        if (sumIndex.find(desiredSum) != sumIndex.end()) {
            return {sumIndex[desiredSum] + 1, i};
        }
        
        sumIndex[currentSum] = i;
    }
    
    return {}; // Return empty vector if no subarray found
}

//********************************************************************************************* 
//                                                                 SETS
7.    remove Duplicates
vector<int> removeDuplicates(const vector<int>& myList) {
    set<int> uniqueSet;  // Create a set to store unique numbers
    
    // Insert each number from the list into the set
    for (int num : myList) {
        uniqueSet.insert(num);
    }
    
    // Convert the set to a vector to return the result
    vector<int> result(uniqueSet.begin(), uniqueSet.end());
    
    return result;
}
8.    has Unique Chars

bool hasUniqueChars(const string& str) {
    unordered_set<char> charSet;
    
    for (char c : str) {
        if (charSet.find(c) != charSet.end()) {
            return false; // Found duplicate
        }
        charSet.insert(c);
    }
    
    return true; // No duplicates found
}
9.  find Pairs
vector<vector<int>> findPairs(const vector<int>& arr1, const vector<int>& arr2, int target) {
    unordered_set<int> mySet;
    vector<vector<int>> pairs;
    
    // Populate the set with elements from arr1
    for (int num : arr1) {
        mySet.insert(num);
    }
    
    // Iterate through arr2 to find pairs
    for (int num : arr2) {
        int complement = target - num;
        
        // Check if complement exists in mySet
        if (mySet.find(complement) != mySet.end()) {
            pairs.push_back({complement, num});
        }
    }
    
    return pairs;
}
10.   longest Consecutive Sequence

int longestConsecutiveSequence(const vector<int>& nums) {
    unordered_set<int> numSet(nums.begin(), nums.end());
    int longestStreak = 0;
    
    for (int num : numSet) {
        // Check if 'num' is the start of a sequence
        if (numSet.find(num - 1) == numSet.end()) {
            int currentNum = num;
            int currentStreak = 1;
            
            // Check the length of the sequence starting from 'num'
            while (numSet.find(currentNum + 1) != numSet.end()) {
                currentNum += 1;
                currentStreak += 1;
            }
            
            // Update the longest streak found so far
            longestStreak = max(longestStreak, currentStreak);
        }
    }
    
    return longestStreak;
}

//********************************************************************************************* 
//                                      Basic Sort ( 1---3 ) & Merge Sort ( 4 ) Algorithm 
1.   Bubble Sort of LL 
void bubbleSort() {
    // If the list has fewer than 2 elements, it's already sorted.
    // So, we exit the function early.
    if (length < 2) return;
 
    // Initialize a pointer called "sortedUntil".
    // This pointer marks the point until which the list is sorted.
    Node* sortedUntil = nullptr;
 
    // Continue sorting until "sortedUntil" reaches the second node in the list.
    while (sortedUntil != head->next) {
        // Initialize "current" at the head of the list. 
        // "current" will be used to traverse the list.
        Node* current = head;
 
        // Traverse the list until "current->next" becomes "sortedUntil".
        // This means we only check the unsorted part of the list.
        while (current->next != sortedUntil) {
            // "nextNode" points to the node immediately after "current".
            Node* nextNode = current->next;
 
            // Compare the value of "current" and "nextNode".
            // If they're out of order, swap them.
            if (current->value > nextNode->value) {
                int temp = current->value;
                current->value = nextNode->value;
                nextNode->value = temp;
            }
            // Move "current" to the next node.
            current = current->next;
        }
        // Update "sortedUntil" to point to the last node we've just checked.
        // This way, "sortedUntil" moves closer to the head of the list.
        sortedUntil = current;
    }
}
2.   Selection Sort of LL 
void selectionSort() {
    // If the list has fewer than 2 elements, it's already sorted.
    // So, we exit the function early.
    if (length < 2) return;
    
    // "current" starts at the head. We'll use it to traverse the list.
    Node* current = head;
    
    // Continue sorting until "current->next" becomes nullptr, 
    // indicating the end of the list.
    while (current->next != nullptr) {
        // Assume the "smallest" value is at "current" for now.
        Node* smallest = current;
        
        // "innerCurrent" starts at the node next to "current".
        // We use it to find the smallest node in the remaining list.
        Node* innerCurrent = current->next;
        
        // Traverse the unsorted part of the list to find the smallest value.
        while (innerCurrent != nullptr) {
            // If we find a smaller value, update "smallest" to point to it.
            if (innerCurrent->value < smallest->value) {
                smallest = innerCurrent;
            }
            // Move "innerCurrent" to the next node.
            innerCurrent = innerCurrent->next;
        }
        
        // If "smallest" is not "current", swap their values.
        if (smallest != current) {
            int temp = current->value;
            current->value = smallest->value;
            smallest->value = temp;
        }
        
        // Move "current" to the next node and continue sorting.
        current = current->next;
    }
}
3.   Insertion Sort of LL 
void insertionSort() {
    if (head == nullptr || head->next == nullptr) {
        return;  // List is empty or has only one element, so it's already sorted
    }

    Node* sorted = nullptr;  // This will be the sorted part of the list
    Node* current = head;    // The node to be inserted

    while (current != nullptr) {
        Node* next = current->next;  // Store the next node

        // Insert current into sorted list
        if (sorted == nullptr || sorted->value >= current->value) {
            // Insert at the beginning
            current->next = sorted;
            sorted = current;
        } else {
            // Find the insertion point
            Node* temp = sorted;
            while (temp->next != nullptr && temp->next->value < current->value) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }

        // Move to the next node
        current = next;
    }

    // Update head and tail
    head = sorted;
    // Find the new tail
    if (head == nullptr) {
        tail = nullptr;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        tail = temp;
    }
}

4.      MERGE TWO LL
void merge(LinkedList& otherList) {
    // Initialize a pointer to the head node of the
    // other linked list we are going to merge.
    Node* otherHead = otherList.getHead();
 
    // Create a 'dummy' node to serve as a starting point.
    // This will simplify handling the head of the new list.
    Node* dummy = new Node(0);
 
    // 'current' will point to the last node in our new,
    // merged list as we build it up.
    Node* current = dummy;
 
    // The loop will run as long as neither of the linked
    // lists is empty.
    while (head != nullptr && otherHead != nullptr) {
 
        // Compare the values at the heads of the two lists.
        // We will take the node with the smaller value.
        if (head->value < otherHead->value) {
            // The current node from our list is smaller.
            current->next = head; // Add it to the merged list.
            head = head->next;    // Move our list's head.
        } else {
            // The node from the other list is smaller.
            current->next = otherHead; // Add it to merged list.
            otherHead = otherHead->next; // Move other head.
        }
        // Move 'current' to the last node in our new list.
        current = current->next;
    }
 
    // At this point, one of the lists is empty. If there
    // are any elements left in the other list, we append
    // them to the end of the merged list.
    if (head != nullptr) {
        current->next = head;
        while (current->next != nullptr) {
            current = current->next; // Move to list's end.
        }
    } else {
        current->next = otherHead;
        while (current->next != nullptr) {
            current = current->next; // Move to list's end.
        }
    }
 
    // Final housekeeping steps. Point our list's head to the
    // first real element, update the tail, and delete dummy.
    tail = current;
    head = dummy->next;
    delete dummy;
 
    // Update the length of our list by adding the length
    // of the other list.
    length += otherList.getLength();
 
    // Clear the other list as it's now merged into ours.
    otherList.head = nullptr;
    otherList.tail = nullptr;
    otherList.length = 0;
}
//********************************************************************************************* 
//                                                    Vectors
1.          remove val Element
void removeElement(vector<int>& nums, int val) {
    int i = 0;  // Slow runner
    for (int j = 0; j < nums.size(); ++j) {
        if (nums[j] != val) {
            nums[i] = nums[j];
            ++i;
        }
    }
    nums.resize(i); 
}
2.   find Maximum Minimum
vector<int> findMaxMin(vector<int>& myList) {
    int max=myList[0];
    int min=myList[0];
    for(int i = 1;i<myList.size();++i){
        
        if(myList[i]>max){
            max=myList[i];
        }
        if(myList[i]<min){
            min=myList[i];
        }}
    vect<int> list = {max,min};
    return list;
    
}
3.   Find Longest String
string findLongestString(vector<string>& stringList) {
	string max="";
	for(int i =0;i<stringList.size();i++){
	    if(stringList[i].size()> max.size()){
	        max=stringList[i];
	    }
	    
	}
	return max;
}
4.    remove duplicates and return size
int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;

    int index = 1; // Start from the second element

    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] != nums[i - 1]) {
            nums[index] = nums[i];
            ++index;
        }
    }

    return index;
}
5.  max profit 
int maxProfit(vector<int>& prices) {
    if (prices.empty()) return 0;

    int min_price = prices[0];
    int max_profit = 0;

    for (int i = 1; i < prices.size(); ++i) {
        // Calculate profit if selling at current price
        int profit = prices[i] - min_price;
        
        // Update max profit
        max_profit = max(max_profit, profit);
        
        // Update min price
        min_price = min(min_price, prices[i]);
    }

    return max_profit;
}
6.   Rotating an Array
void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    if (n == 0) return;
    
    k = k % n; // Normalize k
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
}
7.       Maximum Subarray Sum
int maxSubarray(vector<int>& nums) {
    if (nums.empty()) return 0;

    int max_so_far = INT_MIN;
    int max_ending_here = 0;

    for (int i = 0; i < nums.size(); i++) {
        max_ending_here += nums[i];
        
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
        
        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}
*/