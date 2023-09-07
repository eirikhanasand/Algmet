/**
 * Note from Eirik:
 * 1. Added a counter which increments every time a node is visited, effectively
 *    finding the total node count of the tree
 * 2. Added a nullptr counter which increments every time a node is not found,
 * effectively finding the total number of empty references.
 * 3. Added a check for if the node has both a left and a right subnode, which
 * is used to print the nodes information and increment the fullNodeCounter
 * 4. Added a variable treeHeight, which stores the highest gNivaa level, 
 * effectively finding the tallet point of the tree.
*/
/**
 *   Programeksempel nr 12 - Traverserer et binært tre REKURSIVT.
 *
 *   Eksempel som viser traversering av et binært tre vha rekursjon.
 *   Det viser hvor enkelt treet kan traverseres både på en preorder,
 *   inorder og postorder måte.
 *
 *   @file     EKS_12_RekursivTreTraversering.CPP
 *   @author   Frode Haug, NTNU
 */


#include <iostream>                  //  cout
#include <iomanip>                   //  setw

/**
 *  Node (med ID/key/data og venstre/høyre pekere til nodens barn).
 */
struct Node {
    char ID;
    Node *left, *right;                //  Initierende constructor:
    Node(char id)  {  ID = id;  left = right = nullptr;  }
};


void  besok(const Node* node);
Node* byggTre();
void  traverserInorder(Node* node);
void  traverserPostorder(Node* node);
void  traverserPreorder(Node* node);


int gNivaa = -1;            //  Hvilket nivå vi for øyeblikket er på i treet.
int treeHeight;             //  Max height of the tree
int nullptrCount;           //  Amount of nullpointers on the tree
int fullNodeCount;          //  Amount of full nodes (has two children)
int gNr;                    //  Fortløpende nummerering av besøkte noder.
                            //  NB:  Begge disse er kun i bruk her for å vise
                            //       i hvilken rekkefølge nodene besøkes og
                            //       hvilket nivå de befinner seg på.
                            //       Normalt brukes IKKE disse!

/**
 *  Hovedprogrammet:
 */
int main()  {
    Node*  root;

    root = byggTre();

    gNr = 0;                        //  MÅ nullstilles for hver traversering!
                                    //  Mens 'gNivaa' telles tilbake til -1!!!
    std::cout << "\n\nPreorder traversering:\n";
    traverserPreorder(root);

    gNr = 0;
    std::cout << "\n\nInorder traversering:\n";
    traverserInorder(root);

    gNr = 0;
    std::cout << "\n\nPostorder traversering:\n";
    traverserPostorder(root);

    cout << "\n\n";
    return 0;
}


/**
 *  Besøker (visit) en node - ved å skrive dens besøksnummer ('gNr'), 
 *  dens ID/key/data og hvilket nivå ('gNivaa') den er på.
 *
 *  @param   node  -  Aktuell node som skal besøkes
 */
void  besok(const Node* node) {
    std::cout << setw(6) << ++gNr << ": " << node->ID
         << "  på nivå: " << gNivaa << '\n';
}


/**
 *  Bygger et binært eksempel-tre (likt med det i EKS_08).
 *
 *  @return   Peker til det bygde treets rot
 */
Node* byggTre() {
/*   Bygger treet:                                     A
                                              /                 \
                                         B                          C
                                    /         \                  /
                                  D             E              F
                              /       \           \          /
                            G           H           I      J
                              \        / \         /        \
                               K      L   M       N          O
*/
    Node*  noder[15];
    for (int i = 0; i < 15; i++)
        noder[i] = new Node(static_cast <char> ('A' + i));

    noder[0]->left = noder[1];  noder[0]->right = noder[2];
    noder[1]->left = noder[3];  noder[1]->right = noder[4];
    noder[2]->left = noder[5];
    noder[3]->left = noder[6];  noder[3]->right = noder[7];
                                noder[4]->right = noder[8];
    noder[5]->left = noder[9];
                                noder[6]->right = noder[10];
    noder[7]->left = noder[11]; noder[7]->right = noder[12];
    noder[8]->left = noder[13];
                                noder[9]->right = noder[14];
    return noder[0];
}


/**
 *  Traverserer/går gjennom et tre UNDER 'node'
 *  på en INORDER måte ved hjelp av rekursjon.
 *
 *   @param   node  -  Aktuell node å behandle
 *   @see     besok(...)
 */
void traverserInorder(Node* node) {
    if (node) {
        gNivaa++;
        traverserInorder(node->left);
        besok(node);                  //  Besøker MELLOM de rekursive kallene!
        traverserInorder(node->right);
        gNivaa--;
    }
}


/**
*  Traverserer/går gjennom et tre UNDER 'node'
*  på en POSTORDER måte ved hjelp av rekursjon.
*
*   @param   node  -  Aktuell node å behandle
*   @see     besok(...)
*/
void traverserPostorder(Node* node) {
    if (node) {
        gNivaa++;
        traverserPostorder(node->left);
        traverserPostorder(node->right);
        besok(node);                  //  Besøker ETTER de rekursive kallene!
        gNivaa--;
    }
}


/**
 *  Traverserer/går gjennom et tre UNDER 'node'
 *  på en PREORDER måte ved hjelp av rekursjon.
 *
 *   @param   node  -  Aktuell node å behandle
 *   @see     besok(...)
 */
void traverserPreorder(Node* node) {
    if (node) {
        gNivaa++;
        besok(node);                  //  Besøker FØR de rekursive kallene!
        traverserPreorder(node->left);
        traverserPreorder(node->right);
        gNivaa--;
    }
}

void findStats(Node* node) {
    if (node) {
        gNivaa++;
        if (gNivaa > treeHeight) treeHeight = gNivaa;
        checkAndPrintFullNode(node);
        besok(node);
        traverserPreorder(node->left);
        traverserPreorder(node->right);
        gNivaa--;
    } else nullptrCount++;
}

int findHeight(Node* node) {
    findStats(node);
    return treeHeight;
}

int findNullptrAmount(Node* node) {
    findStats(node);
    return nullptrCount;
}

int checkAndPrintFullNode(Node* node) {
    if (node->left && node->right) {
        fullNodeCount++:
        std::cout << "ID: " << ID;
    }
    
    return fullNodeCount
}

int findNodeCount(Node* node) {
    findStats(node);
    return gNr:
}
