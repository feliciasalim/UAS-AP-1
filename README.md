# UAS AP 1
# Documentation of ToDo CLI Program in c++
This ToDo List program is a console-based program that allows user(s) to manage their own tasks in the command line interface. It allows user(s) to add, view, mark, remove, and search their tasks within the ToDo List.
# Functionality :
1. Add task(s)
- Allows user to add new tasks to the list.
2. View task(s)
- Displays all the task in the list with their status (completed/pending).
- When the list is empty, a message is displayed indicating that the list is empty.
3. Mark task(s) as completed/pending
- User is asked to enter the task number they want to mark as completed/pending.
- The task will be ticked ([V]) if it's completed and will be ignored ([ ]) if it's pending.
4. Remove task(s)
- User is asked to enter the task number they want to remove. 
- The selected task number will be removed once decided.
5. Search task(s) 
- ToDo List will be shown along with the task numbers.
- User is asked to enter a keyword which will be searched within the task(s) description.
- If the keyword is found, it will be indicated which task number contains the searched keyword.
- If no match is found, a message is displayed to indicate there's no matching tasks found.
- PS. The search function is case-sensitive.
6. Exit program
- Allows user to exit the program.
