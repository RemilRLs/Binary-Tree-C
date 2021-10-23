#include "tree.h"

#include <stdio.h>
#include <stdlib.h>


/**
 * Function allowing to create a tree.
 * 
 * - p_value : Our tree label.
 */

node* creerNoeudArbre(int p_value) {

	node* cell = (node*)malloc(sizeof(node));

	if (!cell) {
		return NULL;
	}

	cell->m_data = p_value;

	cell->childLeft = NULL;
	cell->childRight = NULL;

	return cell;
}


/**
 * Function allowing to free a  tree (we use here recursion).
 *
 * - p_ppRoot : Our pointer to the root of the tree.
 */


void libererArbre(node** p_ppRoot) {

	// We check if the p_ppRoot exist.

	if (*p_ppRoot) {
		
		libererArbre(&(*p_ppRoot)->childLeft);
		libererArbre(&(*p_ppRoot)->childRight);

		free(*p_ppRoot);
		*p_ppRoot = NULL;
	}
}


/**
 * Function allowing to add a node in the left of the tree (we use recursion).
 *
 * - p_ppRoot : Our pointer to the root of the tree.
 * - p_value : Our tree label.
 */

void ajoutGauche(node* p_pRoot, int p_value) {

	if (p_pRoot->childLeft != NULL) { // We check if the node where we are has a left child.
		ajoutGauche(p_pRoot->childLeft, p_value);
	}
	else { // else.
		p_pRoot->childLeft = creerNoeudArbre(p_value);
	}
}

/**
 * Function allowing to add a node in the right of the tree (we use recursion).
 *
 * - p_ppRoot : Our pointer to the root of the tree.
 * - p_value : Our tree label.
 */

void ajoutDroite(node* p_pRoot, int p_value) {

	if (p_pRoot->childRight != NULL) { // We check if the node where we are has a right child.
		ajoutDroite(p_pRoot->childRight, p_value);
	}
	else { // else.
		p_pRoot->childRight = creerNoeudArbre(p_value);
		return;
	}
}

/**
 * Function than can calculate the height of the binary tree (depth of a leaf of a tree).
 *
 * - p_ppRoot : Our pointer to the root of the tree.
 */

int hauteur(node* p_pRoot) {

	if (p_pRoot == NULL) {
		return 0;
	}

	int hauteurRight = hauteur(p_pRoot->childRight);
	int hauteurLeft = hauteur(p_pRoot->childLeft);

	if (hauteurRight > hauteurLeft) {
		return(hauteurRight + 1);
	}
	else {
		return(hauteurLeft + 1);
	}
}

/**
 * Function than can calculate the size of the binary tree (number of nodes in the binary tree).
 *
 * - p_ppRoot : Our pointer to the root of the tree.
 */

int taille(node* p_pRoot) {

	if (p_pRoot == NULL) {
		return 0;
	}

	if (p_pRoot) {
		return (1 + taille(p_pRoot->childLeft) + taille(p_pRoot->childRight));
	}
}


/**
 * Function than can calculate the number of leaves of the binary tree (number of nodes that don't have childrens).
 *
 * - p_ppRoot : Our pointer to the root of the tree.
 */

int nbFeuilles(node* p_pRoot) {
	
	if (!p_pRoot) {

		return 0;
	}

	if (p_pRoot) {
		if (!p_pRoot->childLeft && !p_pRoot->childRight) {
			return 1;
		}
		else {
			return (nbFeuilles(p_pRoot->childLeft) + nbFeuilles(p_pRoot->childRight));
		}
	}
}

/**
 * Function than can delete a specified node in the binary tree.
 *
 * - p_ppRoot : Our pointer to the root of the tree.
 * - p_value : Our tree label.
 */



void supprSousArbre(node** p_ppRoot, int p_value) {

	if (!(*p_ppRoot)) {
		return;
	}

	if ((*p_ppRoot)->m_data == p_value) {
		libererArbre(p_ppRoot);
		return;
	}
	else {
		supprSousArbre(&(*p_ppRoot)->childLeft, p_value);
		supprSousArbre(&(*p_ppRoot)->childRight, p_value);
	}
	
}

// Browse Function (Binary tree).

void parcoursPrefixe(node* p_pRoot) {

	if (p_pRoot) {
		printf("%d ", p_pRoot->m_data);

		parcoursPrefixe(p_pRoot->childLeft);
		parcoursPrefixe(p_pRoot->childRight);
	}
}

void parcoursInfixe(node* p_pRoot) {

	if (p_pRoot) {
		if (p_pRoot->childLeft) {
			parcoursInfixe(p_pRoot->childLeft);
		}
		if (p_pRoot->childRight) {
			parcoursInfixe(p_pRoot->childRight);
		}

		printf("%d ", p_pRoot->m_data);
	}
}

void parcoursPostfixe(node* p_pRoot) {

	if (p_pRoot) {
		if (p_pRoot->childLeft) {
			parcoursPostfixe(p_pRoot->childLeft);
		}

		printf("%d ", p_pRoot->m_data);

		if (p_pRoot->childRight) {
			parcoursPostfixe(p_pRoot->childRight);
		}
	}
}