/**
 * Note:
 * 
 * Infix is the "normal" method of writing expressions using a set of rules, for 
 * example parenthesis are valued over addition and subtraction. However for this
 * type of evaluation to work you have to know a set of rules beforehand. To
 * solve this problem scientists and staticians came up with another method of
 * writing expressions called postfix. Postfix does not use parenthesis or
 * subsequent operators of the same type, therefore you never need to know any
 * rules. Simply read left from right and apply the operator to the two numbers
 * to the left of the operator. Then continue reading with the new number taking
 * the leftmost place.
*/

/**
 * Example 1:
 * 
 * Infix: (((4+2)+(3*2))+((3+4)*(2*5)))
 * 
 * Symbol Stack     Postfix           Comment
 * (      (                           Added left parenthesis to stack
 * (      ((                          Added left parenthesis to stack
 * (      (((                         Added left parenthesis to stack
 * 4      (((       4                 Added character to postfix
 * +      (((+      42                Added operator to stack
 * 2      (((+      42                Added character to postfix
 * )      ((        42+               Added right parenthesis to stack, popped parenthesis and added containing operator to postfix
 * +      ((+       42+               Added operator to stack
 * (      ((+(      42+               Added left parenthesis to stack
 * 3      ((+(      42+3              Added character to postfix
 * *      ((+(*     42+3              Added operator to stack
 * 2      ((+(*     42+32             Added operator to stack
 * )      ((+       42+32*            Added right parenthesis to stack, popped parenthesis and added containing operator to postfix
 * )      (         42+32*+           Added right parenthesis to stack, popped parenthesis and added containing operator to postfix
 * +      (+        42+32*+           Added operator to stack
 * (      (+(       42+32*+           Added left parenthesis to stack
 * (      (+((      42+32*+           Added left parenthesis to stack
 * 3      (+((      42+32*+3          Added character to postfix
 * +      (+((+     42+32*+3          Added operator to stack
 * 4      (+((+     42+32*+34         Added character to postfix
 * )      (+(       42+32*+34+        Added right parenthesis to stack, popped parenthesis and added containing operator to postfix
 * *      (+(*      42+32*+34+        Added operator to stack
 * (      (+(*(     42+32*+34+        Added left parenthesis to stack
 * 2      (+(*(     42+32*+34+2       Added character to postfix
 * *      (+(*(*    42+32*+34+2       Added operator to stack
 * 5      (+(*(*    42+32*+34+25      Added character to postfix
 * )      (+(*      42+32*+34+25*     Added right parenthesis to stack, popped parenthesis and added containing operator to postfix
 * )      (+        42+32*+34+25**    Added right parenthesis to stack, popped parenthesis and added containing operator to postfix
 * )                42+32*+34+25**+   Added right parenthesis to stack, popped parenthesis and added containing operator to postfix
*/

/**
 * Example 2:
 * 
 * Infix: ((7*3)+(((4*5)*(3+2))*(6+3)))
 *
 * Symbol Stack     Postfix           Comment
 * (      (                           Added left parenthesis to stack
 * (      ((                          Added left parenthesis to stack
 * 7      ((        7                 Added character to postfix
 * *      ((*       7                 Added operator to stack
 * 3      ((*       73                Added character to postfix
 * )      (         73*               Added right parenthesis to stack, popped parenthesis and added containing operator to postfix
 * +      (+        73*               Added operator to stack
 * (      (+(       73*               Added left parenthesis to stack
 * (      (+((      73*               Added left parenthesis to stack
 * (      (+(((     73*               Added left parenthesis to stack
 * 4      (+(((     73*4              Added character to postfix
 * *      (+(((*    73*4              Added operator to stack
 * 5      (+(((*    73*45*            Added character to postfix
 * )      (+((      73*45*            Added right parenthesis to stack and popped parenthesis
 * *      (+((*     73*45*            Added operator to stack
 * (      (+((*(    73*45*            Added left parenthesis to stack
 * 3      (+((*(    73*45*3           Added character to postfix
 * +      (+((*(+   73*45*3           Added operator to stack
 * 2      (+((*(+   73*45*32          Added character to postfix
 * )      (+((*     73*45*32+         Added right parenthesis to stack, popped parenthesis and added containing operator to postfix
 * )      (+(       73*45*32+*        Added right parenthesis to stack, popped parenthesis and added containing operator to postfix
 * *      (+(*      73*45*32+*        Added operator to stack
 * (      (+(*(     73*45*32+*        Added left parenthesis to stack
 * 6      (+(*(     73*45*32+*6       Added character to postfix
 * +      (+(*(+    73*45*32+*6       Added operator to stack
 * 3      (+(*(     73*45*32+*63      Added character to postfix
 * )      (+(*      73*45*32+*63+     Added right parenthesis to stack, popped parenthesis and added containing operator to postfix
 * )      (+        73*45*32+*63+*    Added right parenthesis to stack, popped parenthesis and added containing operator to postfix
 * )                73*45*32+*63+*+   Added right parenthesis to stack, popped parenthesis and added containing operator to postfix
*/