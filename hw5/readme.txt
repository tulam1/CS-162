/**********************************************************
Program: Linked List Sorted Program
Author: Tu Lam
Date: 05/28/2019
**********************************************************/

Description: The main point in this program is to create a Linked List from scratch and ask user to enter a list of number of their desire and put it in each indivual node using the class .h that were given as part of the requirement. From there, the Linked List will be sorted using the merge sort technique which will break the Linked List apart and into individual small pieces of the Linked List. Then the program merged back together to form the sorted Linked List that user give to the computer to do it algorithm.

Step of the Program:
1. In the sorting.cpp(aka driver.cpp), the int main() function is called and an object of class Link_List is created to access the class.
2. While the int main() function run, there is a function in Link_List class called program() which hold the entire program in there.
3. Using the object of Link_List class created call (l), the int main() can access the function as follow: "l.program();"
4. In the program() function, it has the do-while loop which will ask user to enter a number to be create a node to be add to the Linked List.
5. The process repeat until the user enter 0 in the function enter_again() function.
6. The function then will be added using the push_front(int); function to be put in the Linked List.
7. After finishing entering in all the numbers, the list then will be display in the function of original_list();
8. Then the prompt of asking the user to sort them ascending or descending pop up.
9. Based on what user choose, the program will sort the way the user wanted to be sort and the modify list will be display.
10. After that the program will run the prime_number(); function and the prime_display(); function will display how many prime numbers are in the Linked List.
11. Then the program will called the clear(); function to delete the entire Linked List.
12. Finally, the program is done and ask if the user want to retry the program again.
13. If not, program is done.

Note: The program is running the push_front(); function when inserting a new node.
      There is no extra credit at work for this assignment.
      Since the Link_List_Node are all public function, there is nothing needed to implement into the Link_List_Node.cpp