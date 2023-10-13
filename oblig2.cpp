/**
 * Note:
 * This is my solution to oblig 2 in the Algmet course. The task is pushed to
 * Github for my own accessability and version control, and should only be used
 * as a resource, not copied as an alternative to doing the oblig yourself.
*/

/**
 *  OPPGAVE A: Skriver ut ALLE noder med ID i intervallet 'min'-'max'.
 *
 *  @param   node   -  Noden som skal besøkes/undersøkes
 *  @param   min    -  minste verdi for en utskrevet node sin ID
 *  @param   max    -  største verdi for en utskrevet node sin ID
 */
void skrivIntervall(const Node* node, const int min, const int max) {
    if (node) {
        if (node->ID >= min && node->ID <= max) {
            std::cout << " " << node->ID;
        };
        skrivIntervall(node->left, min, max);
        skrivIntervall(node->right, min, max);
    }
}

/**
 *  OPPGAVE B: Skriver alle VENSTRE BLADNODER i treet.
 *
 *   @param   node  -  Noden som skal besøkes.
 */
void skrivVenstreBladnode(const Node* node) {
    if (node) {
        if (node->left && !node->left->left && !node->left->right) {
            std::cout << " " << node->left->ID;
        }
        skrivVenstreBladnode(node->left);
        skrivVenstreBladnode(node->right);
    }
}