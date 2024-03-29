/**
 * Note:
 * This is my solution to oblig 1 in the Algmet course. The task is pushed to
 * Github for my own accessability and version control, and should only be used
 * as a resource, not copied as an alternative to doing the oblig yourself.
*/

/**
    Oppgave 1: ( 2 * ( ( (4 + 4 ) * (3 * 2 ) ) + ( (5 * 4 ) + (3 + 6 ) ) ) ) 
  
   Tegn    Stack        Postfix
    (       (
    2       (           2
    *       (*          2
    (       (*(         2
    (       (*(         2
    (       (*(((       2
    4       (*(((       24
    +       (*(((+      24
    4       (*(((+      244
    )       (*((        244+
    *       (*((*       244+
    (       (*((*(      244+
    3       (*((*(      244+3
    *       (*((*(*     244+3
    2       (*((*(*     244+32
    )       (*((*       244+32*
    )       (*(         244+32**
    +       (*(+        244+32**
    (       (*(+(       244+32**
    (       (*(+((      244+32**
    5       (*(+((      244+32**5
    *       (*(+((*     244+32**5
    4       (*(+((*     244+32**54
    )       (*(+(       244+32**54*
    +       (*(+(+      244+32**54*
    (       (*(+(+(     244+32**54*
    3       (*(+(+(     244+32**54*3
    +       (*(+(+(+    244+32**54*3
    6       (*(+(+(+    244+32**54*36
    )       (*(+(+      244+32**54*36+
    )       (*(+        244+32**54*36++
    )       (*          244+32**54*36+++
    )                   244+32**54*36+++*
*/

/**
    Oppgave 2: 3 4 5 * 2 + * 6 4 * 8 2 * * +

    Symbol      Stack
        3       3
        4       3,4
        5       3,4,5
        *       3,4,5,*
        2       3,20,2
        +       3,20,2,+
        *       3,22,*
        6       66,6
        4       66,6,4
        *       66,6,4,*
        8       66,24,8
        2       66,24,8,2
        *       66,24,8,2,*
        *       66,24,16,*
        +       66,384,+
                450
*/

/**
 * Oppgave 3, parse tre
 * A: REMRPELEIREUGATMESE
 * B: RPMEEIELRRAGUEMETSE
 * C: PREMIERLEAGUEMESTER
*/