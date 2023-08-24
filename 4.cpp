/**
 * Note from Eirik:
 * 
 * Postfix is a way to write expressions without parenthesis and rules. View
 * task 3 for a tutorial on how to turn infix ("normal expressions") into
 * postfix expressions. This file contains two examples of how to calculate the
 * answer of a postfix expression.
*/

/**
 * Example 1:
 * 
 * Postfix: 3 4 + 3 2 * + 2 + 5 3 * 4 2 + * +
 * 
 * Symbol Stack         Action
 * 3      3             Pushed 3 to stack
 * 4      3,4           Pushed 4 to stack
 * +      3,4,+         Removed 3 and 4, added, pushed 7 to stack
 * 3      7,3           Pushed 3 to stack
 * 2      7,3,2         Pushed 2 to stack
 * *      7,3,2,*       Removed 3 and 2, multiplied, pushed 6 to stack
 * +      7,6,+         Removed 7 and 6, added, pushed 13 to stack
 * 2      13,2          Pushed 2 to stack
 * +      13,2,+        Removed 13 and 2, added, pushed 15 to stack
 * 5      15,5          Pushed 5 to stack
 * 3      15,5,3        Pushed 3 to stack
 * *      15,5,3,*      Removed 5 and 3, multiplied, pushed 15 to stack
 * 4      15,15,4       Pushed 4 to stack
 * 2      15,15,4,2     Pushed 2 to stack
 * +      15,15,4,2,+   Removed 4 and 2, added, pushed 8 to stack
 * *      15,15,6,*     Removed 15 and 8, multiplied, pushed 90 to stack
 * +      15,90,+       Removed 15 and 90, added, pushed 120 to stack
 *        120
*/

/**
 * Example 2:
 * 
 * Postfix: 3 4 + 3 * 2 + 5 2 * + 2 *
 * 
 * Symbol Stack         Action
 * 3      3             Pushed 3 to stack
 * 4      3,4           Pushed 4 to stack
 * +      3,4,+         Removed 3 and 4, added, pushed 7 to stack
 * 3      7,3           Pushed 3 to stack
 * *      7,3,*         Removed 7 and 3, multiplied, pushed 21 to stack
 * 2      21,2          Pushed 2 to stack
 * +      21,2,+        Removed 21 and 2, added, pushed 23 to stack
 * 5      23,5          Pushed 5 to stack
 * 2      23,5,2        Pushed 2 to stack
 * *      23,5,2,*      Removed 5 and 2, added, pushed 10 to stack
 * +      23,10,+       Removed 23 and 10, added, pushed 33 to stack
 * 2      33,2          Pushed 2 to stack
 * *      33,2,+        Removed 33 and 2, added, pushed 66 to stack
 *        66
*/